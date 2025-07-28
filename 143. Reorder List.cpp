/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)   return;
        std::vector<ListNode*> node;
        ListNode* cur = head;
        while(cur){
            node.push_back(cur);
            cur = cur->next;
        }
        int i = 0, j = node.size()-1;
        while(i < j){
            node[i]->next = node[j];
            ++i;
            if(i >= j)  break;
            node[j]->next = node[i];
            --j;
        }
        node[i]->next = nullptr;
    }
};
