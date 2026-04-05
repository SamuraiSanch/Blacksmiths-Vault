#ifndef STATISTICSREPOSITORY_H
#define STATISTICSREPOSITORY_H

#include "Database.h"
#include <iostream>
#include <vector>
#include <string>

class StatisticsRepository {
public:
    void printTotalProfit();
    void printTop5Items();
    void printLowStockItems();
};

#endif
