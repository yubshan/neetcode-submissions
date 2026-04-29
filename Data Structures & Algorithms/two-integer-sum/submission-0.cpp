class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        unordered_map<int, int> index; 
        for(int i = 0 ; i < nums.size() ; i++){
            int diff = target - nums[i];
            if(index.find(diff) != index.end() )
            {
                result.push_back(index[diff]);
                result.push_back(i);
                return result;
            }
            index[nums[i]] = i;
        }
        return result;
    }
};
