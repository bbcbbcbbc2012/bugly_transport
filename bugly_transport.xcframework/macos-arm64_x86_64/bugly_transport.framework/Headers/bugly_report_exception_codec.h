//
//  bugly_report_exception_codec.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//

#ifndef BUGLY_REPORT_EXCEPTION_CODEC_H
#define BUGLY_REPORT_EXCEPTION_CODEC_H

#include "bugly_report_common_codec.h"

namespace bugly {


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

class BulgyReportErrorCodec : public BuglyReportCommonCodec {
public:
    BulgyReportErrorCodec(const BuglyReportExceptionInfo& _exception) : exception(_exception) {};

#pragma mark - override
    const std::string getBaseType() const override;
    const std::string getSubType() const override;
    const std::string encode(BulgyCommonMode& commonData) override;
    RespType decode(const std::string response) override;

public:
    Json::Value makeExpInfo(BulgyCommonMode& commonData);
    Json::Value makeMemoryInfo(BulgyCommonMode& commonData);
    Json::Value makeStorageInfo(BulgyCommonMode& commonData);
    Json::Value makeSDInfo(BulgyCommonMode& commonData);
    Json::Value makeAttributes(BulgyCommonMode& commonData);
    Json::Value makeStacks(BulgyCommonMode& commonData);
    Json::Value makeAttributedStack(BulgyCommonMode& commonData);
    Json::Value makeBody(BulgyCommonMode& commonData);

private:
    BuglyReportExceptionInfo exception;
};

}

#endif //BUGLY_REPORT_EXCEPTION_CODEC_H