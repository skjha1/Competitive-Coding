class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector <int>> result;
        for (int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int k= nums.size()-1;
            while (j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if (sum==0)
                    result.insert({nums[i],nums[j++],nums[k--]});
                else if (sum<0)
                    j++;
                else
                    k--;
            }
        }
        vector<vector<int>> ans;
        copy (result.begin(),result.end(),back_inserter(ans));
        return ans;
        
    }
};
