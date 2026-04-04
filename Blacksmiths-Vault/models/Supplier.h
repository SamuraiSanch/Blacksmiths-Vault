#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <iostream>

class Supplier {
private:
    int m_id;
    std::string m_name;
    std::string m_origin;
    std::string m_contact;
    int m_reliability_rating;
public:
    int getId() const;
    std::string getName() const;
    std::string getOrigin() const;
    std::string getContact() const;
    int getReliabilityRating() const;
    void setId(const int id);
    void setName(const std::string& name);
    void setOrigin(const std::string& origin);
    void setContact(const std::string& contact);
    void setReliabilityRating(const int rating);
};

std::ostream& operator<< (std::ostream& out, const Supplier& supplier);
std::istream& operator>> (std::istream& in, Supplier& supplier);

#endif
