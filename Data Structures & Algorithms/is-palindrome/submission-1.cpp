  class Solution {
  public:
      bool isAlphaNumeric(char c){
        if(c >= '0' && c <= '9' ||
          c >= 'a' && c <= 'z' ||
          c >= 'A' && c <= 'Z' ){
            return true;
        }else{
          return false;
        }
      }

      bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(j > i){
          while( i < j && !isAlphaNumeric(s[i])){
            i++;
          }
          while(i < j && !isAlphaNumeric(s[j])){
            j--;
          }
          if(tolower(s[i]) != tolower(s[j])){
            return false;
          }
          i++, j--;
        }
      return true;
      }
  };
