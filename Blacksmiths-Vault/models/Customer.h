#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

class Customer {
private:
    int m_id;
    std::string m_name;
    std::string m_guild;
    int m_gold_balance;
public:
    int getId() const;
    std::string getName() const;
    std::string getGuild() const;
    int getGoldBalance() const;
    void setId(const int id);
    void setName(const std::string& name);
    void setGuild(const std::string& guild);
    void setGoldBanace(const int gold_balance);
};


#endif

