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
    TreeNode* recursiveBuild(int &i, int min_r, int max_r, vector<int>& preorder, vector<int>& inorder) {

        if (i >= preorder.size()){
            return NULL;
        }
        if (min_r > max_r){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[i]);

        int currentPos = -1;
        for (int f = min_r; f <= max_r; ++f){
            if (inorder[f] == preorder[i]){
                currentPos = f;
            }
        }
        i++;

        TreeNode* leftSubTree = recursiveBuild(i, min_r, currentPos - 1, preorder, inorder);
        TreeNode* rightSubTree = recursiveBuild(i, currentPos + 1, max_r, preorder, inorder);
        node->left = leftSubTree;
        node->right = rightSubTree;
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int id = 0;
        return recursiveBuild(id, 0, preorder.size() - 1, preorder, inorder);
    }
};
