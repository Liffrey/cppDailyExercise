// https://leetcode.com/problems/symmetric-tree/
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true


// Example 2:
// Input: root = [1,2,2,null,3,null,3]
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100
 
//  level:easy

#include <iostream>
#include <vector>
#include <queue>
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
        // TODO
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
    }
};

int main()
{
    Solution tree;
    bool result;
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    
    cout << "\nisSymmetric\n";
    result = tree.isSymmetric(root);
    cout << result;
}