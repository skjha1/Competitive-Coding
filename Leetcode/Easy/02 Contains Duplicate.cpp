class Solution { 
public:
      
bool containsDuplicate(vector<int>& nums) // creating a vector varible nums 
    {
       sort(nums.begin(), nums.end()); // sorting the vector 
       int n = nums.size(); // storing the size of the vector in n 
       
       for(int i = 1; i < n; i++) // iterating through the whole vector 
       {
           if(nums[i] == nums[i-1]) // if duplicate found then return true else return false 
           return true;
       }
       
       return false;
    }
};
