#include "Customer.h"

int Customer::getId() const {
    return m_id;
}
std::string Customer::getName() const {
    return m_name;
}
std::string Customer::getGuild() const {
    return m_guild;
}
int Customer::getGoldBalance() const {
    return m_gold_balance;
}
void Customer::setId(const int id) {
    m_id = id;
}
void Customer::setName(const std::string& name) {
    m_name = name;
}
void Customer::setGuild(const std::string& guild) {
    m_guild = guild;
}
void Customer::setGoldBanace(const int gold_balance) {
    m_gold_balance = gold_balance;
}