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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **indirect = &head;
        while(*indirect){
            if((*indirect)->val == val){
                *indirect = (*indirect)->next;
            }else{
                indirect = &(*indirect)->next;
            }
        }

        return head;
    }
};
