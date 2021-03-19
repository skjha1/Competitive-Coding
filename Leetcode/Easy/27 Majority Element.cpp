class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // if you can see highest frequency will always be in the middle of the list ater sorting 
        
        int middle=(nums.size())/2;  
        // We don't need to sort the whole list, just need to pinpoint the number at the mid position.
        nth_element(nums.begin(),nums.begin()+middle,nums.end());
        return nums[middle];
    }
};
