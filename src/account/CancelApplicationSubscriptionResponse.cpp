#include "greentop/account/CancelApplicationSubscriptionResponse.h"

namespace greentop {
CancelApplicationSubscriptionResponse::CancelApplicationSubscriptionResponse() {
}

CancelApplicationSubscriptionResponse::CancelApplicationSubscriptionResponse(const Status& status) :
    status(status) {
}

void CancelApplicationSubscriptionResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("status")) {
            status = json["status"].asString();
        }
    }
}

Json::Value CancelApplicationSubscriptionResponse::toJson() const {
    Json::Value json;
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    return json;
}

bool CancelApplicationSubscriptionResponse::isValid() const {
    return status.isValid();
}

const Status& CancelApplicationSubscriptionResponse::getStatus() const {
    return status;
}
void CancelApplicationSubscriptionResponse::setStatus(const Status& status) {
    this->status = status;
}


}


