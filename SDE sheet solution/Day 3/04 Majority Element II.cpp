/*
Here what we are essentially doing is making pairs with majority element, fix a majority element increment the count till you find a different one and decrease the count for different elements. Here decreasing the count simply means, making a pair of majority and non-majority element and removing them from the array. Once the count reaches zero, make a new majority element because the deleted pairs had an equal count of majority and non-majority element. When we reach the end we will have the majority element selected due to the process we followed and since it was mentioned in the question that "You may assume that the array is non-empty and the majority element always exist in the array" we do not verify the solution. You can do if you want to in a single pass.

So, taking the idea from the basic problem we can extend it to find majority elements that appear more than n/3 times.
In this case, first we nneed to understand that there will be atmost 2 majority elements. This is pretty self explainatory if you read the question carefully.

Okay, so just like we did in the simpler version of the problem, we take two elements as the majority element and maintain their frequency counts and once we find an element that differs from the two, we decrement both the elements' counts. In this case we have to look for triplets instead of pairs. This essentially means that we form a triplet out of 2 majority and one non-majority element and remove them from the array. We repeat the process till we consider all array elements and simply verify if the elements we found are correct or not, which can be done in a single pass.

Please refer the code below and try to understand it with the explaination I provided above.
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }    
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = count2 = 0;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
        }
        if (count1 > sz/3)
            ans.push_back(num1);
        if (count2 > sz/3)
            ans.push_back(num2);
        return ans;
    }
};
