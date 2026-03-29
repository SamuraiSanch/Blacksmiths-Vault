# CMakeList.txt: проект CMake для Blacksmiths Vault; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget
    "Blacksmiths-Vault.cpp"
    "Blacksmiths-Vault.h"

    # Database
    database/Database.cpp
    database/Database.h
    database/DatabaseManager.cpp
    database/DatabaseManager.h

    # Models
    models/Customer.cpp
    models/Customer.h
    models/Item.cpp
    models/Item.h
    models/Order.cpp
    models/Order.h
    models/Supplier.cpp
    models/Supplier.h

    # Repositories
    repositories/CustomerRepository.cpp
    repositories/CustomerRepository.h
    repositories/ItemRepository.cpp
    repositories/ItemRepository.h
    repositories/OrderRepository.cpp
    repositories/OrderRepository.h
    repositories/SupplierRepository.cpp
    repositories/SupplierRepository.h

    # UI
    ui/Menu.cpp
    ui/Menu.h

    # SQLite
    sqlite/sqlite3.c
    sqlite/sqlite3.h
)

target_include_directories(CMakeTarget PRIVATE
    sqlite
    database
    models
    repositories
    ui
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.