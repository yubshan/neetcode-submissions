class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1); 
        vector<int> suffix(n, 1);
        long product  = 1;
        for(int i = 0; i < n; i++){
            if(i != 0){
                prefix[i] = product;
            }
            product *= nums[i];
        }
        product = 1;
        for(int i = n-1 ; i >= 0 ; i--){
            if(i != n-1){
                suffix[i] = product;
            }
            product *= nums[i];
        }

        for(int i = 0 ; i < n ; i++){
            prefix[i] *= suffix[i];
        }
        return prefix;
    }
};
