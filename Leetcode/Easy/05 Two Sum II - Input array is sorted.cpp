class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res; 
       int left=0,right=numbers.size()-1;
        while (left<right){
            int l=numbers[left];
            int r=numbers[right];
            if (l+r==target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if (l+r<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};
