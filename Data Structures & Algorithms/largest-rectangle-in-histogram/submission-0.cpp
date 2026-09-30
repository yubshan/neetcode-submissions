class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxHeight = INT_MIN;
        int minHeight = INT_MAX;
        int ans = 0;
        for(auto h: heights){
            maxHeight = max(maxHeight, h);
            minHeight = min(minHeight, h);
        }
        

        for(int i = 0 ; i <  n; i++){
            int area = 0;
            for(int j = 0 ; j < n ; j++){
                if(heights[j] >= heights[i]){
                    area += heights[i];
                }else{
                    area = 0;
                }
            }
            ans = max(ans , area);
        }

        ans = max(maxHeight , ans);
        return ans;      
    }
};
