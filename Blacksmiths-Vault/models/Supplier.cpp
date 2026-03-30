#include "Supplier.h"

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