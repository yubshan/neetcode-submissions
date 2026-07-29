class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> table;
      for(auto &s: strs){
        string key = s;
        sort(key.begin(), key.end());
        table[key].push_back(s);
      };
      vector<vector<string>>result;
      for(auto& pr: table){
        result.push_back(pr.second);
      }
      return result;
    }
};
