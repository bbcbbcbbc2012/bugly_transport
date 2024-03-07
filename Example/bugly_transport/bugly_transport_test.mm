//
//  bugly_transport_test.cpp
//  bugly_transport_Example
//
//  Created by hod on 2024/3/7.
//  Copyright © 2024 hodxiang. All rights reserved.
//

#include "bugly_transport_test.h"
#include <iostream>
#include <string>
#include <bugly_transport/bugly_transport.h>
#include <Foundation/Foundation.h>


using namespace bugly;

std::string darwinMakeUUID() {
    char uuid[40];
    memset(uuid, 0, sizeof(uuid));

    CFUUIDRef uuid_object = CFUUIDCreate(kCFAllocatorDefault);
    CFStringRef uuid_cfstring = CFUUIDCreateString(kCFAllocatorDefault, uuid_object);
    CFStringGetCString(uuid_cfstring, uuid, sizeof(uuid), kCFStringEncodingUTF8);
    CFRelease(uuid_object);
    CFRelease(uuid_cfstring);
    uuid[39] = 0;
    return uuid;
}

BuglyAppInfo getAppInfo(const char* appName)
{
    BuglyAppInfo info;
    info.uuid = "123455";        // build_number
    info.appName = appName;        // not used in protocal
    info.appVersion = "1.0.0.1";    // app_version
    info.appChannel = "unknown";    // exception Attributes.app_channel
    info.appVersionCode = 1;        // not used
    info.isAppStoreVersion = false;    // exception Attributes.is_app_store
    info.processName = info.appName; // exception Attributes.process_name
    info.isFirstInstall = true; // exception Attributes.is_first_install

    return info;
}

BulgyDeviceInfo getDeviceInfo()
{
    BulgyDeviceInfo info;
    info.platform = "Android";    //Resource.hardware_os
    info.deviceId = "a9d55b9af8c04cef95550e7016ea59df";        //Resource.unique_id
    info.deviceName = "DVC-AN20";    //Resource.model
    info.osVersion = "10,level 29";    //Resource.os_version
    info.fullOsVersion = "unknown";    //Resource.full_os_version
    info.cpuArch = "arm64";        //exception Resource.cpu_type
    info.archVer = "arm64";
    info.totalDiskSpace = 127870980096; // exception Attributes.storage.total
    info.totalMemorySize = 3840131072; // exception Attributes.memory.system_total
    info.qimei = "a9d55b9af8c04cef95550e7016ea59df"; // not used
    info.isRoot = false;    //exception Attribute.is_root

    info.androidDeviceInfo.cpuName = "not used"; // not used
    info.androidDeviceInfo.brand = "HUAWEI";    //Resource.brand
    info.androidDeviceInfo.romId = "Android12";    //exception Resource.rom
    info.androidDeviceInfo.sdcardSize = 127870980096; //exception Attribute.sd.total
    info.androidDeviceInfo.is64Bit = true; // not used in protocal

    info.iOSDeviceInfo.hardwareModel = "iPhone12,2"; //not used in protocal
    return info;
}

BuglyDeviceStatus getDeviceStatus()
{
    BuglyDeviceStatus status;
    status.freeDiskSpace = 3024154624;    // exception Attributes.storage.free
    status.freeMemory = 68878336;    // exception Attributes.memory.system_free
    status.networkType = "wifi";    // Resource.network_type

    status.androidDeviceStatus.freeSDCard = status.freeDiskSpace; // exception Attribute.sd.free
    return status;
}

BuglyOption getBuglyOption(const char* appName)
{
    BuglyOption option;
    option.isDebug = false;
    option.isTestEnv = false;
    option.SDKType = BUGLY_SDK_TYPE::BUGLY_WOA;
    option.userId = "bugly_transporter_tester";
    option.appId = "7f5e0b427f";
    option.appKey = "a79632e1-e365-4578-8829-27d55c54b93b";
    option.bundleId = "com.tencent.bulgy_transport_tester.hod";
    option.appName = appName;
    option.appVersion = "1.0";
    option.appChannel = "";
    option.enableReport = true;
    option.buglyVersion = "bugly_transport@0.0.1";
    option.launchId = darwinMakeUUID();
    option.clientIdentity = darwinMakeUUID();
    return option;
}

BuglyTransport::CppDataInferfaceType getExceptionInfo()
{
    BuglyTransport::CppDataInferfaceType exception;
    exception["name"] = "_CastError(Serious)";
    exception["message"] = "type 'double' is not a subtype of type 'int' in type cast";
    exception["addr"] = "#0      _MyHomePageState._incrementCounter.<anonymous closure> (package:flutter_application_1/main.dart:81:33)";
    exception["app_start_time"] = "1705395949187";
    exception["stack"] = "#0      _MyHomePageState._incrementCounter.<anonymous closure> (package:flutter_application_1/main.dart:81:33)\n#1      State.setState (package:flutter/src/widgets/framework.dart:1088:30)\n#2      _MyHomePageState._incrementCounter (package:flutter_application_1/main.dart:73:5)\n#3      _InkResponseState._handleTap (package:flutter/src/material/ink_well.dart:989:21)\n#4      GestureRecognizer.invokeCallback (package:flutter/src/gestures/recognizer.dart:193:24)\n#5      TapGestureRecognizer.handleTapUp (package:flutter/src/gestures/tap.dart:608:11)\n#6      BaseTapGestureRecognizer._checkUp (package:flutter/src/gestures/tap.dart:296:5)\n#7      BaseTapGestureRecognizer.acceptGesture (package:flutter/src/gestures/tap.dart:267:7)\n#8      GestureArenaManager.sweep (package:flutter/src/gestures/arena.dart:157:27)\n#9      GestureBinding.handleEvent (package:flutter/src/gestures/binding.dart:444:20)\n#10     GestureBinding.dispatchEvent (package:flutter/src/gestures/binding.dart:420:22)\n#11     RendererBinding.dispatchEvent (package:flutter/src/rendering/binding.dart:278:11)\n#12     GestureBinding._handlePointerEventImmediately (package:flutter/src/gestures/binding.dart:374:7)\n#13     GestureBinding.handlePointerEvent (package:flutter/src/gestures/binding.dart:338:5)\n#14     GestureBinding._flushPointerEventQueue (package:flutter/src/gestures/binding.dart:296:7)\n#15     GestureBinding._handlePointerDataPacket (package:flutter/src/gestures/binding.dart:279:7)\n#16     _rootRunUnary (dart:async/zone.dart:1444:13)\n#17     _CustomZone.runUnary (dart:async/zone.dart:1335:19)\n#18     _CustomZone.runUnaryGuarded (dart:async/zone.dart:1244:7)\n#19     _invoke1 (dart:ui/hooks.dart:185:10)\n#20     PlatformDispatcher._dispatchPointerDataPacket (dart:ui/platform_dispatcher.dart:293:7)\n#21     _dispatchPointerDataPacket (dart:ui/hooks.dart:98:31)\n";
    exception["thread"] = "main";
    exception["exceptionType"] = "109";
    exception["sessionTimestamp"] = "1705395949187";

    exception["isRunInFront"] = "1";
    exception["clientIdentify"] = darwinMakeUUID();
    return exception;
}

void test_bugly_transport()
{
    std::cout << "hello bugly_transport" << std::endl;
    bugly::BuglyTransport transport;

    transport.appInfo = getAppInfo("test");
    transport.deviceInfo = getDeviceInfo();
    transport.updateDeviceStatus(getDeviceStatus());
    transport.option = getBuglyOption("test");
    transport.initImpl();

    BuglyTransport::CppDataInferfaceType dau;
    dau["first_report"] = "1";
    dau["clientIdentify"] = darwinMakeUUID();
    transport.reportDau(dau);

    BuglyTransport::CppDataInferfaceType exception = getExceptionInfo();
    transport.reportException(exception);
}
