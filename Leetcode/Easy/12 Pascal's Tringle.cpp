class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> nums(numRows);
        for (int  i=0;i<numRows;i++)
        {
            nums[i].resize(i+1); // everytime resize the array
            nums[i][0]=nums[i][i]=1; // the 1st and the last element will always will be 1
            for (int j=1;j<i;j++) 
            {
                nums[i][j]=nums[i-1][j-1]+nums[i-1][j]; 
            }
        }
        return nums;
    }
};
