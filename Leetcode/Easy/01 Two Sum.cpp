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