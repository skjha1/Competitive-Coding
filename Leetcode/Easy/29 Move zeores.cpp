class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero_index=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]!=0){
                int temp=nums[i];
                nums[i]=nums[non_zero_index];
                nums[non_zero_index]=temp;
                non_zero_index++;
            }
        }
    }
};
