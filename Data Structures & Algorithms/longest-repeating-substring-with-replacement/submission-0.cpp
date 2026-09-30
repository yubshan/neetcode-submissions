class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        for(int i =0 ; i < s.size(); i++){
            int lives = k;
            int j;
            for(j = i ; j < s.size(); j++){
                if(s[i] != s[j]){
                    if(lives > 0){
                        lives--;
                        continue;
                    }
                    break;
                }
            }
            maxlen = max(maxlen, j-i);
        }
        return maxlen;
    }
};
