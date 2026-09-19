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
    bool treeTraversal(TreeNode* root, int min_r, int max_r){
        if (root == NULL) {
            return true;
        }
        if (root->val <= min_r){
            return false;
        }
        if (root->val >= max_r){
            return false;
        }
        return treeTraversal(root->left, min_r, root->val) && treeTraversal(root->right, root->val, max_r);

    }
    bool isValidBST(TreeNode* root) {
        return treeTraversal(root, INT_MIN, INT_MAX);
    }
};
