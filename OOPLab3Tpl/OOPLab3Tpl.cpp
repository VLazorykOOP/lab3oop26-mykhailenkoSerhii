#include <iostream>

#include "Task1.h"
#include "Task2.h"

int main()
{
    std::cout << " Lab #3  !\n";
    std::cout << "\nSelect an option \n";
    std::cout << " 0. Exit \n";
    std::cout << " 1. Task One - Time Class \n";
    std::cout << " 2. Task Two - Vector Class \n";

    int task = 0;
    std::cout << "Preferred task : ";
    std::cin >> task;

    if (task == 1)
        task1();
    else if (task == 2)
        task2();

    return 1;
}

