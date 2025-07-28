class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast){
                break;
            }
        }
        
        int check = nums[0];
        while(slow != check){
            slow = nums[slow];
            check = nums[check];
        }

        return slow;
    }
};
