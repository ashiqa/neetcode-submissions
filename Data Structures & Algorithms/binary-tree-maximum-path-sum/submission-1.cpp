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
    int treeTraversal(TreeNode* root, int &maxPathSum){
        if (root == NULL) {
            return 0;
        }

        int leftMax = treeTraversal(root->left, maxPathSum);
        int rightMax = treeTraversal(root->right, maxPathSum);
        
        int ret = max(root->val, max(root->val + leftMax, root->val + rightMax));
        maxPathSum = max(maxPathSum, max(ret, root->val + leftMax + rightMax));
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN; 
        treeTraversal(root, sum);
        return sum;
    }
};
