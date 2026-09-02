class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // idea is if the number range is fix which is 1 to n and array have n+1 element  which is because it include one extra duplicate so we can binary search in a range and check each element count in nums array if the count is greater than selected range then it means some where from start to that element duplicate exist because the count has been increased of that duplicate element

        int n = nums.size(); // size
        int l = 0 , h = n-1; // search space
        while(l < h){
            int mid = l + (h-l) / 2;
            int count =  0;
            for(int i = 0 ; i < n ;i++){
                if(nums[i] <= mid){
                    count++;
                }
            }

            if(count <= mid){
                l = mid + 1;
            }else{
                h = mid;
            }
        }
        return l;
    }
};


