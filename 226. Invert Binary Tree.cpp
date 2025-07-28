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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *node = root;
        DFS(node);
        return root;
    }
    void DFS(TreeNode* node){
        if(node == nullptr || \
            (node->left == nullptr && node->right == nullptr)){
            return;
        }

        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        DFS(node->left);
        DFS(node->right);

        return;
    }
};
