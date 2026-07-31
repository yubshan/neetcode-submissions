class Solution {
public:

    string encode(vector<string>& strs) {
      string ans; 
      for(auto s : strs){
        ans += to_string(s.size()) + '#' + s;
      }
      return ans;
    }

    vector<string> decode(string s) {
      vector<string> result;
      int len = 0;
      string word;
      int i = 0;
      while(i < s.size()){
        if(s[i] == '#'){
          int start = i+1;
          word = s.substr(start, len);
          int next = start + len;
          result.push_back(word);
          word.clear();
          len = 0;
          i = next;
        }else{
          len = len * 10 +  (s[i] - '0');
          i++;
        }
      }
      return result;
    }
};
