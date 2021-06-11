class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); //     numbers of the row 
        int m=matrix[0].size(); // numbers of the column
        int i=0; // keep i at starting of the matrix. 
        int j=m-1; // keep j on the right most top corner.
        if (!matrix.size()) return false;
        while ((i>=0 && i<n) && (j>=0 && j<=m)){ // as long as i & j is not going out of the bound 
            if (matrix[i][j]==target)
                return true;
            else if (matrix[i][j]>target)
                j--; // move to left 
            else if(matrix[i][j]<target)
                i++; // move to bottom
        }
        return false;
    }
};