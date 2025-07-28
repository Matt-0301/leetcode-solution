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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int *result = &res;
        DFS(root, 0, result);

        return res;
    }
    int DFS(TreeNode* node, int depth, int *res){
        if(node == nullptr){
            return 0;
        }
        int left = DFS(node->left, depth, res);
        int right = DFS(node->right, depth+1, res);
        if(left + right > *res){
            *res = left + right;
        }
        return 1 + std::max(left, right);
    }
};
