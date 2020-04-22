# triPOSMobileSDK-iOS repository
This repository holds the triPOSMobileSDK framework for iOS.
The original is here:

  - [link](https://developer.vantiv.com/docs/DOC-1915?forceNoRedirect=true)
  - [zipfile](https://developer.vantiv.com/servlet/JiveServlet/download/1915-35-6683/triPOS+Mobile+SDK+1.6.2.zip)
  
This version has been modified to work with the Finix POS SDK for iOS. Details follow.

## Changes to the SDK
The SDK that ships from WorldPay has several limitations due to the way its packaged.
The SDK is a Universal framework. Aka a "fat" library. That means it contains compiled binary code for multiple target architectures.
This is to facilitate using one framework for both simulator and device.

As a consequence, when submitting to the app store the target app will be rejected unless it contains only the shipping architecture (arm7 and arm64 for iOS devices). To address that the SDK includes a `Run Script` phase for building the app that calls `lipo` to remove simulator slices (x86 and x86-64).


## Solution
this will create an xcframework out of the shipping binaries


## tl;dr what to do with a new version

- put the zipfile into `zip`
- update `Makefile` to reference the file:
	
	```
	SDK_ZIPFILE="triPOS Mobile SDK 1.6.2.zip"
	```

- build the xcframework with:
	
	```
	make ship
	```

Voila! If successful, an XCFramework will exist in the current directory named `triPOSMobileSDK.xcframework`

