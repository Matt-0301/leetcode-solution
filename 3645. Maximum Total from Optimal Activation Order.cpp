class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        std::vector<int> index(n);
        std::iota(index.begin(), index.end(), 0);
        std::sort(index.begin(), index.end(), [&](int i, int j){
            if(limit[i] != limit[j]){
                return limit[i] < limit[j];
            }
            return value[i] > value[j];
        });
        std::vector<int> new_value(n);
        std::vector<int> new_limit(n);
        for(int i = 0; i < n; i++){
            new_value[i] = value[index[i]];
            new_limit[i] = limit[index[i]];
        }

        int cnt, act_cnt = 0, act_start = 0;
        long long total = 0;
        for(int i = 0; i < n; i++){
            // cout << "aaaaa: " << act_cnt  << ", " << new_limit[i] << endl;
            if(act_cnt >= new_limit[i]){
                break;
            }
            total += new_value[i];
            ++act_cnt;
            cnt = 0;
            while(act_start < n && act_cnt >= new_limit[act_start]){
                ++act_start, ++cnt;
            }
            act_cnt = (act_cnt-cnt < 0) ? 0 : act_cnt-cnt;
            if(act_start > i+1){
                i = act_start-1;
            }
            // cout << act_cnt << ", " << act_start << ", " << total << ", " << i << endl;
        }

        return total;
    }
};
