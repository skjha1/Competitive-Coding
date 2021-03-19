class Solution {
public:
    int missingNumber(vector<int>& nums) { // creating the variable by the name of nums as a vector  
    int result = 0;
    for (int i = 0; i < nums.size(); i++) { // iterating through the vector 
        result =result + (i+1)- nums[i];  // getting the missing number and then returning it 
    }
    return result;
}
};
