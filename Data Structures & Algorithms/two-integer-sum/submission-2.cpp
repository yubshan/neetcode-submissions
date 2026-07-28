class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> result;
        int diff = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(seen.find(nums[i]) != seen.end()){
                result.push_back(seen[nums[i]]);
                result.push_back(i);
                return result;
            }else{
                diff = target - nums[i];
                seen[diff] = i;
            };
        };
        return result;
    }
};
