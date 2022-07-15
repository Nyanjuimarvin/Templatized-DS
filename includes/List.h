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

private:
    ListNode<NODETYPE> *firstPtr; // ptr to first Node
    ListNode<NODETYPE> *lastPtr;  // ptr to last Node
}

#endif
