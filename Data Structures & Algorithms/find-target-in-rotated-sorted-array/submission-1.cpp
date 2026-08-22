class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       int l = 0, r= n-1;
       while(l <= r){
            int mid = l + (r-l)/2;
            if(target == nums[mid]) return mid;
            if(nums[l] <= nums[mid]){
                //left side
                if(target > nums[mid] || target < nums[l] ){
                    l = mid +1;
                }else{
                    r = mid -1;
                }
            }else{
                //right side
                if(target < nums[mid] || target > nums[r]){
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }
       }
       return -1;
    }
};
