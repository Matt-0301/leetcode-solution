class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size(), left = 0, right = n-1, mid = (left+right)/2;
        while(left <= right){
            // string tmp = s;
            // for(int i = 0; i <= mid; i++){
            //     tmp[order[i]] = '*';
            // }
            long long cnt = 0;
            std::vector<int> tmp(order.begin(), order.begin()+mid+1);
            std::sort(tmp.begin(), tmp.end());
            cnt += 1LL * (tmp[0] + 1) * (n-tmp[0]);
            for(int i = 1; i <= mid; i++){
                cnt += 1LL * (tmp[i] - tmp[i-1]) * (n-tmp[i]);
            }
            
            if(cnt >= k){
            // if(countSubstring(tmp, n) >= k){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            mid = (left+right)/2;
        }

        return (left == n) ? -1 : left;
    }
    // int countSubstring(string s, int n){
    //     int cnt = 0;
    //     for(int i = 0; i < n; i++){
    //         for(int left = i; left < n; left++){
    //             if(s[left] == '*'){
    //                 cnt += n - left;
    //                 break;
    //             }
    //         }
    //     }

    //     return cnt;
    // }
};
