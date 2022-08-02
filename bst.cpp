// create-read-update-delete
// define
// insertion
// removal
// traversal
#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
class binaryTreeSearch
{
public:
    Node *root;
    binaryTreeSearch()
    {
        root = NULL;
    }
    ~binaryTreeSearch(){};

    void insert(int value)
    {
        if (root == NULL)
        {
        }
        if (value <= root->val)
        {
        }
    }
    bool contains(int value)
    {
    }
    void printInOrder()
    {
    }
};