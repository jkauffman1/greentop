#ifndef CANCELAPPLICATIONSUBSCRIPTIONRESPONSE_H
#define CANCELAPPLICATIONSUBSCRIPTIONRESPONSE_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/enum/Status.h"

namespace greentop {

class CancelApplicationSubscriptionResponse : public JsonResponse {
    public:
        CancelApplicationSubscriptionResponse();

        CancelApplicationSubscriptionResponse(const Status& status);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Status& getStatus() const;
        void setStatus(const Status& status);


    private:
        Status status;
};

}

#endif // CANCELAPPLICATIONSUBSCRIPTIONRESPONSE_H


