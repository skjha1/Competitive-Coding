class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums(rowIndex+1,1); // create a vector more then the size(1 extra) and initialize it with 1
        for (int i=1;i<rowIndex;i++)
        {
            nums[rowIndex]=nums[0]=1;
            for (int j=i;j>0;j--)
                nums[j]= nums[j]+nums[j-1];
        }
        return nums;
    }
};

---------------------------------------------------------------------------------------------------------------
  class Solution {
public:
vector getRow(int rowIndex) {
vector nums(rowIndex+1,1); // create a vector more then the size(1 extra) and initialize it with 1
for (int i=1;i<rowIndex;i++)
{
for (int j=i;j>0;j--)
nums[j]= nums[j]+nums[j-1];
}
return nums;
}
};
