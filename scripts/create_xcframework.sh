#!/bin/zsh

# create_xcframework.sh
#   from an extracted framework build an .xcframework after lipoins
#
#   Finix Payments, Inc. 2020
#

# reset the context to a standard set of defaults
emulate -LR zsh

function usage () {
  echo "Create an .xcframework from a given framework"
  echo "Usage: $1 Framework.framework output_dir"
  echo "Example: $1 triPOSMobileSDK.framework staging"
}


if [[ $#argv -ne 2 ]]; then
  usage $0
  exit -1
fi


INPUT_FRAMEWORK=$argv[1]

OUTPUT_DIR=$argv[2]  # place the output this

echo "input framework $INPUT_FRAMEWORK"
echo "output dir $OUTPUT_DIR"


SIMULATOR_DIR="iphonesimulator"
SIMULATOR_ARCHS=(i386 x86_64) #NOTE: zsh arrays created with the parens but you can't pass through to functions!

DEVICE_DIR="iphoneos"
DEVICE_ARCHS=(arm64 armv7) #TODO: make sure these are the only ones


# validate commmand-line


# spit out error and then exit. if 2 args, 2nd is the error code
function error_exit () {
  echo "ERROR: $1"
  exit -1 
}


LIPO="lipo"
function check_lipo() {
  echo -n "checking for lipo..."
  if ! type "$LIPO" > /dev/null; then
    error_exit "$LIPO not found in path. Please install Xcode"
  fi
  echo "found"
}

XCODEBUILD="xcodebuild"
function check_xcodebuild() {
  echo -n "checking for xcodebuild..."
  if ! type "$XCODEBUILD" > /dev/null; then
    error_exit "$XCODEBUILD not found in path. Please install Xcode"
  fi
  echo "found"
}


#check for input framework
if [[ -e $INPUT_FRAMEWORK ]]; then
  echo "Framework $INPUT_FRAMEWORK exists."
else
  error_exit "no framework found for $INPUT_FRAMEWORK. did you run extract_framework.sh yet?"
fi



#preflight checks make sure tools exist
check_lipo #check that lipo exists
check_xcodebuild #and for xcodebuild

XCFRAMEWORK_NAME=`basename $INPUT_FRAMEWORK`
XCFRAMEWORK_NAME=${XCFRAMEWORK_NAME:s/.framework/.xcframework/}

OUTPUT_XCFRAMEWORK="$OUTPUT_DIR/$XCFRAMEWORK_NAME"

# make sure we don't already have an xcframework 
echo -n "checking target if $OUTPUT_XCFRAMEWORK already exists..."
if [[ -e $OUTPUT_XCFRAMEWORK ]]; then
  error_exit "it exists. Aborting"
  exit -32
else:
  echo "not present. continuing"
fi


TEMP_DIR="create_temp" # a temp place to have 

if [[ -d $TEMP_DIR ]]; then
  echo "$TEMP_DIR exists. removing it."
  rm -rf $TEMP_DIR
fi

mkdir $TEMP_DIR


function extract_framework_and_lipo() {
  # NOTE: this is a little yucky because of how zsh doesn't deal with arrays as function parameters.
  # instead we'll pass in archs as the remaining params.
  target_dir=$1
  shift

  if [[ -d $target_dir ]]; then 
    rm -rf $target_dir
  fi
  mkdir -p $target_dir

  # copy to target and then lipo it
  cp -r $INPUT_FRAMEWORK $target_dir


  BINARY_NAME=`basename $INPUT_FRAMEWORK`
  BINARY_NAME=${BINARY_NAME:s/.framework//}

  echo "binary = $BINARY_NAME"

  #TODO: check that slices exist
  TARGET_BINARY="$target_dir/$INPUT_FRAMEWORK/$BINARY_NAME"

  cmd=($TARGET_BINARY)

  #now strip
  for arch in $@;
  do
    echo "arch: $arch"
    cmd+=('-extract' $arch)
  done

  cmd+=("-output" $TARGET_BINARY.temp) #note the .temp!

  #TODO: check archs exist in there

  echo "running: $LIPO $cmd"
  $LIPO $cmd

  echo "moving lipo'd into place"

  mv $TARGET_BINARY.temp $TARGET_BINARY
  lipo -info $TARGET_BINARY
}


#extract for simulator
extract_framework_and_lipo "$TEMP_DIR/$SIMULATOR_DIR" $SIMULATOR_ARCHS

#extract for device
extract_framework_and_lipo "$TEMP_DIR/$DEVICE_DIR" $DEVICE_ARCHS



echo "Generating the XCFramework $XCFRAMEWORK_NAME in $OUTPUT_DIR"

framework_cmd=(-create-xcframework -framework $TEMP_DIR/$SIMULATOR_DIR/$INPUT_FRAMEWORK -framework $TEMP_DIR/$DEVICE_DIR/$INPUT_FRAMEWORK -output $OUTPUT_XCFRAMEWORK)

echo "command = $XCODEBUILD $framework_cmd"
$XCODEBUILD $framework_cmd
# final command to extract framework

#xcodebuild -create-xcframework -framework iphoneos/triPOSMobileSDK.framework -framework iphonesimulator/triPOSMobileSDK.framework -output triPOSMobileSDK.xcframework

#now, clean up the temp directories
