
class Solution {
public:
    void backtrack(vector<int>& nums,
               vector<int>& combination,
               int remaining,
               int start,
               vector<vector<int>>& result) {
    if (remaining == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (nums[i] > remaining) {
            break;
        }

        combination.push_back(nums[i]);

        backtrack(nums, combination,
                  remaining - nums[i], i, result);

        combination.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> combination;

        backtrack(nums, combination, target, 0, result);
        return result;
    }
};