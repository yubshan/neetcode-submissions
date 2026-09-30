class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> table;
        vector<string> temp = strs;
        for(auto & word: temp){
            sort(word.begin(), word.end());
        }
        for(int i = 0 ; i< temp.size(); i++){
                table[temp[i]].push_back(strs[i]);
        }
        for (auto index : table){
            cout << index << endl;

        }
        return result;
    }
};
