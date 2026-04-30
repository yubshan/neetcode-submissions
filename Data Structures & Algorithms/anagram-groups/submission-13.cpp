class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> table;
       for(auto &word: strs){
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        table[sortedWord].push_back(word);
       }
       vector<vector <string>>result;
       for(auto pair : table){
        result.push_back(pair.second);
       }
       return result;

    }
};
