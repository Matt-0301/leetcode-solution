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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> res;
        if(!root)   return res;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int len = queue.size();
            std::vector<int> subres;
            for(int i = 0; i < len; i++){
                TreeNode *node = queue.front();
                queue.pop();
                subres.push_back(node->val);
                if(node->left)  queue.push(node->left);
                if(node->right)  queue.push(node->right);
            }
            res.push_back(subres);
        }

        return res;
    }
};
