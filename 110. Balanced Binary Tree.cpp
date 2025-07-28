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
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right) <= 1){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }

    int height(TreeNode* node){
        if(!node){
            return 0;
        }

        return std::max(1+height(node->left), 1+height(node->right));
    }
};
