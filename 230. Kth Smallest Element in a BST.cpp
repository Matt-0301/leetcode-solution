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
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> res;
        DFS(root, res, k, 0);
        return res[k-1];
    }
    void DFS(TreeNode *node, vector<int>& res, int k, int cnt){
        if(!node)   return;

        DFS(node->left, res, k, cnt);
        res.push_back(node->val);
        if(++cnt == k)  return;
        DFS(node->right, res, k, cnt);
        return;
    }
};
