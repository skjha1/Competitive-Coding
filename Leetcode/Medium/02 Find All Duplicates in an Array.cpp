class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> res;
        // this question is all about playing with index
        // in this 8 will be the maximum number & 1 will be min 
        for (int i=0;i<nums.size();i++)
        {
            int pos = abs(nums[i])-1;
// go to the index 4-1 = 3 i.e 7 and make 7 as negetive and so on.
// make all the element of vector as -ve after redusing 1, in order to maintain index (1 to 8)
            nums[pos]= -nums[pos]; // after subtracting that will be a valid index within this array
            if(nums[pos]>0) // if number is greater then zero
                res.push_back(abs(nums[i])); // keep that indeth element in the array 
        }
        return res;
    }
};
