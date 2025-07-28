class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        std::map<string, vector<string>> map;
        const std::set<string> categories = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(int i = 0; i < code.size(); i++){
            if(code[i].size() == 0 || !checkString(code[i]))
                continue;
            if(!categories.count(businessLine[i]))
                continue;
            if(!isActive[i])
                continue;

            map[businessLine[i]].push_back(code[i]);
        }
        vector<string> res;
        std::sort(map["electronics"].begin(), map["electronics"].end());
        std::sort(map["grocery"].begin(), map["grocery"].end());
        std::sort(map["pharmacy"].begin(), map["pharmacy"].end());
        std::sort(map["restaurant"].begin(), map["restaurant"].end());

        res.insert(res.end(), map["electronics"].begin(), map["electronics"].end());
        res.insert(res.end(), map["grocery"].begin(), map["grocery"].end());
        res.insert(res.end(), map["pharmacy"].begin(), map["pharmacy"].end());
        res.insert(res.end(), map["restaurant"].begin(), map["restaurant"].end());

        return res;
    }

    bool checkString(string s){
        for(const auto& ch: s){
            if(!isalnum(ch) && ch != '_'){
                return false;
            }
        }

        return true;
    }
};
