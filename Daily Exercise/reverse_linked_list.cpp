//! template version 2.5
// https://leetcode.com/problems/reverse-linked-list/
//  Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000

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
    //  x - 1-2-6-3-4-5-6
    //  p - c
    ListNode *newHead = new ListNode;
    ListNode *prev, *curr;
    newHead->next = head;
    prev = newHead;
    curr = head;
    while (curr != NULL)
    {
        if (curr->val == val)
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

ListNode *reverseList(ListNode *head)
{
    //   1 2 3 4 5 - null
    //           * 
    //   
    //   5 4 3 2 1 - null
    
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
    resultNode = reverseList(resultNode);

    if (resultNode != NULL)
    {
        while (resultNode != NULL)
        {
            cout << resultNode->val << " - ";
            resultNode = resultNode->next;
        }
        cout << endl;
    }
    cout << "Beklenen"
         << " "
         << "6-5-4-3-5-2-1";
}