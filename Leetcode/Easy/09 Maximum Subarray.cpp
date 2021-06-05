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
--------------------------------------------------------------------------------------------
    
    class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for (auto i:nums)
        {
            sum+=i;
            maxi=max(maxi,sum); // everytime take maximum after adding the next element 
            if (sum<0) sum=0; // whenever sum become less then 0 set its value to zero 
        }
        return maxi;
    }
};
// tc sc =O(n), O(1)
