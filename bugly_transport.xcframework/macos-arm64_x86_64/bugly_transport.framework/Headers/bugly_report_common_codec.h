//
//  bugly_report_common_codec.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//

#ifndef BUGLY_REPORT_COMMON_CODEC_H
#define BUGLY_REPORT_COMMON_CODEC_H
#include <string>
#include <unordered_map>
#include <json/json.h>

namespace bugly {

struct BulgyCommonMode;

class BuglyReportCommonCodec {
public:
    using RespType = std::unordered_map<std::string, std::string>;

    virtual ~BuglyReportCommonCodec();

    virtual const std::string getBaseType() const;
    virtual const std::string getSubType() const;

    virtual const std::string encode(BulgyCommonMode& commonData);
    virtual RespType decode(const std::string response);

    std::string jsonToString(const Json::Value& jsonObj);
    std::string stringToZip(const std::string& str);
    std::string jsonToZip(const Json::Value& jsonObj);

    virtual void updateVariableInfo(BulgyCommonMode& commonData);
    virtual Json::Value makeParams(BulgyCommonMode& commonData);
    virtual Json::Value makeResource(BulgyCommonMode& commonData);
    uint64_t getCurrentTime() const;
    std::string makeUUID() const;
};

}
#endif //BUGLY_REPORT_COMMON_CODEC_H