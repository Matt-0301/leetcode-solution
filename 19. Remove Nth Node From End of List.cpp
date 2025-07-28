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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head;
        int len = 0;
        while(cur){
            ++len;
            cur = cur->next;
        }
        n = len - n;
        cout << n << endl;
        int now = 1;
        ListNode **indirect = &head;
        if(n == 0){
            indirect = &((*indirect)->next);
            return *indirect;
        }
        while(now < n){
            ++now;
            indirect = &((*indirect)->next);
        }
        (*indirect)->next = (*indirect)->next->next;

        return head;
    }
};
