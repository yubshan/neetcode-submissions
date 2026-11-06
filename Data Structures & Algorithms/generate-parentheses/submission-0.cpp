class Solution {
    void backtrack(int n, int openCount, int closeCount, string &combination,  vector<string>& result){
        if(openCount == n && closeCount == n){
            result.push_back(combination);
            return;
        }
        if(openCount == n){
            // don't have choice.
            combination.push_back(')');
            backtrack( n, openCount,  closeCount + 1, combination, result);
            combination.pop_back();
        }else if(openCount > closeCount){
            // have choice
            // include part with ")"
            combination.push_back(')');
            backtrack( n, openCount,  closeCount + 1, combination, result);
            //exclude part with "("
            combination.pop_back();
            combination.push_back('(');
            backtrack( n, openCount + 1,  closeCount, combination, result);
            combination.pop_back();
        }else{
            //don't have choice 
            combination.push_back('(');
            backtrack( n, openCount + 1,  closeCount, combination, result);
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
