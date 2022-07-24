#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode *head;

    ~ListNode()
    {
        ListNode *pDel = head;
        ListNode *pWalk = head;
        if (head != NULL)
        {

            while (pWalk->next != NULL)
            {
                pWalk = pWalk->next;
                delete pDel;
                pDel = pWalk;
            }
            if (pWalk->next == NULL)
                delete pWalk;
        }
    }
};

class LinkedList
{
public:
    ListNode *head = NULL;
    void add(const int &value)
    {
        ListNode *pNewNode = new ListNode;
        pNewNode->val = value;
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
    };
    void get(int x)
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            for (int i = 0; i < x; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            cout << pCurrentNode->val << endl;
        }
    };
    void update(int x, const int &value)
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            for (int i = 0; i < x; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            pCurrentNode->val = value;
        }
    };
    void del(int x)
    {
        ListNode *pCurrentNode = head;
        ListNode *pTempNode = new ListNode;
        if (pCurrentNode != NULL)
        {
            for (int i = 0; i < x - 1; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            pTempNode = pCurrentNode;
            for (int i = x - 1; i < x + 1; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            pTempNode->next = pCurrentNode;
        }
    };
    void insertAfter(int x, const int &value)
    {
        ListNode *pCurrentNode = head;
        ListNode *pNewNode = new ListNode;
        pNewNode->val = value;
        if (pCurrentNode != NULL)
        {
            for (int i = 0; i < x; i++)
            {
                pCurrentNode = pCurrentNode->next;
            }
            pNewNode->next = pCurrentNode->next;
            pCurrentNode->next = pNewNode;
        }
    };
    void print()
    {
        ListNode *pCurrentNode = head;
        if (pCurrentNode != NULL)
        {
            while (pCurrentNode != NULL)
            {
                cout << pCurrentNode->val << "-";
                pCurrentNode = pCurrentNode->next;
            }
            cout << endl;
        }
    };
};

int main()
{
    {
        LinkedList list;
        list.add(10);
        list.add(12);
        list.add(14);
        list.print();
        list.update(2, 100);
        list.print();
        list.del(2);
        list.print();
        list.get(0);
        list.insertAfter(1, 200);
        list.print();
    }
    return 0;
}