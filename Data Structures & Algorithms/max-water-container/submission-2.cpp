class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int l =0 ;
        int r = heights.size() - 1;
        while(l <= r){
            int h = min(heights[l], heights[r]);
            int width = r-l;
            int area = h*width;
            max_area = max(area, max_area);
            if(heights[l] <= heights[r]) l++;
            else r--;
        } 
        return max_area;
    }
};
