class Solution {
    unordered_map<int, string> freq;
  
    void backtrack(string digits, vector<string>& result, string ans, int i ){
        if( i >= digits.length()){
            result.push_back(ans);
            return;
        }
        int digit = stoi(digits.substr(i, 1));
        string chars = freq[digit];
        for(auto c : chars){
            ans.push_back(c);
            backtrack(digits, result, ans,  i+1);
            ans.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string charSet ="abcdefghijklmnopqrstuvwxyz";
        vector<string> result;
        string ans;
        int j = 0;
        for(int i = 2; i < 10; i++){
           freq[i] = ((i == 7 || i == 9) ? charSet.substr(j, 4):  charSet.substr(j, 3));
           j = (i == 7) ? j + 4 : j+3;
        }
        if(digits.empty()) return result;
        backtrack(digits, result, ans, 0);
        return result;
    }
};
