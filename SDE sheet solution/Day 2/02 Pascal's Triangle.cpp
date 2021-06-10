class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> m(numRows);// creating 2-D vector with rows=numRows
        
            for(int i=0;i<numRows;i++)
            {
                m[i].resize(i + 1);    //to increase column size as level increases
                m[i][0] = m[i][i] = 1; //first and last element of every row is 1 always so

                //loop to calculate sum of remaining elements from previous row  
                for (int j = 1; j < i; j++)
                   m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
        
            }
        return m;
    }
};