class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN, productMax = 1, productMin = 1;
        int tmp = 1;
        for(const auto& num: nums){
            tmp = productMax * num;
            productMax = std::max({tmp, productMin*num, num});
            productMin = std::min({tmp, productMin*num, num});
            // cout << productMax << ", " << productMin << endl;
            if(result < productMax){
                result = productMax;
            }
        }

        return result;
    }
};
