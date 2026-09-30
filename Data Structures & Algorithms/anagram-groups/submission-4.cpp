class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<char, int> freq;
        for(auto & word: strs){
            sort(word.begin(), word.end());
        }
        if(strs[0] == strs[3]) cout << "true";
        
        return result;
    }
};
