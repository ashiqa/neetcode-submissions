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
        if (root == NULL){
            return false;
        }
        bool lFound = dfs(root->left, p, q, res);
        bool rFound = dfs(root->right, p, q, res);
        if (lFound && rFound){
            res = root;
        } else if ((lFound || rFound) && (root->val == p->val || root->val == q->val)){
            res = root;
        }
        if (root->val == p->val || root->val == q->val || lFound || rFound) {
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
