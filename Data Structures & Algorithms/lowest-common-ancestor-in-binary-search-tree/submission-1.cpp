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
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res) {
        if (root == NULL) {
            return false;
        }
        bool leftPresent = dfs(root->left, p, q, res);
        bool rightPresent = dfs(root->right, p, q, res);

        if (res == NULL && leftPresent && rightPresent){
            res = root;
        }
        
        if (root->val == p->val || root->val == q->val) {
            if (leftPresent ||rightPresent)res = root; 
            return true;
        }
        if (leftPresent || rightPresent) {
            return true;
        }
    
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        dfs(root, p, q, res);
        return res;
    }
};
