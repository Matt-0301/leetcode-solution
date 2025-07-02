class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        int mid = (left + right) / 2;
        while(left <= right){
            long long count = 0;
            // cout << "mid: " << mid << endl;
            for(const auto& pile: piles){
                count += pile / mid;
                if(pile % mid != 0) count++;
            }
            // cout << count << endl;
            if(count <= h){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }

        return left;
    }
};
