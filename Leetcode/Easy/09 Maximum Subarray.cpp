class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       if (nums.size()==0) return 0;
        int max_sum= nums[0];
        int sum_inc_cur = nums[0];
        for (int i=1;i<nums.size();i++)
        {
            sum_inc_cur=max(sum_inc_cur+nums[i],nums[i]);
            max_sum=max(max_sum,sum_inc_cur);
        }
        return max_sum;
    }
};
