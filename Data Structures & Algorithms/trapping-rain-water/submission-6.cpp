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
            if(height[l] <= height[r]){
                max_left = max(height[l], max_left);
                int capacity = max_left - height[l];
                ans += capacity;
                l++; 
            }else{
                max_right = max(height[r], max_right);
                int capacity = max_right - height[r];
                ans += capacity;
                r--;
            }
           
        }
        return ans;
    }
};
