class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lst;
        int max_count = 0;
        for(auto num : nums){
          if(lst.count(num)){
            continue;
          };
          lst.insert(num);
        }
        for(auto i : lst){
          if(lst.find(i-1) == lst.end() ){
            int nextElement = i;
            int count = 0;
            while(lst.count(nextElement)){  
                nextElement++;
                count++;
            }
            if(count> max_count){
                max_count = count;
              }
          }
        }
        return max_count;
    }
};
