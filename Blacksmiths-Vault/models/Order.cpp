#include "Order.h"

int Order::getId() const {
    return m_id;
}
int Order::getCustomerId() const {
    return m_customer_id;
}
int Order::getItemId() const {
    return m_item_id;
}
int Order::getQuantity() const {
    return m_quantity;
}
double Order::getTotalPrice() const {
    return m_total_price;
}
std::string Order::getStatus() const {
    return m_status;
}
std::string Order::getOrderDate() const {
    return m_order_date;
}
void Order::setId(const int id) {
    m_id = id;
}
void Order::setCustomerId(const int customerId) {
    m_customer_id = customerId;
}
void Order::setItemId(const int itemId) {
    m_item_id = itemId;
}
void Order::setQuantity(const int quantity) {
    m_quantity = quantity;
}
void Order::setTotalPrice(const double totalPrice) {
    m_total_price = totalPrice;
}
void Order::setStatus(const std::string& status) {
    m_status = status;
}
void Order::setOrderDate(const std::string& orderDate) {
    m_order_date = orderDate;
}