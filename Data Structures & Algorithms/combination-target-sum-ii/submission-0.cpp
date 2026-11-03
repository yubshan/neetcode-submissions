class Solution {
    void backtracking(vector<int>& sortedArr, vector<int>& combination, vector<vector<int>>& result, int index , int remaining ){
        if(remaining == 0){
            result.push_back(combination);
            return;
        }

        if( index >= sortedArr.size() || sortedArr[index] > remaining ){
            return;
        }

        //inclusion of the current num
        combination.push_back(sortedArr[index]);
        backtracking(sortedArr, combination, result, index+1, remaining - sortedArr[index]);

        combination.pop_back();
        //exclusing also skip duplicate
        while( index+1 < sortedArr.size() && sortedArr[index] == sortedArr[index+1]){
            index = index +1; 
        }
        backtracking(sortedArr, combination, result, index + 1, remaining);

        return;

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result ;
        vector<int> combination;
        int index = 0;
        backtracking(candidates,combination , result, index, target );
        return result;
    }
};
