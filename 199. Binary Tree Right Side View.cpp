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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        if(!root)   return res;
        std::queue<TreeNode*> queue;
        int len, i;
        TreeNode *node;

        queue.push(root);
        while(!queue.empty()){
            len = queue.size();
            res.push_back(queue.front()->val);
            for(i = 0; i < len; i++){
                node = queue.front();
                queue.pop();
                if(node->right) queue.push(node->right);
                if(node->left) queue.push(node->left);
            }
        }

        return res;
    }
};
