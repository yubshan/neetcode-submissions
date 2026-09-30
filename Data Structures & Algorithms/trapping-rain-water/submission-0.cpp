class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for(int i = 0 ; i < height.size(); i++){
            int max_left = height[i];
            int max_right = height[i];
            int l  = i ;
            int r = i;
            while( l >= 0 &&  r < height.size()){
               max_left = max(max_left, height[l]);
               max_right = max (max_right, height[r]);
               l--;
               r++;
            }
            int min_height = min(max_left, max_right);
            int capacity = min_height - height[i];
            ans += capacity;
        }
        return ans;
    }
};
