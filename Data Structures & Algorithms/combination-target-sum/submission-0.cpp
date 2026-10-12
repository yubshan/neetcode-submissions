
class Solution {
public:
    void backtrack(vector<int>& nums,
                   vector<int>& combination,
                   int remaining,
                   int index,
                   vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(combination);
            return;
        }

        if (index == nums.size()) {
            return;
        }

        // If this candidate is too large, all later
        // candidates are too large because nums is sorted.
        if (nums[index] > remaining) {
            return;
        }

        // Include: same index, because reuse is allowed.
        combination.push_back(nums[index]);
        backtrack(nums, combination, remaining - nums[index],
                  index, result);
        combination.pop_back();

        // Exclude: move to the next candidate.
        backtrack(nums, combination, remaining,
                  index + 1, result);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> combination;

        backtrack(nums, combination, target, 0, result);
        return result;
    }
};