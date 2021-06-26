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
-------------------------------------------------
    
    class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
        int xor2=0;
       for (int i=0;i<n;i++)
       {
           xor1^=nums[i];  // let say array is 3,0,1 then bit1 will store  3^0^1 
           xor2^=(i+1); // this will store 1,2,3
       }
        return xor1^xor2; // a^a=0 ,so the number present both in x1 and x2 will cancel out(become zero ) and the element which is not present in x1 . i.e 2 will be returned by the function.
    }
};
