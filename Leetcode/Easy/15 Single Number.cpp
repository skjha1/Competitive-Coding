class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for (int i=0;i<nums.size();++i)
        {
            res= res^ nums[i]; // takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.
        }
        return res;
        
    }
};
----------------------------------------------------------------------------------------------

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int>s;
        for(int i=0;i<nums.size();i++){
            if(!s.empty()){
                if(s.top()==nums[i]){
                    s.pop();
                }else{
                    s.push(nums[i]);
                }
            }else{
                s.push(nums[i]);
            }
        }
        int ans= s.top();
        return ans;
    }
};
