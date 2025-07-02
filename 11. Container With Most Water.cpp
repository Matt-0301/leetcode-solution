class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size(), left = 0, right = len-1;
        int local, max = 0;
        while(left < right){
            local = (right - left) * std::min(height[left], height[right]);
            if(local > max) max = local;
            if(height[left] < height[right])    ++left;
            else    --right;
        }

        return max;
    }
};
