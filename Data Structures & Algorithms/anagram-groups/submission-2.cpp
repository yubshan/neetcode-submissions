class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<char, int> freq;
        for(auto word: strs){
            sort(word.begin(), word.end());
        }
        for(auto word : strs){
            cout << word<< ", ";
        }
        return result;
    }
};
