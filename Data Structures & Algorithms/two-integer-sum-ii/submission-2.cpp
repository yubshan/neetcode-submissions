class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans_index;
        int i = 0; 
        int j = numbers.size() - 1;
        int sum = 0;
        while(i < j){
            sum = numbers[i]  + numbers[j];
            if(sum < target){
                i++;
            }else if (sum > target){
                j--;
            }else{
                ans_index.push_back(i+1);
                ans_index.push_back(j+1);
                break;
            }
        }
        return ans_index;
    }
};
