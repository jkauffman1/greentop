/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef TIMERANGE_H
#define TIMERANGE_H

#include <ctime>
#include <json/json.h>

#include "greentop/JsonMember.h"

namespace greentop {

class TimeRange : public JsonMember {
    public:

        TimeRange(const std::tm& from = std::tm(),
            const std::tm& to = std::tm());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::tm& getFrom() const;
        void setFrom(const std::tm& from);

        const std::tm& getTo() const;
        void setTo(const std::tm& to);


    private:
        std::tm from;
        std::tm to;
};

}

#endif // TIMERANGE_H


