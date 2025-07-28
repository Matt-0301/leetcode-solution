class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool hasVowel = false, hasConsonant = false;
        std::set<char> set({'a', 'e', 'i', 'o', 'u'});
        for(const auto& ch: word){
            if(!isalnum(ch))    return false;
            if(isalpha(ch)){
                if(!hasVowel && set.count(tolower(ch)))  hasVowel = true;
                if(!hasConsonant && !set.count(tolower(ch)))  hasConsonant = true;
            }

        }

        if(hasVowel && hasConsonant)    return true;
        return false;
    }
};
