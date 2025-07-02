class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::unordered_map<string, int> map;
        std::vector<int> result;
        for(const auto& word: words){
            map[word]++;
        }
        int word_size = words[0].size();
        int cat_size = word_size * words.size();
        if(cat_size > s.size())    return result;

        bool flag;
        for(int m = 0; m < word_size; m++){
            flag = false;
            for(int i = m; i <= s.size() - cat_size; i+= word_size){
                if(flag){
                    string tmp1 = s.substr(i-word_size, word_size);
                    string tmp2 = s.substr(i + cat_size - word_size, word_size);
                    cout << tmp1 << ", " << tmp2 << endl;
                    if(tmp1 == tmp2){
                        result.push_back(i);
                    }else{
                        flag = false;
                    }
                }else{
                    if(check_substring(map, s, i, cat_size, word_size) == true){
                        result.push_back(i);
                        flag = true;
                    }else{
                        flag =false;
                    }
                }

            }
        }

        return result;
    }

    bool check_substring(std::unordered_map<string, int> map, string &s,int i, int cat_size, int word_size){
        for(int j = i; j < i + cat_size; j+= word_size){
            string tmp = s.substr(j, word_size);
            if(map.find(tmp) != map.end() && map[tmp] > 0){
                map[tmp]--;
            }else{
                return false;
            }
        }
        return true;
    }

};
