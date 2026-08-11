class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(auto c : s1){
            freq1[ c -'a']++;
        };
        int m = s1.size();
        int l = 0;
        int r = 0;
        for( r = 0 ;r< m ; r++){
            freq2[s2[r] - 'a']++;
        }
        if(freq1 == freq2) return true;

        for( r  = m ; r < s2.size() ; r++ ){
            freq2[s2[l] - 'a'] --;
            freq2[s2[r] - 'a']++;
            if(freq1 == freq2) return true;
            l++;
        }
        return false;
    }
};
