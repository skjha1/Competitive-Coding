class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0;  // the beginning row is set to be zero 
        int right = matrix[0].size() - 1; // this is for end of the col
        int left = 0;  // this is for column beginning 
        int bottom = matrix.size() - 1; //this is end of row
        
        while(top <= bottom && left <= right){ // row beg is less then row end && col begi is less then col end
            //top row
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]); // this will enter the 1st line [1,2,3]
            top++; // now top is at 1st row and last col(i.e at 3)
        
            //left colm
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]); // this will enter [6,9]
            right--; // now right is at last row last col(i.e at 9)
            
            //bottom row
            if(top <= bottom){
                for(int i = right; i >= left; i--) // now move from bottom right to bottom left 
                    ans.push_back(matrix[bottom][i]); // this will store [8,7]
                bottom--;// here botom is at last row 1st col (i.e at 7)
            }
            
            //right colm
            if(left <= right){      
                for(int i = bottom; i >= top; i--) // now move from left bottom to left top 
                    ans.push_back(matrix[i][left]); // now take 4 and so on ............
                left++; 
            }
        }
        return ans;
    }
};
