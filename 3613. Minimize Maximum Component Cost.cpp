class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(n <= k)  return 0;
        std::vector<int> parents(n, -1);
        // std::iota(parents.begin(), parents.end(), 0); 
        std::vector<int> ranks(n, 0);
        int count = n;
        std::sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        for(const auto& edge: edges){
            if(Union(parents, ranks, edge[0], edge[1])){
                --count;
            }
            if(count == k){
                return edge[2];
            }
        }
        return 0;
    }
    int Find(vector<int>& parents, int i){
        // if(parents[i] != i){
        //     parents[i] =  Find(parents, parents[i]);
        // }
        // return parents[i];
        if(parents[i] == -1){
            return i;
        }
        return parents[i] =  Find(parents, parents[i]);
    }
    bool Union(vector<int>& parents, vector<int>& ranks, int x, int y){
        int rootX = Find(parents, x);
        int rootY = Find(parents, y);
        if(rootX == rootY){
            return false;
        }
        if(ranks[rootX] > ranks[rootY]){
            parents[rootY] = rootX;
        }else if(ranks[rootX] < ranks[rootY]){
            parents[rootX] = rootY;
        }else{
            parents[rootX] = rootY;
            ranks[rootY]++;
        }

        return true;
    }
};
