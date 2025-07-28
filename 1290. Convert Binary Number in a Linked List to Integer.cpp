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
    int getDecimalValue(ListNode* head) {
        std::vector<bool> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        int result = 0;
        int j = 1;
        for(int i = vec.size()-1; i >= 0; i--){
            if(vec[i])    result += j;
            j *= 2;
        }

        return result;
    }
};
