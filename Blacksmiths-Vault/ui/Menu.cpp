#include "Menu.h"
#include "InputHelper.h"

short chooseOption(const short min, const short max) {
    short answer;
    while (true) {
        std::cin >> answer;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Incorrect answer. Please enter a number.\n";
        }
        else if (answer >= min && answer <= max) {
            return answer;
        }
        else std::cerr << "Incorrect number entered. Please try again.";
    }
}

void Menu::startMenu() {
    std::cout << " === BLACKSMITH'S VAULT === \n1. Items\n2. Suppliers\n3. Customers\n4. Orders\n5. Statistics\n0. Exit\nYour choice: ";
    short answer;
    while (true) {
        answer = chooseOption(0, 5);
        if (answer >= 1 && answer <= 5) {
            processResponse(answer);
        }
        else if (answer == 0) {
            std::cout << "Thank you for use BLACKSMITH'S VAULT!\n";
            break;
        }
        else std::cerr << "Incorrect number entered. Please try again.";
    }
}
void Menu::processResponse(const short option) {
    switch (option) {
    case 1: 
        std::cout << "What do you want to do with Items?\n1. Watch all items\n2. Add new item\n3. Update item\n4. Delete item\n5. Filter by rarity\n6. Filter by type\nYour choice: ";
        processItemsResponse(chooseOption(1, 6));
        break;
    case 2:  std::cout << "What do you want to do with Suppliers?\n1. Watch all Suppliers\n2. Add new supplier\n3. Update supplier\n4. Delete supplier\n5. Filter by origin\nYour choice: ";
        processSuppliersResponse(chooseOption(1, 5));
        break;
    case 3:
        std::cout << "What do you want to do with Customers?\n1. Watch all customers\n2. Add new customer\n3. Update customer\n4. Delete customer\n5. Filter by guild\nYour choice: ";
        processCustomersResponse(chooseOption(1, 5));
        break;
    case 4:
        std::cout << "What do you want to do with Orders?\n1. Watch all orders\n2. Add new order\n3. Update order\n4. Delete order\n5. Cancel order\n6. Filter by status\nYour choice: ";
        processOrdersResponse(chooseOption(1, 6));
        break;
    case 5:
        std::cout << "What do you want to do with Statistics?\n1. Watch top 5 items by popularity\n2. Watch general profit\n3. Watch items with low supply\nYour choice: ";
        processStatisticsResponse(chooseOption(1, 3));
        break;
    default: std::cerr << "Unexpected option choosed!\n"; break;
    }
}
void Menu::processItemsResponse(const short option) {
    switch (option) {
    case 1: {
        std::vector<Item> allItems = i.getAll();
        for (const auto& item : allItems)
            std::cout << item;
        break;
    }
    case 2: {
        Item newItem;
        std::cin >> newItem;
        i.add(newItem);
        std::cout << "Item added successfully!\n";
        break;
    }
    case 3: {
        int updateId = getInput<int>("Enter item ID to update: ");
        Item updateItem = i.getById(updateId);
        if (updateItem.getId() == 0) {
            std::cerr << "Item not found!\n";
            break;
        }
        std::cout << "Current item: \n" << updateItem << '\n';
        std::cout << "Enter new data:\n";
        std::cin >> updateItem;

        i.update(updateItem);
        std::cout << "Item updated successfully!\n";
        break;
    }
    case 4: {
        int removeId = getInput<int>("Enter item ID to delete: ");
        Item removeItem = i.getById(removeId);
        if (removeItem.getId() == 0) {
            std::cerr << "Item not found!\n";
            break;
        }
        std::cout << "Current item:\n" << removeItem << '\n';
        i.remove(removeId);
        std::cout << "Item deleted successfully!\n";
        break;
    }
    case 5: {
        std::string rarityToSort = getString("Enter rarity to filter by: ");
        std::vector<Item> itemsWithInputRarity = i.filterByRarity(rarityToSort);
        if (itemsWithInputRarity.empty()) {
            std::cerr << "Incorrect rarity. Items with that rarity not found.\n";
            break;
        }
        for (const auto& item : itemsWithInputRarity)
            std::cout << item;
        break;
    }
    case 6: {
        std::string typeToSort = getString("Enter type to filter by: ");
        std::vector<Item> itemsWithInputType = i.filterByType(typeToSort);
        if (itemsWithInputType.empty()) {
            std::cerr << "Incorrect type. Items with that type not found.\n";
            break;
        }
        for (const auto& item : itemsWithInputType)
            std::cout << item;
        break;
    }
    }
}
void Menu::processOrdersResponse(const short option) {
    switch (option) {
    case 1: {
        std::vector<Order> allOrders = o.getAll();
        for (const auto& order : allOrders)
            std::cout << order;
        break;
    }
    case 2: {
        Order newOrder;
        std::cin >> newOrder;
        o.add(newOrder);
        std::cout << "Order added successfully!\n";
        break;
    }
    case 3: {
        int updateId = getInput<int>("Enter order ID to update: ");
        Order updateOrder = o.getById(updateId);
        if (updateOrder.getId() == 0) {
            std::cerr << "Order not found!\n";
            break;
        }
        std::cout << "Current order: \n" << updateOrder << '\n';
        std::cout << "Enter new data:\n";
        std::cin >> updateOrder;

        o.update(updateOrder);
        std::cout << "Order updated successfully!\n";
        break;
    }
    case 4: {
        int removeId = getInput<int>("Enter order ID to delete: ");
        Order removeOrder = o.getById(removeId);
        if (removeOrder.getId() == 0) {
            std::cerr << "Order not found!\n";
            break;
        }
        std::cout << "Current order:\n" << removeOrder << '\n';
        o.remove(removeId);
        std::cout << "Order deleted successfully!\n";
        break;
    }
    case 5: {
        int cancelId = getInput<int>("Enter order ID to cancel: ");
        Order cancelOrder = o.getById(cancelId);
        if (cancelOrder.getId() == 0) {
            std::cerr << "Order not found!\n";
            break;
        }
        else if (cancelOrder.getStatus() == "cancelled") {
            std::cerr << "Order is already cancelled!\n";
            break;
        }
        o.cancel(cancelOrder.getId());
        std::cout << "Order cancelled successfully!\n";
        break;
    }
    case 6: {
        std::string statusToSort = getString("Enter status to filter by: ");
        std::vector<Order> ordersWithInputStatus = o.filterByStatus(statusToSort);
        if (ordersWithInputStatus.empty()) {
            std::cerr << "Incorrect status. Orders with that status not found.\n";
            break;
        }
        for (const auto& order : ordersWithInputStatus)
            std::cout << order;
        break;
    }
    }
}
void Menu::processSuppliersResponse(const short option) {
    switch (option) {
        case 1: {
            std::vector<Supplier> allSuppliers = s.getAll();
            for (const auto& supplier : allSuppliers)
                std::cout << supplier;
            break;
        }
        case 2: {
        Supplier newSupplier;
        std::cin >> newSupplier;
        s.add(newSupplier);
        std::cout << "Supplier added successfully!\n";
        break;
        }
        case 3: {
            int updateId = getInput<int>("Enter supplier ID to update: ");
            Supplier updateSupplier = s.getById(updateId);
            if (updateSupplier.getId() == 0) {
                std::cerr << "Supplier not found!\n";
                break;
            }
            std::cout << "Current supplier: \n" << updateSupplier << '\n';
            std::cout << "Enter new data:\n";
            std::cin >> updateSupplier;
            s.update(updateSupplier);
            std::cout << "Supplier updated successfully!\n";
            break;
        }
        case 4: {
            int removeId = getInput<int>("Enter supplier ID to delete: ");
            Supplier removeSupplier = s.getById(removeId);
            if (removeSupplier.getId() == 0) {
                std::cerr << "Supplier not found!\n";
                break;
            }
            std::cout << "Current supplier:\n" << removeSupplier << '\n';
            s.remove(removeId);
            std::cout << "Supplier deleted successfully!\n";
            break;
        }
        case 5: {
            std::string originToSort = getString("Enter origin to filter by: ");
            std::vector<Supplier> suppliersWithInputOrigin = s.filterByOrigin(originToSort);
            if (suppliersWithInputOrigin.empty()) {
                std::cerr << "Incorrect origin. Suppliers with that origin not found.\n";
                break;
            }
            for (const auto& supplier : suppliersWithInputOrigin)
                std::cout << supplier;
            break;
        }
    }
}
void Menu::processCustomersResponse(const short option) {
    switch (option) {
    case 1: {
        std::vector<Customer> allCustomers = c.getAll();
        for (const auto& customer : allCustomers)
            std::cout << customer;
        break;
    }
    case 2: {
        Customer newCustomer;
        std::cin >> newCustomer;
        c.add(newCustomer);
        std::cout << "Customer added successfully!\n";
        break;
    }
    case 3: {
        int updateId = getInput<int>("Enter customer ID to update: ");
        Customer updateCustomer = c.getById(updateId);
        if (updateCustomer.getId() == 0) {
            std::cerr << "Customer not found!\n";
            break;
        }
        std::cout << "Current customer: \n" << updateCustomer << '\n';
        std::cout << "Enter new data:\n";
        std::cin >> updateCustomer;
        c.update(updateCustomer);
        std::cout << "Customer updated successfully!\n";
        break;
    }
    case 4: {
        int removeId = getInput<int>("Enter customer ID to delete: ");
        Customer removeCustomer = c.getById(removeId);
        if (removeCustomer.getId() == 0) {
            std::cerr << "Customer not found!\n";
            break;
        }
        std::cout << "Current customer:\n" << removeCustomer << '\n';
        c.remove(removeId);
        std::cout << "Customer deleted successfully!\n";
        break;
    }
    case 5: {
        std::string guildToSort = getString("Enter guild to filter by: ");
        std::vector<Customer> customersWithInputGuild = c.filterByGuild(guildToSort);
        if (customersWithInputGuild.empty()) {
            std::cerr << "Incorrect guild. Customers with that guild not found.\n";
            break;
        }
        for (const auto& customer : customersWithInputGuild)
            std::cout << customer;
        break;
    }
    }
}
void Menu::processStatisticsResponse(const short option) {
    switch (option) {
    case 1: stats.printTop5Items(); break;
    case 2: stats.printTotalProfit(); break;
    case 3: stats.printLowStockItems(); break;
    }
}