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
#include "ListNode.h"

template <typename NODETYPE>
class List
{

public:
    List()
        : firstPtr(nullptr), lastptr(nullptr)
    {
    }

    ~List()
    {

        if (!isEmpty())
        {
            std::cout << "Destroying Nodes....\n";

            ListNode<NODETYPE> *currentPtr = firstPtr;
            ListNode<NODETYPE> *tempPtr = nullptr;

            while (currentPtr != nullptr)
            {
                tempPtr = currentPtr;
                std::cout << tempPtr->data << "\n";
                currentPtr = currentPtr->nextPtr;
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

    /**
     * @brief Insert Node at front of List
     *
     */
    void insertAtFront(const NODETYPE &value)
    {
        ListNode<NODETYPE> *newPtr = getNewNode(value);

        if (isEmpty())
        {
            firstPtr = lastPtr = newPtr;
        }
        else
        {
            // Point new Node to the Node that was previously first
            newPtr->nextPtr = firstPtr;

            // Aim firstPtr at the new Node
            firstPtr = newPtr;
        }
    }

    /**
     * @brief insert Node at the back of the List
     *
     */
    void insertAtBack(const NODETYPE &value)
    {
        ListNode<NODETYPE> *newPtr = getNewNode(value);

        if (isEmpty())
        {
            firstPtr = lastPtr = newPtr;
        }
        else
        {
            lastPtr->nextPtr = newPtr;
            lastPtr = newPtr;
        }
    }

    /**
     * @brief Delete from the front of the list
     * @return True if delete successful, false if unsuccessful
     *
     */
    bool deleteFromFront(NODETYPE &value)
    {
        if (isEmpty())
            return false;

        else
        {
            ListNode<NODETYPE> *tempPtr = firstPtr; // Temporarily hold the item being deleted

            if (firstPtr == lastPtr)          // List has one element
                firstPtr = lastPtr = nullptr; // No nodes remain
            else
                firstPtr = firstPtr->nextPtr; // point to 2nd Node in the List

            value = tempPtr->data;
            delete tempPtr;
            return true;
        }
    }

    /**
     * @brief Delete from the back of the list
     * @return True if delete successful, false if unsuccessful
     *
     */
    bool deleteFromBack(NODETYPE &value)
    {
        if (isEmpty())
            return false;
        else
        {
            ListNode<NODETYPE> *tempPtr = lastPtr;

            if (firstPtr == lastPtr)
                firstPtr = lastPtr = nullptr;
            else
            {
                ListNode<NODETYPE> *currentPtr = firstPtr;

                while (currentPtr->nextPtr != lastPtr) // Move to the last Node
                    currentPtr = currentPtr->nextPtr;

                lastPtr = currentPtr;
                currentPtr->nextPtr = nullptr;
            }

            value = tempPtr->data;
            delete tempPtr;
            return true;
        }
    }

private:
    ListNode<NODETYPE> *firstPtr; // ptr to first Node
    ListNode<NODETYPE> *lastPtr;  // ptr to last Node

    /**
     * @brief utility function for new Node allocation
     * @return ListNode object
     */
    ListNode<NODETYPE> *getNewNode(const NODETYPE &valueOfNode)
    {
        return new ListNode<NODETYPE>(valueOfNode);
    }
}

#endif
