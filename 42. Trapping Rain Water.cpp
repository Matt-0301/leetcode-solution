class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, len = height.size(), left = 0, right = len-1;
        int left_max = height[0], right_max = height[len-1];
        while(left < right){
            if(height[left] < height[right]){
                ++left;
                if(left_max < height[left]) left_max = height[left];
                result += left_max - height[left];
            }else{
                --right;
                if(right_max < height[right]) right_max = height[right];
                result += right_max - height[right];
            }
            // cout << "left: " << left << ", right: " << right << ", result: " << result << endl;
        }

        return result;
    }
};
