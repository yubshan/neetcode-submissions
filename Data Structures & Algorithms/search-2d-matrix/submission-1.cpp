class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int row_left = 0 ; 
        int row_right = n-1;




        while(row_left <= row_right){
            int row_mid = (row_left + row_right) / 2;
            int col_left = 0;
            int col_right = matrix[0].size()-1;
            int col_mid = 0;
            while(col_left <= col_right){
                col_mid = (col_left + col_right) /2;
                if(matrix[row_mid][col_mid] == target) {
                    return true;
                }else if(matrix[row_mid][col_mid] < target){
                    col_left = col_mid + 1;
                }else{
                    col_right = col_mid  - 1;
                }
            }
            if(matrix[row_mid][col_mid]  < target){
                row_left = row_mid + 1;
            }else if(matrix[row_mid][col_mid] > target){
                row_right = row_mid -1;
            }
        }
        return false;
    }
};
