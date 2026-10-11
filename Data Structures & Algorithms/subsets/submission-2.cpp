class Solution {

public:

    void backtrack(const vector<int>& arr, vector<int>& subSet, int index,     vector<vector<int>>& result){
        //Base case 
        if(index == arr.size()){
            result.push_back(subSet);
            return;
        }
        // choice one : inclusion 
        subSet.push_back(arr[index]);
        backtrack(arr, subSet,index+1, result);
        subSet.pop_back();

        // choice two: exclusion
        backtrack(arr, subSet, index+1, result);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0 ;
        vector<int> subSet;
        vector<vector<int>> result;
        backtrack(nums, subSet, index, result);
        return result;
    }
};
