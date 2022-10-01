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

class Stack
{
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }
    ~Stack()
    {
        Node* pDel = top;
        Node* pWalk = top;
        if (top != NULL)
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

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    };
    int peek()
    {
        if (top != NULL)
        {
            cout << top->val << "-";
            return top->val;
        }
        return 0;
    };
    void push(int value)
    {
        Node* newNode = new Node;
        newNode->val = value;
        
        if (top != NULL)
        {
            newNode->next = top;
            top = newNode;
        }
        else {
            top = newNode;
        }
    };
    int pop()
    {
        int val = top->val;
        top = top->next;
        return val;
    };
    void printAllStack()
    {
        Node* newNode = top;
        if (newNode != NULL)
        {
            while (newNode != NULL)
            {
                cout << newNode->val << "-";
                newNode = newNode->next;
            }
            cout << endl;
        }
    };
};

int main()
{
    {
        Stack s;
    }
    {
        Stack s;
        s.push(1);
    }
    {
        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
    }
    Stack testStack;
    testStack.push(5);
    testStack.push(4);
    testStack.push(12);
    testStack.printAllStack();
    testStack.peek();
    testStack.pop();
    testStack.peek();
    testStack.isEmpty();
    return 0;
}