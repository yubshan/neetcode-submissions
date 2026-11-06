class Solution {
    void backtrack(int n, int openCount, int closeCount, string &combination,  vector<string>& result){
        if(openCount == n && closeCount == n){
            result.push_back(combination);
            return;
        }
        if(openCount < n) {
            combination.push_back('(');
            backtrack(n, openCount + 1, closeCount, combination, result);
            combination.pop_back();
        }

        if(closeCount < openCount) {
            combination.push_back(')');
            backtrack(n, openCount, closeCount + 1, combination, result);
            combination.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string s;
        backtrack(n, 0, 0, s, result);
        return result;
    }
};
