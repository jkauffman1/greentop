/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/MarketDescription.h"

namespace greentop {
MarketDescription::MarketDescription()  : marketBaseRate(-1){
}

MarketDescription::MarketDescription(const BoolJsonMember& persistenceEnabled,
    const BoolJsonMember& bspMarket,
    const std::tm& marketTime,
    const std::tm& suspendTime,
    const std::tm& settleTime,
    const MarketBettingType& bettingType,
    const BoolJsonMember& turnInPlayEnabled,
    const std::string& marketType,
    const std::string& regulator,
    const double marketBaseRate,
    const BoolJsonMember& discountAllowed,
    const std::string& wallet,
    const std::string& rules,
    const BoolJsonMember& rulesHasDate,
    const std::string& clarifications) :
    persistenceEnabled(persistenceEnabled),
    bspMarket(bspMarket),
    marketTime(marketTime),
    suspendTime(suspendTime),
    settleTime(settleTime),
    bettingType(bettingType),
    turnInPlayEnabled(turnInPlayEnabled),
    marketType(marketType),
    regulator(regulator),
    marketBaseRate(marketBaseRate),
    discountAllowed(discountAllowed),
    wallet(wallet),
    rules(rules),
    rulesHasDate(rulesHasDate),
    clarifications(clarifications) {
}

void MarketDescription::fromJson(const Json::Value& json) {
    if (json.isMember("persistenceEnabled")) {
        persistenceEnabled.fromJson(json["persistenceEnabled"]);
    }
    if (json.isMember("bspMarket")) {
        bspMarket.fromJson(json["bspMarket"]);
    }
    if (json.isMember("marketTime")) {
        strptime(json["marketTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &marketTime);
    }
    if (json.isMember("suspendTime")) {
        strptime(json["suspendTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &suspendTime);
    }
    if (json.isMember("settleTime")) {
        strptime(json["settleTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &settleTime);
    }
    if (json.isMember("bettingType")) {
        bettingType = json["bettingType"].asString();
    }
    if (json.isMember("turnInPlayEnabled")) {
        turnInPlayEnabled.fromJson(json["turnInPlayEnabled"]);
    }
    if (json.isMember("marketType")) {
        marketType = json["marketType"].asString();
    }
    if (json.isMember("regulator")) {
        regulator = json["regulator"].asString();
    }
    if (json.isMember("marketBaseRate")) {
        marketBaseRate = json["marketBaseRate"].asDouble();
    }
    if (json.isMember("discountAllowed")) {
        discountAllowed.fromJson(json["discountAllowed"]);
    }
    if (json.isMember("wallet")) {
        wallet = json["wallet"].asString();
    }
    if (json.isMember("rules")) {
        rules = json["rules"].asString();
    }
    if (json.isMember("rulesHasDate")) {
        rulesHasDate.fromJson(json["rulesHasDate"]);
    }
    if (json.isMember("clarifications")) {
        clarifications = json["clarifications"].asString();
    }
}

Json::Value MarketDescription::toJson() const {
    Json::Value json(Json::objectValue);
    if (persistenceEnabled.isValid()) {
        json["persistenceEnabled"] = persistenceEnabled.toJson();
    }
    if (bspMarket.isValid()) {
        json["bspMarket"] = bspMarket.toJson();
    }
    if (marketTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &marketTime);
        json["marketTime"] = std::string(buffer);
    }
    if (suspendTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &suspendTime);
        json["suspendTime"] = std::string(buffer);
    }
    if (settleTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &settleTime);
        json["settleTime"] = std::string(buffer);
    }
    if (bettingType.isValid()) {
        json["bettingType"] = bettingType.getValue();
    }
    if (turnInPlayEnabled.isValid()) {
        json["turnInPlayEnabled"] = turnInPlayEnabled.toJson();
    }
    if (marketType != "") {
        json["marketType"] = marketType;
    }
    if (regulator != "") {
        json["regulator"] = regulator;
    }
    if (marketBaseRate >= 0) {
        json["marketBaseRate"] = marketBaseRate;
    }
    if (discountAllowed.isValid()) {
        json["discountAllowed"] = discountAllowed.toJson();
    }
    if (wallet != "") {
        json["wallet"] = wallet;
    }
    if (rules != "") {
        json["rules"] = rules;
    }
    if (rulesHasDate.isValid()) {
        json["rulesHasDate"] = rulesHasDate.toJson();
    }
    if (clarifications != "") {
        json["clarifications"] = clarifications;
    }
    return json;
}

bool MarketDescription::isValid() const {
    return persistenceEnabled.isValid() && bspMarket.isValid() && marketTime.tm_year > 0 && suspendTime.tm_year > 0 && settleTime.tm_year > 0 && bettingType.isValid() && turnInPlayEnabled.isValid() && marketType != "" && regulator != "" && marketBaseRate >= 0 && discountAllowed.isValid();
}

const BoolJsonMember& MarketDescription::getPersistenceEnabled() const {
    return persistenceEnabled;
}
void MarketDescription::setPersistenceEnabled(const BoolJsonMember& persistenceEnabled) {
    this->persistenceEnabled = persistenceEnabled;
}

const BoolJsonMember& MarketDescription::getBspMarket() const {
    return bspMarket;
}
void MarketDescription::setBspMarket(const BoolJsonMember& bspMarket) {
    this->bspMarket = bspMarket;
}

const std::tm& MarketDescription::getMarketTime() const {
    return marketTime;
}
void MarketDescription::setMarketTime(const std::tm& marketTime) {
    this->marketTime = marketTime;
}

const std::tm& MarketDescription::getSuspendTime() const {
    return suspendTime;
}
void MarketDescription::setSuspendTime(const std::tm& suspendTime) {
    this->suspendTime = suspendTime;
}

const std::tm& MarketDescription::getSettleTime() const {
    return settleTime;
}
void MarketDescription::setSettleTime(const std::tm& settleTime) {
    this->settleTime = settleTime;
}

const MarketBettingType& MarketDescription::getBettingType() const {
    return bettingType;
}
void MarketDescription::setBettingType(const MarketBettingType& bettingType) {
    this->bettingType = bettingType;
}

const BoolJsonMember& MarketDescription::getTurnInPlayEnabled() const {
    return turnInPlayEnabled;
}
void MarketDescription::setTurnInPlayEnabled(const BoolJsonMember& turnInPlayEnabled) {
    this->turnInPlayEnabled = turnInPlayEnabled;
}

const std::string& MarketDescription::getMarketType() const {
    return marketType;
}
void MarketDescription::setMarketType(const std::string& marketType) {
    this->marketType = marketType;
}

const std::string& MarketDescription::getRegulator() const {
    return regulator;
}
void MarketDescription::setRegulator(const std::string& regulator) {
    this->regulator = regulator;
}

const double MarketDescription::getMarketBaseRate() const {
    return marketBaseRate;
}
void MarketDescription::setMarketBaseRate(const double marketBaseRate) {
    this->marketBaseRate = marketBaseRate;
}

const BoolJsonMember& MarketDescription::getDiscountAllowed() const {
    return discountAllowed;
}
void MarketDescription::setDiscountAllowed(const BoolJsonMember& discountAllowed) {
    this->discountAllowed = discountAllowed;
}

const std::string& MarketDescription::getWallet() const {
    return wallet;
}
void MarketDescription::setWallet(const std::string& wallet) {
    this->wallet = wallet;
}

const std::string& MarketDescription::getRules() const {
    return rules;
}
void MarketDescription::setRules(const std::string& rules) {
    this->rules = rules;
}

const BoolJsonMember& MarketDescription::getRulesHasDate() const {
    return rulesHasDate;
}
void MarketDescription::setRulesHasDate(const BoolJsonMember& rulesHasDate) {
    this->rulesHasDate = rulesHasDate;
}

const std::string& MarketDescription::getClarifications() const {
    return clarifications;
}
void MarketDescription::setClarifications(const std::string& clarifications) {
    this->clarifications = clarifications;
}


}



