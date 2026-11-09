class Solution {
    bool isPali(string s , int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void backtrack(string s, int i , vector<string> &part, vector<vector<string>>& result ){
        if(i >= s.length()){
            result.push_back(part);
            return;
        }
        for(int j = i ; j < s.length(); j++){
            if(isPali(s, i, j)){
                part.push_back(s.substr(i, j-i+1));
                backtrack(s, j+1, part, result);
                part.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;
        backtrack(s, 0, part, result);
        return result;
    }
};
