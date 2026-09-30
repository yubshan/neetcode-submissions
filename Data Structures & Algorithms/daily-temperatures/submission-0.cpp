class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        int n = temperatures.size();
        for( int i =0 ; i < n ; i++){
            int j = i+1;
            while( j < n && temperatures[j] <= temperatures[i]){
                j++;
            }
            if(j < n){
                ans.push_back(j-i);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
