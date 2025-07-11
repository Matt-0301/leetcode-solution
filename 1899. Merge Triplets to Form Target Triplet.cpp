class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        std::vector<int> result(3, 0);
        for(const auto& triplet: triplets){
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                result = {std::max(triplet[0], result[0]), std::max(triplet[1], result[1]),\
                    std::max(triplet[2], result[2])};
            }
        }
        return result == target;
    }
};
