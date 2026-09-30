class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        for(int i = 0 ; i < s.size(); i++){
            unordered_set<int> seen;
            int count = 1;
            for(int j = i+1; j < s.size(); j++){
                if(s[i] == s[j] || seen.count(s[j])){
                    break;
                }
                count++;
                seen.insert(s[j]);
            }
            maxlen= max(maxlen, count);
        }
        return maxlen;
    }
};
