class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        std::priority_queue<int, vector<int>, greater<int>> minHeapPlayers;
        std::priority_queue<int, vector<int>, greater<int>> minHeapTrainers;

        for(const auto& player: players){
            minHeapPlayers.push(player);
        }
        for(const auto& trainer: trainers){
            minHeapTrainers.push(trainer);
        }
        int result = 0;
        while(!minHeapTrainers.empty() && !minHeapPlayers.empty()){
            int p = minHeapPlayers.top();
            while(!minHeapTrainers.empty() && minHeapTrainers.top() < p){
                minHeapTrainers.pop();
            }
            if(!minHeapTrainers.empty()){
                ++result;
                minHeapTrainers.pop();
            }
            minHeapPlayers.pop();
        }

        return result;

    }
};
