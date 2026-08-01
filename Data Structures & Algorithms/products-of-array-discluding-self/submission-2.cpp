class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int len = nums.size();
      vector<int> left(len, 1);
      vector<int> right(len, 1);
      int product = 1;
      //left product
      for(int i = len-1; i >= 0 ; i--){
        for(int j = (i - 1); j >= 0 ; j-- ){
          product *= nums[j];
        }
        left[i] = product;
        product = 1;
      }
     
     
      //right product
      for(int i = 0; i < len ; i++){
        for(int j = (i + 1); j < len ; j++ ){
          product *= nums[j];
        }
        right[i] = product;
        product = 1;
      }

      for(int i = 0 ; i < left.size(); i++){
        left[i] = left[i] * right[i];
      }
      return left;
    }
};
