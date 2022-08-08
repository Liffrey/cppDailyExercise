// https://leetcode.com/problems/binary-tree-level-order-traversal/
//  Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

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

class Solution
{
public:
    vector<vector<int>> result;

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (q.empty() == false)
        {
            vector<int> row;
            
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *node = q.front();
                q.pop();
                row.push_back(node->val);

                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};

int main()
{
    Solution tree;
    vector<vector<int>> result;
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "\nlevel order traversal\n";
    result = tree.levelOrder(root);
}