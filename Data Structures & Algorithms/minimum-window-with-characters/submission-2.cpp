class Solution {
public:
    bool validSubSet(vector<int> original, vector<int> potential) {
        for (int i = 0; i < original.size(); i++) {
            if (original[i] == 0) continue;

            if (original[i] > potential[i])
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int l = 0;
        int r = 0;

        int minWindowlen = s.size();
        string subString = "";

        vector<int> freqt(26, 0);
        vector<int> freqs(26, 0);

        for (int i = 0; i < t.size(); i++) {
            char c = tolower(t[i]);
            freqt[c - 'a']++;
        }

        while (r < s.size()) {

            char c = tolower(s[r]);
            freqs[c - 'a']++;

            while (validSubSet(freqt, freqs)) {

                string newPotentialSubString =
                    s.substr(l, r - l + 1);

                if (newPotentialSubString.size() <= minWindowlen) {
                    subString = newPotentialSubString;
                    minWindowlen = newPotentialSubString.size();
                }

                freqs[tolower(s[l]) - 'a']--;
                l++;

            } 
            r++;
        }

        return subString;
    }
};