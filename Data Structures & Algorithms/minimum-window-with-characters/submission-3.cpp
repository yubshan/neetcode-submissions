class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int l = 0;
        int r = 0;

        int validCharInWin=0;
        string subString = "";
        int minSubStringLen= s.size();

        unordered_map<char, int> freqt;
        unordered_map<char, int> freqs;

        for (auto c : t) {
            freqt[c]++;
        }

        while (r < s.size()) {

            char c = s[r];

            if (freqt[c] > 0) {

                if (freqs[c] < freqt[c])
                    validCharInWin++;

                freqs[c]++;
            }

            while (validCharInWin == t.size()) {

                if (r - l + 1 <= minSubStringLen) {
                    subString = s.substr(l, r - l + 1);
                    minSubStringLen = r - l + 1;
                }

                char left = s[l];

                if (freqt[left] > 0) {

                    if (freqs[left] <= freqt[left])
                        validCharInWin--;

                    freqs[left]--;
                }

                l++;
            }

            r++;
        }
        return subString;
    }
    
};