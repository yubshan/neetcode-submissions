class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while( l <= r && r < s.size()){
            if(seen.find(s[r]) != seen.end()){
                l = max(seen[s[r]]+1, l);
            }
            seen[s[r]] = r;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
