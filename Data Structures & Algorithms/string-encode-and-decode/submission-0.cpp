class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(auto word : strs){
            result +=(to_string(word.size())+ '#'+ word );
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int length =0;
        int i = 0 ; 
        while ( i < s.size()){
           int j = i;
           while(s[j] != '#'){
            j++;
           }
           int length = stoi(s.substr(i, j-i));
           i = j+1;
           j = i + length;
           result.push_back(s.substr(i, length));
           i = j;
        }
        return result;
    }   
};
