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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *cur = res;
        bool carry = false;
        while(l1 || l2){
            int val;
            if(!l1) val = l2->val;
            else if(!l2) val = l1->val;
            else val = l1->val + l2->val;

            if(carry){
                val++;
                carry = false;
            }
            if(val >= 10){
                carry = true;
                val -= 10;
            }
            cur->next = new ListNode(val);
            cur = cur->next;

            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        if(carry)   cur->next = new ListNode(1);
        
        return res->next;
    }
};
