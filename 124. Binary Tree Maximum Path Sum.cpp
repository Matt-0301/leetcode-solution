// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         int res = INT_MIN;
//         int *result = &res;
//         DFS(root, result);

//         return res;
//     }
//     int DFS(TreeNode *node, int *res){
//         if(node == nullptr) return 0;

//         if(node->val > *res)    *res = node->val;
//         int left = DFS(node->left, res);
//         int right = DFS(node->right, res);
//         if(node->val + left > *res)    *res = node->val + left;
//         if(node->val + right > *res)    *res = node->val + right;
//         if(left+right+node->val > *res){
//             *res = left+right+node->val;
//         }

//         return std::max(node->val, node->val+std::max(left, right));
//     }
// };
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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int *result = &res;
        DFS(root, result);

        return res;
    }
    int DFS(TreeNode *node, int *res){
        if(node == nullptr) return 0;

        int left = std::max(DFS(node->left, res), 0);
        int right = std::max(DFS(node->right, res), 0);
        if(left+right+node->val > *res){
            *res = left+right+node->val;
        }

        return std::max(node->val, node->val+std::max(left, right));
    }
};
