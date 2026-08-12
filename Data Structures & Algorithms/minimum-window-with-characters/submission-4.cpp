class Solution {
public:
    string minWindow(string s, string t) {

        if (t.empty() || s.size() < t.size())
            return "";

        int l = 0;
        int r = 0;

        int validCharInWin = 0;

        int minSubStringLen = s.size() + 1;
        int bestStart = 0;

        unordered_map<char, int> freqt;
        unordered_map<char, int> freqs;

        for (char c : t) {
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

                int currentLen = r - l + 1;

                if (currentLen < minSubStringLen) {
                    minSubStringLen = currentLen;
                    bestStart = l;
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

        if (minSubStringLen == s.size() + 1)
            return "";

        return s.substr(bestStart, minSubStringLen);
    }
};