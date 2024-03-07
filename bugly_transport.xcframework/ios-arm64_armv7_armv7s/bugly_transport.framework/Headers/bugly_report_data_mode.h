//
//  bugly_report_data_mode.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//


/// 用来定义各个上报所需的数据

#ifndef BUGLY_REPORT_DATA_MODE_H
#define BUGLY_REPORT_DATA_MODE_H

#include <vector>
#include <string>
#include <unordered_map>

namespace bugly {

#pragma mark -- DAU
using SdkInfoType = std::vector<std::unordered_map<std::string, std::string>>;
struct BulgyReportDauAttributes
{
    std::vector<std::string> features_enabled;
    bool                     first_report;
    SdkInfoType              sdk_info;
    std::string              clientIdentify;
};

#pragma mark -- Exception
struct BuglyReportExceptionInfo
{
    std::string         name;
    std::string         message;
    std::string         addr;
    uint64_t            app_start_time;
    std::string         stack;
    std::string         thread;
    std::string         exceptionType;  // Dart:"109"
    uint64_t            sessionTimestamp;

    bool                isRunInFront;
    std::string         clientIdentify;
};

#pragma mark -- LaunchMetric
struct BuglyReportLaunchMetricInfo
{
 
};

#pragma mark -- LooperMetric
struct BuglyReportLooperMetricInfo 
{

};

#pragma mark -- JankStack
struct BuglyReportJankStackInfo
{

};


} //namespace

#endif //BUGLY_REPORT_DATA_MODE_H