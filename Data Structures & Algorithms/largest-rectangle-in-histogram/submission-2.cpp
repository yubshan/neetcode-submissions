class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_min(n, -1);    
        vector<int> right_min(n, n);   
        stack<int>st;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                left_min[i]= st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1  ; i>= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right_min[i] = st.top();
            }

            st.push(i);
        }
        
        for(int i = 0; i < n ; i++){
            int area = (right_min[i] - left_min[i] - 1) * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }   
};
