#include "Supplier.h"
#include "InputHelper.h"

int Supplier::getId() const {
    return m_id;
}
std::string Supplier::getName() const {
    return m_name;
}
std::string Supplier::getOrigin() const {
    return m_origin;
}
std::string Supplier::getContact() const {
    return m_contact;
}
int Supplier::getReliabilityRating() const {
    return m_reliability_rating;
}
void Supplier::setId(const int id) {
    m_id = id;
}
void Supplier::setName(const std::string& name) {
    m_name = name;
}
void Supplier::setOrigin(const std::string& origin) {
    m_origin = origin;
}
void Supplier::setContact(const std::string& contact) {
    m_contact = contact;
}
void Supplier::setReliabilityRating(const int rating) {
    m_reliability_rating = rating;
}
std::ostream& operator<< (std::ostream& out, const Supplier& supplier) {
    out << supplier.getId() << ": " << supplier.getName() << " | " << supplier.getOrigin() << " | " << supplier.getContact() << " | " << supplier.getReliabilityRating() << '\n';
    return out;
}
std::istream& operator>> (std::istream& in, Supplier& supplier) {
    supplier.setName(getString("Enter supplier name: "));
    supplier.setOrigin(getString("Enter supplier origin: "));
    supplier.setContact(getString("Enter supplier contact: "));
    supplier.setReliabilityRating(getInput<int>("Enter supplier reliability rating: "));
    return in;
}
