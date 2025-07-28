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
    int goodNodes(TreeNode* root) {
        return DFS(root, INT_MIN);
    }

    int DFS(TreeNode* node, int maxval){
        if(!node){
            return 0;
        }
        int res = (node->val < maxval) ? 0 : 1;
        maxval = std::max(node->val, maxval);
        return res + DFS(node->left, maxval) + DFS(node->right, maxval);
    }
};
