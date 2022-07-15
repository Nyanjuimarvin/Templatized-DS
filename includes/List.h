/**
 * @file List.h
 * @author Nyanjuimarvin
 * @brief Template class List definition
 * @version 0.1
 * @date 2022-07-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNodes.h"

template <typename NODETYPE>
class List
{

public:

    List()
        : firstPtr(nullptr), lastptr(nullptr)
    {
    }

    ~List(){

        if( !isEmpty() ){
            std::cout << "Destroying Nodes....\n";

            ListNode<NODETYPE> *currentPtr = firstPtr;
            ListNode<NODETYPE> *tempPtr = nullptr;

            while ( currentPtr != nullptr ){
                tempPtr = currentPtr;
                std::cout << tempPtr ->data << std::endl;
                currentPtr = currentPtr -> nextPtr;
                delete tempPtr;
            }
            
        }

        std::cout << "Destruction of Nodes Completed \n\n";
    }

    /**
     * @brief isEmpty() function
     * @return true if List is empty, else false
     *
     */
    bool isEmpty() const
    {
        return firstPtr == nullptr;
    }

private:
    ListNode<NODETYPE> *firstPtr; // ptr to first Node
    ListNode<NODETYPE> *lastPtr;  // ptr to last Node
}

#endif
