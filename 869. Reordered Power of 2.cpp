class Solution {
public:
    bool reorderedPowerOf2(int n) {
        std::unordered_set<string> table;
        createTable(table);
        string res = to_string(n);
        std::sort(res.begin(), res.end());
        
        return table.count(res) ? true : false;
    }

    void createTable(unordered_set<string>& table){
        int n = 0;
        string tmp;
        while((int)pow(2, n) <= 1e9){
            tmp = to_string((int)pow(2, n));
            std::sort(tmp.begin(), tmp.end());
            // cout << tmp << endl;
            table.insert(tmp);
            ++n;
        }
    }
};
