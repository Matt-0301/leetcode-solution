class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size(), left = 0, right = len-1;
        while(left < right){
            // cout << numbers[left] << ", " << numbers[right] << endl;
            if(numbers[left] + numbers[right] == target)  return {left+1, right+1};
            if(numbers[left] + numbers[right] > target){
                --right;
            }else{
                ++left;
            }
        }
        return {left+1, right+1};
    }
};
