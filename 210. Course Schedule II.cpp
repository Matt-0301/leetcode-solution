class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> premap;
        std::unordered_set<int> visited;
        std::unordered_set<int> finished;

        for(const auto& p: prerequisites){
            premap[p[0]].push_back(p[1]);
        }

        std::vector<int> res;
        for(int i = 0; i < numCourses; i++){
            if(!DFS(premap, visited, finished, i, res))   return vector<int>();
        }

        return res;
    }

    bool DFS(unordered_map<int, vector<int>>& premap, unordered_set<int>& visited, \
            unordered_set<int>& finished, int i, vector<int>& result){
        if(visited.count(i))  return false;
        if(premap[i].empty()){
            if(!finished.count(i)){
                finished.insert(i);
                result.push_back(i);
            }
            return true;
        }

        visited.insert(i);
        for(const auto& p: premap[i]){
            if(!DFS(premap, visited, finished, p, result))    return false;
        }
        visited.erase(i);
        premap[i].clear();
        finished.insert(i);
        result.push_back(i);

        return true;
    }
};
