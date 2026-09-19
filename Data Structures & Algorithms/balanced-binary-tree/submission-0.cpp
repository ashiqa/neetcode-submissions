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
    int heightOfTree(TreeNode* root, bool &res) {
        if (root == NULL) {
            return 0;
        }
        int lHT = heightOfTree(root->left, res);
        int rHT = heightOfTree(root->right, res);
        if (abs(lHT-rHT) > 1){
            res = false;
        }
        return 1 + max(lHT, rHT);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        heightOfTree(root, res);
        return res; 
    }
};
