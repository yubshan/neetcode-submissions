class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        vector<vector<string>>result;
        unordered_map<string, vector<string>> table;
        for(int i = 0 ; i < strs.size(); i++){
            sort(temp[i].begin(), temp[i].end());
            table[temp[i]].push_back(strs[i]);
        } 
        for(auto [key, value] : table){
            vector<string>arr;
            for(auto word : value){
                arr.push_back(word);
            }
            result.push_back(arr);
        }
        for(auto arr : result){
            for(auto word : arr ){
                cout << word << ', ';
            }
        }
        return result;

    }
};
