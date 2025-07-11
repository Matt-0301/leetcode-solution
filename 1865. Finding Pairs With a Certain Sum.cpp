class FindSumPairs {
private:
    std::vector<int> arr2;
    std::unordered_map<int, int> map1;
    std::unordered_map<int, int> map2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr2 = nums2;
        for(const auto& num: nums1){
            ++map1[num];
        }
        for(const auto& num: nums2){
            ++map2[num];
        }
    }
    
    void add(int index, int val) {
        --map2[arr2[index]];
        arr2[index] += val;
        ++map2[arr2[index]];
    }
    
    int count(int tot) {
        int result = 0;
        for(const auto& map: map1){
            int target = tot - map.first;
            if(map2.count(target)){
                result += (map2[target] * map.second);
            }
        }
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
