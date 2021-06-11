class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int candidate=nums[0];
    int count =1;
    for (int i=0;i<nums.size();i++)
    {
        if (nums[i]==candidate)
            count++;
        else
            count--;
        if (count ==0)
        {
            candidate=nums[i];
            count=1;
        }
    }
    return candidate;
    }
};
-------------------------------------------------------------------------

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return nums[len / 2];
    }
};