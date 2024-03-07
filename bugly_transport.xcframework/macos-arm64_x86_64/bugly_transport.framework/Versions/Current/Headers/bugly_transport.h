//
//  bugly_transport.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//

#ifndef BULGY_TRANSPORT_H
#define BULGY_TRANSPORT_H
#include <unordered_map>
#include <string>
#include <memory>
#include "bugly_data_mode.h"

namespace bugly {

class BuglyTransportImpl;

/// @brief bugly 协议层外部接口(供ffi调用)
class BuglyTransport {
public:
    BuglyTransport();

    using CppDataInferfaceType = std::unordered_map<std::string, std::string>;
    /// @brief 异常上报接口
    /// @param name, message, addr, app_start_time:int, call_stack, thread_name
    bool reportException(CppDataInferfaceType& exception);

    /// @brief  Dau上报
    /// @param features_enabled, first_report, sdk_info
    bool reportDau(CppDataInferfaceType& dau);

    /// @brief  LaunchMetric上报
    /// @param  process_name, launch_type, launch_cost:int, start_time:int, tags:list<string>, spans
    bool reportLaunchMetric(const CppDataInferfaceType launch);

    /// @brief LooperMetric上报
    /// @param looper
    /// @return
    bool reportLooperMetric(const CppDataInferfaceType looper);
    bool reportJankStack(const CppDataInferfaceType jank);

    /// @brief 设置appInfo
    /// @param appId, appKey, bundleId, userId
    void setAppInfo(CppDataInferfaceType& _appInfo);

    /// @brief 设置option
    /// @param option
    void setBuglyOption(CppDataInferfaceType& _option);

    /// @brief 更新userId
    /// @param userId
    void updateUserId(const std::string& _userId);

    void updateDeviceStatus(CppDataInferfaceType& _deviceStatus);
    void updateDeviceStatus(const BuglyDeviceStatus& _deviceStatus);

    void initImpl();

    template<typename T>
    void getValueWithMap(T &out, CppDataInferfaceType& _data, const std::string& key);
    template<>
    void getValueWithMap(bool &out, CppDataInferfaceType& _data, const std::string& key);
    template<>
    void getValueWithMap(uint64_t &out, CppDataInferfaceType& _data, const std::string& key);
    template<>
    void getValueWithMap(int32_t &out, CppDataInferfaceType& _data, const std::string& key);
public:

    BulgyDeviceInfo deviceInfo;
    BuglyDeviceStatus deviceStatus;
    BuglyAppInfo appInfo;
    BuglyOption option;

    BuglyTransportImpl* impl;
};

}
#endif //BULGY_TRANSPORT_H
