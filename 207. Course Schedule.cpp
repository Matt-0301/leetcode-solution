class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> premap;
        for(const auto& p: prerequisites){
            premap[p[1]].push_back(p[0]);
        }

        std::unordered_set<int> visited;
        for(int i = 0; i < numCourses; i++){
            if(!DFS(premap, visited, i))    return false;
        }
        return true;
    }

    bool DFS(unordered_map<int, vector<int>>& premap, unordered_set<int>& visited, int i){
        if(visited.count(i)){
            return false;
        }
        if(premap[i].empty()){
            return true;
        }

        visited.insert(i);
        for(const auto& c: premap[i]){
            if(visited.count(c)){
                return false;
            }
            DFS(premap, visited, c);
        }
        visited.erase(i);
        premap[i].clear();

        return true;
    }
};
