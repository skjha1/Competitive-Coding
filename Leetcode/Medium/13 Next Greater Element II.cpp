// https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v; // creating a vector to store result 
        int n= nums.size(); // size of arrray
        stack<int> s; // creating a stack 
        for (int i=n-1;i>=0;i--)
        {
            s.push(nums[i]); // take elements in the stack from array 
        }
        for (int i=n-1;i>=0;i--) 
        {
            if (s.size()==0) // when stack size is empty there is no element in stack return output as -1;
                v.push_back(-1);
            else if (s.size()>0 && s.top()>nums[i])// when there is element in stack and stack top is greater then array element 
                v.push_back(s.top()); // take stack top in the result vector 
            else if (s.size()>0 && s.top()<= nums[i]) //  when there is element in stack and that element is less then array element 
            {
                while (s.size()>0 && s.top() <= nums[i])// upto when there is element and stack top is less then array's element delete the element from stack
                    s.pop();// delete the element from stack
                if (s.size()==0)
                    v.push_back(-1); // when stack became empty return -1
                else
                    v.push_back(s.top());// else push stack top in the vector 
            }
            s.push(nums[i]);// push array in stack
        }
        reverse(v.begin(),v.end()); // while returning reverse the vector and return it.
        return v;
    }
};
