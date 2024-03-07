//
//  bugly_data_mode.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//

#ifndef BUGLY_DATA_MODE_H
#define BUGLY_DATA_MODE_H

#include <string>

namespace bugly {


#pragma mark - 设备信息
struct BuglyAndroidDeviceInfo
{
    std::string         cpuName;
    std::string         brand;
    std::string         romId;
    uint64_t            sdcardSize;
    bool                is64Bit;
};

struct BuglyIOSDeviceInfo
{
    std::string         hardwareModel;
};

struct BulgyDeviceInfo
{
    /// 平台，android/iOS
    std::string         platform;

    /// 设备 id
    std::string         deviceId;

    /// 设备名
    std::string         deviceName;

    /// 操作系统版本 例如："15.1.1"
    std::string         osVersion;

    /// 完整版本号 例如："Version 15.1.1 (Build 19B81)"
    std::string         fullOsVersion;

    /// CPU 架构
    std::string         cpuArch;

    std::string         archVer;

    /// 磁盘空间
    uint64_t            totalDiskSpace;

    /// 内存大小
    uint64_t            totalMemorySize;

    ///  qimei
    std::string         qimei;

    /// 是否为 root 机器
    bool                isRoot;

    /// 安卓设备信息
    BuglyAndroidDeviceInfo androidDeviceInfo;

    /// iOS设备信息
    BuglyIOSDeviceInfo      iOSDeviceInfo;
};



#pragma mark - 设备状态
struct BuglyAndroidDeviceStatus
{
    uint64_t            freeSDCard;
};

struct BuglyIOSDeviceStatus
{

};

struct BuglyDeviceStatus
{
    uint64_t            freeDiskSpace;
    uint64_t            freeMemory;
    std::string         networkType;

    BuglyAndroidDeviceStatus androidDeviceStatus;
};



#pragma mark - 应用信息
struct BuglyAppInfo
{
    /// rdm uuid, 与 bugly 中的保持一致
    std::string         uuid;

    /// app name
    std::string         appName;

    /// app Version
    std::string         appVersion;

    /// app channel
    std::string         appChannel;

    /// app version code， 该值只有 android 有
    uint64_t            appVersionCode;

    /// 是否为 appstore 版本，该值只有 iOS 有
    bool                isAppStoreVersion;

    /// 进程名
    std::string         processName;

    /// 是否首次安装
    bool                isFirstInstall;
};

#pragma mark -- buglyOption
enum BUGLY_SDK_TYPE : uint32_t {
    BUGLY_WOA = 0,
    BUGLY_PRO,

    BUGLY_SDK_TYPE_COUNT,
};
struct BuglyOption
{
    bool                            isDebug;
    bool                            isTestEnv;
    BUGLY_SDK_TYPE                  SDKType;
    std::string                     userId;
    std::string                     appId;
    std::string                     appKey;
    std::string                     bundleId;
    std::string                     appName;
    std::string                     appVersion;
    std::string                     appChannel;
    bool                            enableReport;

    std::string                     buglyVersion;
    std::string                     launchId;
    std::string                     clientIdentity;
};

}

#endif //BUGLY_DATA_MODE_H