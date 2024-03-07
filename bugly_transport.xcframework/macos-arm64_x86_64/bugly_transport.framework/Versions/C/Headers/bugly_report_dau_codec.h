//
//  bugly_report_dau_codec.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//

#ifndef BUGLY_REPORT_DAU_CODEC_H
#define BUGLY_REPORT_DAU_CODEC_H

#include "bugly_report_common_codec.h"
#include <vector>
#include <string>
#include <unordered_map>

namespace bugly {

using SdkInfoType = std::vector<std::unordered_map<std::string, std::string>>;

struct BulgyReportDauAttributes
{
    std::vector<std::string> features_enabled;
    bool                     first_report;
    SdkInfoType              sdk_info;
    std::string              clientIdentify;
};

class BuglyReportDauCodec : public BuglyReportCommonCodec
{
public:
    BuglyReportDauCodec(const BulgyReportDauAttributes& _dauAttr);
#pragma mark - override
    const std::string getBaseType() const override;
    const std::string getSubType() const override;
    const std::string encode(BulgyCommonMode& commonData) override;
    RespType decode(const std::string response) override;

public:
    Json::Value makeAttributes();
    
    Json::Value makeDAUTestJson();

private:
    BulgyReportDauAttributes dauAttr;
};

}
#endif //BUGLY_REPORT_DAU_CODEC_H
