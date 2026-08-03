class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lst;
        vector<int> startInt;
        int max_count = 0;
        for(auto num : nums){
          if(lst.count(num)){
            continue;
          };
          lst.insert(num);
        }
        for(auto i : lst){
          if(lst.count(i-1)){
            continue;
          };
          startInt.push_back(i);
        }
        for(auto i : startInt){
          int nextElement = i;
          int count = 0;
          while(true){  
            if(lst.count(nextElement)){
              nextElement++;
              count++;
            }else{
              break;
            }
            if(count> max_count){
              max_count = count;
            }
          }
        }
        return max_count;
    }
};
