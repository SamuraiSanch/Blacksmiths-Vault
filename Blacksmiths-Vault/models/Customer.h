#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

class Customer {
private:
    int m_id;
    std::string m_name;
    std::string m_guild;
    double m_gold_balance;
public:
    int getId() const;
    std::string getName() const;
    std::string getGuild() const;
    double getGoldBalance() const;
    void setId(const int id);
    void setName(const std::string& name);
    void setGuild(const std::string& guild);
    double setGoldBalance(const double gold_balance);
};


#endif

