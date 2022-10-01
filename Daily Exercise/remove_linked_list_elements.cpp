//! template version 2.4
//https://leetcode.com/problems/remove-linked-list-elements/submissions/
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// Example 1:

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []

// Constraints:

// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50

// level:easy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct LinkedList
{
    ListNode *head = NULL;

    void add(const int &val)
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
            pCurrentNode = pCurrentNode->next;
        }
        cout << pCurrentNode->val << endl;
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
            for (int i = x - 1; i < x + 1; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            pTempNode->next = pCurrentNode;
        }
    }
    void updateValue(int x, const int &val)
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
    void insertNode(int x, const int &val)
    {
        ListNode *pCurrentNode = head;
        ListNode *pNewNode = new ListNode;
        pNewNode->val = val;
        for (int i = 0; i < x; i++)
        {
            pCurrentNode = pCurrentNode->next;
        }
        pNewNode->next = pCurrentNode->next;
        pCurrentNode->next = pNewNode;
    }
    void printList()
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            while (pCurrentNode != NULL)
            {
                cout << pCurrentNode->val << " - ";
                pCurrentNode = pCurrentNode->next;
            }
            cout << endl;
        }
    }
};

ListNode *removeElements(ListNode *head, int val)
{
    //  x - 1-2-6-3-4-5-6      x = newHead
    //  p - c
    //      p c
    //        p c
    //        p x c
    //            p c
    //              p c
    //                p c
    //                  x
    ListNode *newHead = new ListNode;
    ListNode *prev, *curr;
    newHead->next = head;
    prev = newHead;
    curr = head;
    while (curr!=NULL)
    {
        if(curr->val==val)
        {
            prev->next = curr->next;
        }
        else 
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return newHead->next;
}

int main()
{
    ListNode *resultNode = new ListNode(1);
    resultNode->next = new ListNode(2);
    resultNode->next->next = new ListNode(6);
    resultNode->next->next->next = new ListNode(3);
    resultNode->next->next->next->next = new ListNode(4);
    resultNode->next->next->next->next->next = new ListNode(5);
    resultNode->next->next->next->next->next->next = new ListNode(6);
    int val = 6;
    resultNode = removeElements(resultNode, val);

    if (resultNode != NULL)
    {
        while (resultNode != NULL)
        {
            cout << resultNode->val << " - ";
            resultNode = resultNode->next;
        }
        cout << endl;
    }
}