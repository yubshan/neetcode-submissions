class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                return mid;
            }else if(nums[r] >= target && nums[l]> target){
                //rigth side sort
                l = mid + 1;
            }else if(nums[l] <= target && nums[r] < target){
                // left side sort
                r = mid - 1;
            }else if(nums[r] >= target && nums[l] <= target){
                // in the sorted aray
                if(nums[mid] > target){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
