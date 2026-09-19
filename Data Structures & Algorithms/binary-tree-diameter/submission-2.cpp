/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int traverseTree(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = traverseTree(root->left, res);
        int rightDepth = traverseTree(root->right, res);
        res = max(res, (leftDepth + rightDepth));

        return 1 + max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        traverseTree(root, res);
        return res;
    }
};
