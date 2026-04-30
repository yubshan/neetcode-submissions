class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;

        for(auto &word : strs){
            vector<int>count(26,0);
            for(auto c : word){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 0 ; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            table[key].push_back(word);
        }

        vector<vector<string>> result;
        for(auto pair : table){
            result.push_back(pair.second);
        }

        return result;
    }
};
