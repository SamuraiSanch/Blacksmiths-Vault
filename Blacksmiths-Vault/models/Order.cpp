#include "Order.h"
#include "InputHelper.h"
#include "ItemRepository.h"
#include "CustomerRepository.h"

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
std::istream& operator>>(std::istream& in, Order& order) {
    order.setCustomerId(getInput<int>("Enter customer ID: "));
    order.setItemId(getInput<int>("Enter item ID: "));
    order.setQuantity(getInput<int>("Enter quantity: "));

    ItemRepository itemRepo;
    Item item = itemRepo.getById(order.getItemId());

    if (item.getId() == 0) {
        std::cerr << "Item not found!\n";
        order.setCustomerId(0);
        return in;
    }

    if (item.getStock() < order.getQuantity()) {
        std::cerr << "Not enough stock! Available: " << item.getStock()
            << ", Requested: " << order.getQuantity() << "\n";
        order.setCustomerId(0);
        return in;
    }

    double totalPrice = item.getPrice() * order.getQuantity();

    CustomerRepository customerRepo;
    Customer customer = customerRepo.getById(order.getCustomerId());

    if (customer.getId() == 0) {
        std::cerr << "Customer not found!\n";
        order.setCustomerId(0);
        return in;
    }

    if (customer.getGoldBalance() < totalPrice) {
        std::cerr << "Not enough gold! Balance: " << customer.getGoldBalance()
            << ", Required: " << totalPrice << "\n";
        order.setCustomerId(0);
        return in;
    }

    order.setTotalPrice(totalPrice);
    std::cout << "Total price: " << totalPrice << " gold\n";
    order.setStatus("pending");
    order.setOrderDate(getString("Enter order date (dd mm yyyy): "));
    return in;
}