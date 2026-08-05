class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans_index;
        int i = 0; 
        int j = 0;
        int sum = 0;
        while(i < numbers.size()){
          j = i+1;
          while(j <  numbers.size()){
            sum = numbers[i] + numbers[j];
            if(sum == target){
              ans_index.push_back(i+1);
              ans_index.push_back(j+1);
              return ans_index;
            }
            j++;
          }
          i++;
        }
        return ans_index;
    }
};
