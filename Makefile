SDK_ZIPFILE="triPOS Mobile SDK 1.6.2.zip"

OUTPUT_FRAMEWORK_DIR=triPOSMobileSDK.framework

.PHONY: clean empty extract ship xcframework


clean:
	rm -rf $(OUTPUT_FRAMEWORK_DIR)

# NOTE: this file has spaces so we have to substitute them with an escape sequence. i.e. " " becomes "\ ". icky.
extract:
	scripts/extract_framework.sh zip/$(subst ' ', '\ ',$(SDK_ZIPFILE))

xcframework:
	scripts/create_xcframework.sh triPOSMobileSDK.framework .

empty: clean
	rm -rf triPOSMobileSDK.xcframework

ship: clean extract xcframework
	echo "Done"
