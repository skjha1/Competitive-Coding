// https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
// solution : https://uploads.disquscdn.com/images/a2bee3cd55348623b01e27c191b7dc79a53de1dabbc7a64e2619bcec6e391acb.png
// This is ratate image fron leetcode
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        // this loops are for the transpose if the matrix 
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                int temp= matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for (int i=0;i<n;i++){ // this loop is to flip the matrix horizontally
            for (int j=0;j<(n/2);j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][n-1-j];
                matrix[i][n-1-j]=temp;
            }
        }
    }
};
