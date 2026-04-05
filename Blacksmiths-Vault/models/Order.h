#ifndef ORDER_H
#define ORDER_H
#include <iostream>

class Order {
private:
    int m_id = 0;
    int m_customer_id;
    int m_item_id;
    int m_quantity;
    double m_total_price;
    std::string m_status;
    std::string m_order_date;
public:
    int getId() const;
    int getCustomerId() const;
    int getItemId() const;
    int getQuantity() const;
    double getTotalPrice() const;
    std::string getStatus() const;
    std::string getOrderDate() const;
    void setId(const int id);
    void setCustomerId(const int customerId);
    void setItemId(const int itemId);
    void setQuantity(const int quantity);
    void setTotalPrice(const double totalPrice);
    void setStatus(const std::string& status);
    void setOrderDate(const std::string& orderDate);
};

std::ostream& operator<< (std::ostream& out, const Order& order);
std::istream& operator>> (std::istream& in, Order& order);

#endif

