class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        std::vector<int> parents(c+1, -1);
        std::vector<int> ranks(c+1, 0);
        
        for(const auto& connection: connections){
            Union(parents, ranks, connection[0], connection[1]);
        }
        std::map<int, priority_queue<int, vector<int>, greater<>>> hashmap;
        std::vector<int> group(c+1, 0);
        std::vector<bool> check(c+1, true);
        for(int i = 1; i <= c; i++){
            int tmp = Find(parents, i);
            group[i] = tmp;
            hashmap[tmp].push(i);
        }
        std::vector<int> res;
        for(const auto& query: queries){
            if(query[0] == 1){
                int m = -1;
                if(check[query[1]]){
                    m = query[1];
                }else{
                    int g = group[query[1]];
                    while(!hashmap[g].empty() && !check[hashmap[g].top()]){
                        hashmap[g].pop();
                    }
                    if(!hashmap[g].empty()){
                        m = hashmap[g].top();
                    }
                }
                res.push_back(m);
            }else{
                check[query[1]] = false;
            }
        }

        return res;
    }

    int Find(vector<int>& parents, int x){
        if(parents[x] == -1){
            return x;
        }
        return parents[x] = Find(parents, parents[x]);
    }
    void Union(vector<int>& parents, vector<int>& ranks, int x, int y){
        int rootx = Find(parents, x);
        int rooty = Find(parents, y);
        if(rootx == rooty){
            return;
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
        return;
    }
};
