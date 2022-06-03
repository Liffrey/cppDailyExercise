//! template version 2.3
// https://leetcode.com/problems/linked-list-cycle/

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:

// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:

// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.

//  level:easy

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};
struct LinkedList
{
    ListNode *head = NULL;
    void add(int const &val)
    {
        ListNode *pNewNode = new ListNode;
        pNewNode->val = val;
        pNewNode->next = NULL;

        if (head == NULL)
        {
            head = pNewNode;
        }
        else
        {
            ListNode *pCurrentNode = head;

            while (pCurrentNode->next != NULL)
            {
                pCurrentNode = pCurrentNode->next;
            }
            pCurrentNode->next = pNewNode;
        }
    }

    void get(int x)
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            for (int i = 0; i < x; i++)
            {
                pCurrentNode->next = pCurrentNode;
            }
            cout << pCurrentNode->val << endl;
        }
    }

    void del(int x)
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            for (int i = 0; i < x - 1; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            ListNode *pTempNode = pCurrentNode;
            {
                for (int i = x - 1; i < x + 1; i++)
                {
                    pCurrentNode = pCurrentNode->next;
                }
                pTempNode->next = pCurrentNode;
            }
        }
    }

    void updateValue(int x, int &val)
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            for (int i = 0; i < x; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            pCurrentNode->val = val;
        }
    }

    void insertNode(int x, int &val)
    {
        
        ListNode *pCurrentNode = head;
        ListNode *pNewNode = new ListNode;
        pNewNode->val=val;
        ListNode *pTempNode = new ListNode;
        for (int i = 0; i < x - 1; i++)
        {
            pCurrentNode->next = pCurrentNode;
        }
        
    }

    void printList()
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            while (pCurrentNode != NULL)
            {
                cout << pCurrentNode->val << " ";
                pCurrentNode = pCurrentNode->next;
            }
            cout << endl;
        }
    }
};
bool hasCycle(ListNode *head)
{
    bool result = false;
    return result;
}

int main()
{
    LinkedList head;
    head.add(3);
    head.printList();
    head.add(2);
    head.printList();
    return 0;
}