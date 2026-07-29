class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> table;
      for(auto &s: strs){
        vector<int> freq (26, 0);
        for(auto c : s){
            freq[c - 'a']++;
        }
        string key = to_string(freq[0]);
        for(int i = 0 ; i < 26 ; i++){
            key += "." + to_string(freq[i]);
        };
        table[key].push_back(s);
      };
      vector<vector<string>>result;
      for(auto& pr: table){
        result.push_back(pr.second);
      }
      return result;
    }
};
