class Solution {
public:
    int evalRPN(vector<string>& ss) {

        stack<int> st;

        for (auto s : ss) {

            if (s == "+" ||
                s == "-" ||
                s == "*" ||
                s == "/") {

                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                int result;

                if (s == "+")
                    result = num1 + num2;
                else if (s == "-")
                    result = num1 - num2;
                else if (s == "*")
                    result = num1 * num2;
                else
                    result = num1 / num2;

                st.push(result);

            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};