// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:

// Input: root = [1,null,2]
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100

// level:easy

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
    int maxDepth(TreeNode *root)
    {
        //level order solution 
        int i=0;
        int maxDepth = 0;
        if (root == NULL)
        return 0;
        // |3|
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            // |3|9 20| 
            for (int i=0;i< size;i++)
            {
                TreeNode* currentNode = q.front();
            // |9 20| 
                q.pop();

                if(currentNode->left != NULL)
                {
                q.push(currentNode->left);
                }

                if(currentNode->right != NULL)
                {
                q.push(currentNode->right); 
                }
            }
            maxDepth++;
        }
        return maxDepth;
    }
};

int main()
{
    Solution tree;
    int result;
    //[0,2,4,1,null,3,-1,5,1,null,6,null,8]
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "\nmax depth\n";
    result = tree.maxDepth(root);
    cout << result;
}