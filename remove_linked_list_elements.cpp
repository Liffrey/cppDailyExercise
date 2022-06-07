//! template version 2.4

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
    LinkedList givenList;
    givenList.head = head;
    while(head != NULL)
    {

    }
    //listenin üzerinden geç
    //eğer verilen val değeri ile listedeki node değerlerinden biri eşleşirse
        //eşleşe node'u sil 
}