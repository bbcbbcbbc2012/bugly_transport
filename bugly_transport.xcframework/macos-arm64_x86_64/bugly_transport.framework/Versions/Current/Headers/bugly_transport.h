//
//  bugly_transport.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//

#ifndef BULGY_TRANSPORT_H
#define BULGY_TRANSPORT_H
#include "bugly_option.h"
#include "bugly_report_data_mode.h"

namespace bugly {

class BuglyTransportImpl;

/// @brief bugly 协议层外部接口(供ffi调用)
class BuglyTransport {
public:
    BuglyTransport();
    ~BuglyTransport();

    /// @brief 初始化
    /// @param _option 
    void initWithOption(const BuglyOption& _option);

    /// @brief 更新用户id
    /// @param _userId 
    void updateUserId(const std::string& _userId);

    /// @brief 更新网络状态
    /// @param _netType 
    void updateNetType(const std::string& _netType);

    /// @brief 异常上报接口
    /// @param _exception
    bool reportException(const BuglyReportExceptionInfo& _exception);

    /// @brief  Dau上报
    /// @param _dau
    bool reportDau(const BulgyReportDauAttributes& _dau);

    /// @brief  LaunchMetric上报
    /// @param  _launch
    bool reportLaunchMetric(const BuglyReportLaunchMetricInfo& _launch);

    /// @brief LooperMetric上报
    /// @param _looper
    bool reportLooperMetric(const BuglyReportLooperMetricInfo& _looper);

    /// @brief JankStack上报
    /// @param _jank 
    bool reportJankStack(const BuglyReportJankStackInfo& _jank);

private:
    bool prepareReport();

private:
    BuglyTransportImpl* impl;
    bool enableReport;
};

}
#endif //BULGY_TRANSPORT_H
