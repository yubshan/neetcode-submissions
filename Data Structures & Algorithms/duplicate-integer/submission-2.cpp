class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int result = nums[0];
        for(auto i : nums){
            result ^= nums; 
        }
        if(result > 0){
            return false;
        }
        return true;
    }
};