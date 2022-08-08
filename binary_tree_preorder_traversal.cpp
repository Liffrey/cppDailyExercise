// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,2,3]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

#include <iostream>
#include <vector>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    ~TreeNode()
    {
    //TODO
    }
};

class Traversal
{
public:
    vector<int> resultPreorderTraversal;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return resultPreorderTraversal;

        cout << root->val << " ";
        resultPreorderTraversal.push_back(root->val);

        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return resultPreorderTraversal;
    }
    vector<int> resultPostorderTraversal;
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return resultPostorderTraversal;

        postorderTraversal(root->left);
        postorderTraversal(root->right);

        cout << root->val << " ";
        resultPostorderTraversal.push_back(root->val);

        return resultPostorderTraversal;
    }
    vector<int> resultInorderTraversal;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return resultInorderTraversal;

        inorderTraversal(root->left);
        cout << root->val << " ";
        resultInorderTraversal.push_back(root->val);
        inorderTraversal(root->right);

        return resultInorderTraversal;
    }
};

int main()
{
    Traversal tree;
    vector<int> result;
    TreeNode *root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "\nPreorder traversal\n";
    result = tree.preorderTraversal(root);
}