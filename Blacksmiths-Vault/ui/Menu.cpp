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
        std::cout << "What do you want to do with Statistics?\n1. Watch top 5 items by popularity\n2. Watch general profit\n3. Watch items with low supply\n4. Watch top supplier\nYour choice: ";
        processStatisticsResponse(chooseOption(1, 4));
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

}
void Menu::processSuppliersResponse(const short option) {

}
void Menu::processCustomersResponse(const short option) {

}
void Menu::processStatisticsResponse(const short option) {

}