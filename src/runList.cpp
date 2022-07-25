/**
 * @file runList.cpp
 * @author Nyanjuimarvin
 * @brief Executable to test the List
 * @version 0.1
 * @date 2022-07-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>

#include "List.h"

void whatToDo()
{
    std::cout << "Enter one of the following:\n"
              << " 1 to insert at beginning of list\n"
              << " 2 to insert at end of list\n"
              << " 3 to delete from beginning of list\n"
              << " 4 to delete from end of list\n"
              << " 5 to end list processing\n";
}

/**
 * @brief test the List and its Operations
 *
 */
template <typename T>
void testList(List<T> &listObject, const std::string &objectTypeName)
{
    std::cout << "Testing a List of " << objectTypeName << std::endl;
    whatToDo();

    unsigned short operationChosen;
    T value;

    do
    {
        std::cout << "? ";
        std::cin >> operationChosen;

        switch (operationChosen)
        {
        case 1:
            std::cout << "Enter " << objectTypeName << ": ";
            std::cin >> value;
            listObject.insertAtFront(value);
            listObject.printList();
            break;

        case 2:
            std::cout << "Enter " << objectTypeName << ": ";
            std::cin >> value;
            listObject.insertAtBack(value);
            listObject.printList();
            break;

        case 3:
            if (listObject.deleteFromFront(value))
                std::cout << value << " removed from the front of the List\n";
            listObject.printList();
            break;

        case 4:
            if (listObject.deleteFromBack(value))
                std::cout << value << " removed from the back of the List\n";
            listObject.printList();
            break;
        }

    } while (operationChosen < 5);

    std::cout << "Aborting List Processing...\n\n\n";
}

int main(int, char**)
{
    List<int> intList;
    testList(intList, "Integer");
}