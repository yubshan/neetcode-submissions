class Solution {
    void backtrack(vector<int>& nums, vector<int>&combination, vector<vector<int>>& result, vector<bool>used){
        if (combination.size() == nums.size()) {
            result.push_back(combination);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) {
                continue;
            }

            used[i] = true;
            combination.push_back(nums[i]);

            backtrack(nums, combination, result, used);

            combination.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>combination;
        vector<bool>used(nums.size(), false);
        backtrack(nums, combination, result, used);
        return result;
    }
};
