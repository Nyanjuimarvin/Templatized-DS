/* LIST NODES.h
 *   by Nyanjuimarvin
 *
 * Created:
 *   July 15, 2022, 1:42:24 PM GMT+3
 * Last edited:
 *   July 15, 2022, 1:56:03 PM GMT+3
 * Auto updated?
 *   Yes
 *
 * Description:
 *   Template class ListtNode definition
 **/

#ifndef LISTNODE_H
#define LISTNODE_H

// Forward Declaration of class List
template <typename NODETYPE> class List;

template <typename NODETYPE>
class ListNode
{
    // Make class List friend -> Access of ListNode private members
    friend class List<NODETYPE>;

private:
    NODETYPE data;
    ListNode<NODETYPE> *nextPtr;
}

#endif
