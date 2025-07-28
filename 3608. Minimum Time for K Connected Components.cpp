class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        std::sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        });
        // for(const auto& edge: edges){
        //     cout << edge[0] << ", " << edge[1] << ", " << edge[2] << endl;
        // }
        std::vector<int> parents(n, -1);
        std::vector<int> ranks(n, 0);
        int cnt = n, res = 0;
        for(int i = 0; i < edges.size(); i++){
            if(Union(parents, ranks, edges[i][0], edges[i][1])){
                cnt--;
            }
            if(cnt >= k){
                res = i+1;
            }else{
                break;
            }
        }

        return res == edges.size() ? 0 : edges[res][2];
    }

    int Find(vector<int>& parents, int x){
        if(parents[x] == -1){
            return x;
        }
        return parents[x] = Find(parents, parents[x]);
    }
    bool Union(vector<int>& parents, vector<int>& ranks, int x, int y){
        int rootx = Find(parents, x);
        int rooty = Find(parents, y);
        if(rootx == rooty){
            return false;
        }
        if(ranks[rootx] > ranks[rooty]){
            parents[rooty] = rootx;
        }else if(ranks[rootx] < ranks[rooty]){
            parents[rootx] = rooty;
        }else{
            // cout << rootx << ", " << rooty << endl;
            parents[rootx] = rooty;
            ranks[rooty]++;
        }
        return true;
    }
    
};
