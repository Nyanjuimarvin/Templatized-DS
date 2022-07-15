/**
 * @file ListNodes.h
 * @author Nyanjuimarvin
 * @brief Template class ListNode definition
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LISTNODE_H
#define LISTNODE_H

// Forward Declaration of class List
template <typename NODETYPE> class List;

template <typename NODETYPE>
class ListNode
{
    // Make class List friend -> Access of ListNode private members
    friend class List<NODETYPE>;

public:

    //Default constructor
    explicit ListNode( const NODETYPE &typeInfo )
    :data(typeInfo), nextPtr(nullptr)
    {

    }
    
    //get data in ListNode
    NODETYPE getData() const{
        return data;
    }

private:
    NODETYPE data;
    ListNode<NODETYPE> *nextPtr;
}

#endif
