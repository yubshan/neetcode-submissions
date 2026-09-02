class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //   fliping the input array for seen number 
        for(auto n : nums){
            int idx = abs(n) - 1;
            if(nums[idx] < 0) {
                return abs(n);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};
