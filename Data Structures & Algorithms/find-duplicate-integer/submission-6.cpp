class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       if(nums.empty()){
            return -1;
       }
       int slow = nums[0];
       int fast = nums[0];

       while( true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow){
                break;
            }
       }
       fast = nums[0];
       while( fast != slow){
            slow = nums[slow];
            fast = nums[fast];
       }
       return fast;
    }
};


