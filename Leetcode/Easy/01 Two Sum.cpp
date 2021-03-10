#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoSumAns;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[i] + nums[j] == target) {
                    twoSumAns.push_back(i);
                    twoSumAns.push_back(j);
                }
            }
        }
        return twoSumAns;
    }
};

void PrintVector(vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
       vector<int> nums = {2,7,11,15};
        int Sum = 9;
  /*  vector<int> nums = { 3,2,4 };
    int Sum = 6;*/
    vector<int> result = solution.twoSum(nums, Sum);
    PrintVector(result);
}



-----------------------------------------------------------------------------------------------------------------------
    
    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num1; // make a variable for finding the element
        for (int i = 0; i < nums.size(); i++)  // iterate through the vector 
        {
            num1 = target - nums[i]; // we will get the 2nd item to bve find 
            for (int k = i+1; k < nums.size(); k++ ) // for finding the position 
            {
                 if(nums[k] == num1)
                 {
                     return {i,k}; // just take both the subscript 
                 }
            }
        }
        return {};
    }
};
