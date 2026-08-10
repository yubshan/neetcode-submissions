class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_set<int> seen;
     int l = 0; 
     int r = 0;
     int maxlen = 0;
     while(l <= r && r < s.size()){
        while(seen.count(s[r])){
            seen.erase(s[l]);
            l++;
        }
        seen.insert(s[r]);
        maxlen = max(maxlen, r-l+1);
        r++;
     }
     return maxlen;
    }
};
