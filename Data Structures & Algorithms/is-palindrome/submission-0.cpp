class Solution {
public:
    bool isPalindrome(string s) {
      string compressed = "";
      string matching = "";
      for(int i = 0 ; i < s.size(); i++){
        if(s[i] >= '0' && s[i]<= '9' ||
           s[i] >= 'a' && s[i]<= 'z' ||
           s[i] >= 'A' && s[i]<= 'Z'){
            compressed += tolower(s[i]);
           }
      }
      for(int i = s.size() -1 ; i >= 0; i--){
        if(s[i] >= '0' && s[i]<= '9' ||
           s[i] >= 'a' && s[i]<= 'z' ||
           s[i] >= 'A' && s[i]<= 'Z'){
            matching += tolower(s[i]);
           }
      }

      if(compressed == matching){
        return true;
      }
      return false;

    }
};
