class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int n : nums){ // iterated through the nums 
            n = abs(n);
            if(nums[n-1] > 0) nums[n-1] *= -1; // if it is greater than zero i.e we are reaching for the 1st time 
            // since we negeted the values everytime so when duplicate will come it will become +ve & we will push back in vector
            else result.push_back(n); // if this is negetive i.e we are reaching here for the second time so take that duplicate value 
        }
        return result;
    }
};

---------------------------------------------


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> res;
        // this question is all about playing with index
        // in this 8 will be the maximum number & 1 will be min 
        for (int i=0;i<nums.size();i++)
        {   // [4,3,2,7,8,2,3,1]
            int pos = abs(nums[i])-1;
            // [3,2,1,6,7,1,2,0]
// go to the index 4-1 = 3 i.e 7 and make 7 as negetive and so on.
// make all the element of vector as -ve after redusing 1, in order to maintain index (1 to 8)
            nums[pos]= -nums[pos]; // after subtracting that will be a valid index within this array
          
            if(nums[pos]>0) //now those which number is greater then zero take that in vector
                
                res.push_back(abs(nums[i])); // keep that indeth element in the array 
        }
        return res;
    }
};
