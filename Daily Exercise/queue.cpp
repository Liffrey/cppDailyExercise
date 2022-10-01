#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class Queue
{
    Node* tail = new Node;
    Node* head = new Node;

public:
    Queue()
    {
        tail = NULL;
        head = NULL;
    };

public:
    bool isEmpty()
    {
        return head == NULL;
    };
    int peek()
    {
        if(head!=NULL)
        {
            cout << head->val << "-";
            return head->val;
        }
        return NULL;
    };
    void add(int value)
    {
        Node* newNode = new Node;
        newNode->val = value;
        if (tail != NULL)
        {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == NULL)
        {
            head = newNode;
        }
    };
    int remove()
    {
        int val = 0;
        if (head != NULL)
        {
            val = head->val;
            head = head->next;
        }
        if (head == NULL)
        {
            tail = NULL;
        }
        return val;
    }
    void printAllQueue()
    {
        Node* currentNode = head;
        if (currentNode != NULL)
        {
            while (currentNode != NULL)
            {
                cout << currentNode->val << "-";
                currentNode = currentNode->next;
                
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue testQueue;
    testQueue.add(5);
    testQueue.add(4);
    testQueue.add(12);
    testQueue.printAllQueue();
    testQueue.peek();
    testQueue.remove();
    testQueue.peek();
    testQueue.isEmpty();
    return 0;
}