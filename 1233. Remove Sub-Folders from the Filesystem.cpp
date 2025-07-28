class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        std::unordered_set<string> set;
        std::vector<string> res;
        std::sort(folder.begin(), folder.end());

        for(const auto& path: folder){
            string tmp = "";
            bool sub = false;
            for(const auto& ch: path){
                if(ch == '/' && set.count(tmp)){
                    sub = true;
                    break;
                }
                tmp += ch;
            }
            if(!sub){
                set.insert(path);
                res.push_back(path);
            }
        }

        return res;
    }
};
