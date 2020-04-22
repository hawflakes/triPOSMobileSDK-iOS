SDK_ZIPFILE="triPOS Mobile SDK 1.6.2.zip"

OUTPUT_FRAMEWORK_DIR=triPOSMobileSDK.framework

.PHONY: clean extract ship 


clean:
	rm -rf $(OUTPUT_FRAMEWORK_DIR)

# NOTE: this file has spaces so we have to substitute them with an escape sequence. i.e. " " becomes "\ ". icky.
extract:
	scripts/convert_framework.sh zip/$(subst ' ', '\ ',$(SDK_ZIPFILE))


ship: clean extract
	echo "Done"
