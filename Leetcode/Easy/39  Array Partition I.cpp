// https://leetcode.com/problems/array-partition-i/
class Solution {
public:
  
    int arrayPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	size_t sum = 0;
	for(int i = 0; i < len; i+=2)
		sum += nums[i];
	return sum;
}
    
};
