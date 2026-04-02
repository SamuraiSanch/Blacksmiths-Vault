#include "Menu.h"

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

}
void Menu::processOrdersResponse(const short option) {

}
void Menu::processSuppliersResponse(const short option) {

}
void Menu::processCustomersResponse(const short option) {

}
void Menu::processStatisticsResponse(const short option) {

}