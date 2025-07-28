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
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;

        return DFS(root, LONG_MIN, LONG_MAX);
    }

    bool DFS(TreeNode *node, long low, long high){
        if(!node)   return true;

        if(node->val > low && node->val < high){
            return DFS(node->left, low, node->val) && \
                    DFS(node->right, node->val, high);
        }
        return false;
    }
};
