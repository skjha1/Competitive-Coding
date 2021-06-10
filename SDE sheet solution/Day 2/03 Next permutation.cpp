/* Algorithm:
step 1: Linearly traverse given array from the end and find a number that is greater than its adjacent. Store the index of lower number in breakPoint variable. If there is no such element, reverse entire array and return.

step 2: Linearly traverse from end and this time find a number larger than nums[breakPoint]. Let's call it nums[i].

step 3: Swap nums[i] and nums[breakPoint].

step 4: Reverse the array from index breakPoint + 1 to nums.size().

Example:
Consider nums[] = [1, 3, 5, 4, 2].

Traverse from back and find a breakpoint. Here, index breakPoint = 1 and nums[breakPoint] = 3

Traverse from back and find a number larger than this. Here this number is: nums[i] = 4

Swap nums[breakPoint] and nums[i]. Value after swapping: nums[] = [1, 4, 5, 3, 2].

Reverse array from breakPoint + 1 to nums.size() i.e. these elements: [1, 4, 5, 3, 2]
Final answer = [1, 4, 2, 3, 5].
code:
*/

// find next permutation
void nextPermutation(vector<int> &nums)
{
    // initialize variable:
    int breakPoint = -1;

    // find a breakpoint:
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            breakPoint = i - 1;
            break;
        }
    }

    // if no breakpoint
    if (breakPoint < 0)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // if found a breakpoint
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > nums[breakPoint])
        {
            swap(nums[breakPoint], nums[i]);
            reverse(nums.begin() + breakPoint + 1, nums.end());
            break;
        }
    }
}