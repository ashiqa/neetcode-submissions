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
    bool findNode(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res) {
        if (root == NULL){
            return false;
        }
        
        bool leftFound = findNode(root->left, p, q, res);
        bool rightFound = findNode(root->right, p, q, res);

        if ((root->val == p->val || root->val == q->val) 
            && (leftFound || rightFound)){
            res = root;
            return true;
        }
    
        if (leftFound && rightFound){
            res = root;
            return true;
        }
        if (p->val == root->val) {
            return true;
        }
        if (q->val == root->val) {
            return true;
        }
        if (leftFound || rightFound){
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        findNode(root, p, q, res);
        return res;
    }
};
