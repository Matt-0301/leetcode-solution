class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());
        std::vector<long long> rooms(n, 0);
        std::vector<int> freq(n, 0);
        bool used;
        int min;
        for(const auto& meeting: meetings){
            used = false;
            min = 0;
            for(int i = 0; i < n; i++){
                if(rooms[i] <= meeting[0]){ // can used
                    used = true;
                    rooms[i] = meeting[1];
                    ++freq[i];
                    break;
                }
                if(rooms[i] < rooms[min]){
                    min = i;
                }
            }
            if(!used){
                rooms[min] = meeting[1] - meeting[0] + rooms[min];
                ++freq[min];
            }
        }
        int max = 0;
        for(int i = 0; i < n; i++){
            if(freq[i] > freq[max]){
                max = i;
            }
        }

        return max;
    }
};
