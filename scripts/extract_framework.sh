#!/bin/zsh

# extract_framework.sh
#   extract  framework from  zipfile  and build an xcframework
#
#   Finix Payments, Inc. 2020
#

# reset the context to a standard set of defaults
emulate -LR zsh

INPUT_ZIPFILE=$1

FRAMEWORK="triPOSMobileSDK"

FRAMEWORK_DIRNAME="$FRAMEWORK.framework"


# spit out error and then exit. if 2 args, 2nd is the error code
function error_exit () {
  echo "ERROR: $1"
  if (( $# == 2)); then
    exit $2
  else
    exit -1 
  fi
}


# first, check that the zipfile exists

if [[ -e "$INPUT_ZIPFILE" ]]; then
  echo "zipfile found at $INPUT_ZIPFILE"
  unzip -tq $INPUT_ZIPFILE
else
  error_exit "no file found at $INPUT_ZIPFILE"
fi

# check that output is not there
if [[ -e "$FRAMEWORK_DIRNAME"  ]]; then
  error_exit "framework output $FRAMEWORK_DIRNAME exists! bailing. (perhaps you need to remove it first?)"
fi


# See if there is a framework in there
# NOTE: this lists the archive and looks for a directory (path ending in '/' matching the framework 
ZIPFILE_FRAMEWORK=`unzip -Z -1 "$INPUT_ZIPFILE" |grep "/\$" |grep "$FRAMEWORK_DIRNAME/\$"`

if [[ -n "$ZIPFILE_FRAMEWORK" ]]; then
  echo "Framework found at $ZIPFILE_FRAMEWORK in $INPUT_ZIPFILE"
else
  error_exit "ERROR: No framework found in zipfile $INPUT_ZIPFILE"
fi
 
#extract framework to temp

UNZIP_OUTPUT_DIR="output_temp"
rm -rf $UNZIP_OUTPUT_DIR
mkdir $UNZIP_OUTPUT_DIR

# unzip. note that this preserves the deep directory structure, so we need to move it out
unzip "$INPUT_ZIPFILE" "$ZIPFILE_FRAMEWORK*" -d "$UNZIP_OUTPUT_DIR"

#since it is in the wrong place, move it to where we expect

mv $UNZIP_OUTPUT_DIR/$ZIPFILE_FRAMEWORK .



if [[ `basename $ZIPFILE_FRAMEWORK` == $FRAMEWORK_DIRNAME ]]; then
  echo "good. zipfile output dir basename matches framework name"
else
  error_exit "ERROR: zipfile extracted directory [$ZIPFILE_FRAMEWORK ]didn't match expected $FRAMEWORK_DIRNAME"
fi


# now clean up the output
rm -rf UNZIP_OUTPUT_DIR
