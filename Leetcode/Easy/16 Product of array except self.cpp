class Solution { // this is with less time 
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len,0);
        res[0]=1;
        for (int i=1;i<len;i++)
            res[i]= res[i-1]*nums[i-1];
        int right=1;
        for (int i=len-1;i>=0;i--){
            res[i]*=right;
            right*=nums[i];
        }
        return res;
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------
class Solution { // this solution is with less space 
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        vector<int> res(nums.size(),0);
        for (int i=1;i<nums.size();i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        for (int i=nums.size()-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for (int i=0;i<nums.size();i++)
        {
            res[i]=left[i]*right[i];            
        }
        return res;
    }
};
