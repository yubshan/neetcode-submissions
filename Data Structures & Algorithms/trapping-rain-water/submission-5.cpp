class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int max_left = 0;
        int max_right = 0;
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l < r){
            max_left = max(height[l], max_left);
            max_right = max(height[r], max_right);
            int min_height = min(max_left, max_right);
            int i = 0;
            if(height[l] <= height[r]){
                i = height[l];
                int capacity = min_height - height[l];
                ans += capacity;
                l++; 
            }else{
                i = height[r];
                int capacity = min_height - height[r];
                ans += capacity;
                r--;
            }
           
        }
        return ans;
    }
};
