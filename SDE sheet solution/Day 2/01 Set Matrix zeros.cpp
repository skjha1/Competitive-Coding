/*Approach-First of all create two vectors rowmarker and columnmarker to store the positions of column and row where the element is zero.
If element in either row marker or columnmarker is 0.Then make the element in the whole matrix 0.
*/

 void setZeroes(vector<vector<int>>& matrix) {     
        int rowsize=matrix.size(); 
        int columnsize=matrix[0].size(); 
        vector<int>rowmarker(rowsize,1); // a dummy vector of size row 
        vector<int>columnmarker(columnsize,1); // adummy vector of size colunm
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++) // lineraly traverse a matrix 
            {
                if(matrix[i][j]==0) // when ever you find zero 
                {
                    rowmarker[i]=0; // set zero to column index as well as row index
                    columnmarker[j]=0;
                }
            }
        } 
        for(int i=0;i<rowsize;i++) // again linerly traverse in full matrix 
        {
            for(int j=0;j<columnsize;j++)
            {
                if(rowmarker[i]==0 or columnmarker[j]==0) // and whereever dummy vector is zero make entire row and column as zero 
                    matrix[i][j]=0;
             }
        }
        
    }
    
    -------------------------------------------------------------------------------------------------------------------
    
    class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {     
       int col0=1;
        int rows=matrix.size();
        int col=matrix[0].size();
        
        for (int i=0;i<rows;i++)
        {
            if(matrix[i][0]==0)
                col0=0;
            for (int j=1;j<col;j++)
            {
                if (matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        for (int i=rows-1;i>=0;i--)
        {
            for (int j=col-1;j>=1;j--)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            if (col0==0)
            matrix[i][0]=0;
        }
        
        
    }
};
