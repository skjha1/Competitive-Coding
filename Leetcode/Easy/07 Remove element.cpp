class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()==0) return 0;
        int returned_size=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]!=val) // if element is not equal to value we want to delete 
            {
                nums[returned_size++]=nums[i];
            }
        }
        return returned_size;
    }
};
// https://leetcode.com/problems/remove-element/
