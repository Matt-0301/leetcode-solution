class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::vector<int> parents(n, -1);
        std::vector<int> ranks(n, -1);
        int count = n;
        for(const auto& edge: edges){
            if(!Union(parents, ranks, edge[0], edge[1])){
                return false;
            }
            --count;
        }
        if(count != 1)  return false;
        return true;
    }
    int Find(vector<int>& parents, int i){
        if(parents[i] == -1){
            return i;
        }
        return parents[i] = Find(parents, parents[i]);
    }

    bool Union(vector<int>& parents, vector<int>& ranks, int x, int y){
        int rootx = Find(parents, x);
        int rooty = Find(parents, y);

        if(rootx == rooty)  return false;

        if(ranks[rootx] > ranks[rooty]){
            parents[rooty] = rootx;
        }else if(ranks[rootx] < ranks[rooty]){
            parents[rootx] = rooty;
        }else{
            parents[rooty] = rootx;
            ++ranks[rootx];
        }

        return true;
    }
};

