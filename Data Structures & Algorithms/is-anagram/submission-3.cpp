class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        if(s.size() != t.size()) return false;
        for(auto c : s){
            freq[c]++;
        };
        for(auto c : t){
            freq[c]--;
        };
        for (auto i : freq){
            if(i.second > 0) return false;
        };
        return true;
    }
};
