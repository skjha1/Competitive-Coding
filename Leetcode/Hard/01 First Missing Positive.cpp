class Solution
{
public:
    int firstMissingPositive(vector<int>nums)
    {
        int n=nums.size(); // size of the vector 
        for(int i = 0; i < nums.size();  i++) // iterating through the nums
            // checking the underflow and the overflow condition then 
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[abs(nums[i] - 1)] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        
        for(int i = 0; i < n;  i++)
            if(nums[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};
