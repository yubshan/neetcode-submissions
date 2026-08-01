class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int len = nums.size();
      vector<int> left(len, 1);
      vector<int> right(len, 1);

      //left product
      for(int i = 1; i < len ; i++){
        left[i] = nums[i-1] * left[i -1];
      }
     
     
      //right product
      for(int i = len-2; i >=0  ; i--){
        right[i] = nums[i+1] * right[i+1];
      }

      for(int i = 0 ; i < left.size(); i++){
        left[i] = left[i] * right[i];
      }
      return left;
    }
};
