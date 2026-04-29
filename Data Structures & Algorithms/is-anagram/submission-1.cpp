class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> freq;

        for(auto i : s){
            freq[i]++;
        }

        for(auto i : t){
            freq[i]--;
        }

        for(auto [c, frequency]: freq){
            if(frequency != 0) return false;
        }
        return true;
    }
};
