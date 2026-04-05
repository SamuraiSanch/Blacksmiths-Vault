#include "Order.h"
#include "InputHelper.h"

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
std::ostream& operator<< (std::ostream& out, const Order& order) {
    out << order.getId() << ": " << order.getCustomerId() << " | " << order.getItemId() << " | " << order.getQuantity() << " | " << order.getTotalPrice() << " | " << order.getStatus() << " | " << order.getOrderDate() << '\n';
    return out;
}
std::istream& operator>> (std::istream& in, Order& order) {
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    order.setCustomerId(getInput<int>("Enter customer ID: "));
    order.setItemId(getInput<int>("Enter item ID: "));
    order.setQuantity(getInput<int>("Enter quantity: "));
    order.setTotalPrice(getInput<double>("Enter total price: "));
    order.setStatus(getString("Enter status: "));
    order.setOrderDate(getString("Enter order date: "));
    return in;
}