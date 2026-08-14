class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c == ')' || c == '}' || c == ']'){
                if(st.empty()) return false;
                char tos = st.top();
                if(c == ')' && tos != '('){
                    return false;
                }else if(c == '}' && tos != '{'){
                    return false;
                }else if(c == ']' && tos != '['){
                    return false;
                }
                st.pop();
            }else{
                st.push(c);
            }
        }
        if(st.empty()) return true;
        else return  false;
    }
};
