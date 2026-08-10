class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> count(26, 0);

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            count[s[r] - 'A']++;

            int maxFreq = 0;

            for (int i = 0; i < 26; i++) {
                maxFreq = max(maxFreq, count[i]);
            }

            while ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;

                // recalculate because the window changed
                maxFreq = 0;
                for (int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, count[i]);
                }
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};