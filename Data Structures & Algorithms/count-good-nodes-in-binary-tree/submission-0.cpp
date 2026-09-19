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
    void traversalTree(TreeNode* root, int maxx, int &cnt){
        if (root == NULL){
            return;
        }
        if (root->val >= maxx){
            maxx = root->val;
            ++cnt;
        }
        traversalTree(root->left, maxx, cnt);
        traversalTree(root->right, maxx, cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        traversalTree(root, -101, cnt);
        return cnt;
    }
};
