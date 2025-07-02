class Solution {
public:
    std::map<char, string> hash_map;
    char symbol = 0;
    string encode(vector<string>& strs) {
        string encode;
        for(const auto& str: strs){
            hash_map[symbol] = str;
            encode += symbol;
            symbol++;
        }
        return encode;
    }

    vector<string> decode(string s) {
        std::vector<string> decode;
        for(const auto& ch: s){
            decode.push_back(hash_map[ch]);
        }

        return decode;
    }
};

