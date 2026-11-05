class Solution {
    void backtrack(vector<int>& nums, vector<int>&subset, vector<vector<int>>&result, int index){
     
        //base case
        if(index == nums.size()){
            // store ans 
            result.push_back(subset);
            return;
        }

        //include part 
        subset.push_back(nums[index]);
        backtrack(nums, subset, result, index+1);

        //exclude part with skip for duplicate
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index = index+1;
        }
        subset.pop_back();
        backtrack(nums, subset, result, index+1);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, subset, result, 0);
        return result;
    }
};
