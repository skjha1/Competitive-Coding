// https://leetcode.com/problems/next-permutation/
/*This problem is similar to a few others here on getting the next bigger number with the same digits or the next permutation of a string, etc.

This is just easier since we work directly with a vector, so let's crack on!

First of all, we will create 2 support variables, our indexes i and j, respectively set to be pointing to the penultimate element and past the end of the vector.

We will then keep reducing i as long as it is non-negative and as long as it points to an element >= than the previous one.

If we were to finally end up with i == -1, it would mean that the whole vector is set in decreasing order, so no next permutation is possible, and we need to transform the array to the very first one, before leaving the function.

Now, you might just opt to sort the vector, but since we know it is already ordered, just reversing it might just save us precious computation: O(nlogn) vs. O(n) (or, rather O(n/2)) is a no brainer.

For any other value of i, we will then search with j for the very first element that is <= nums[i], which is guaranteed to be there (since all the elements before i are in decreasing order).

Once found, we will swap nums[i] and nums[j], since nums[j] is the next number to go there, and set the rest of the positions from i + 1 to be in increasing order - I guess here reversing and then using insertion sort would perform better, but I did not feel like going for that overkill just in case.

The code:*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // support variables
        int i = nums.size() - 2, j = i + 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        // edge case: already the highest permutation you can get
        if (i == -1) {
            reverse(begin(nums), end(nums));
            return;
        }
        // finding the first element > nums[i]
        while (nums[--j] <= nums[i]);
        // swapping i and j's values
        swap(nums[i], nums[j]);
        // ordering the rest
        sort(begin(nums) + i + 1, end(nums));
    }
};
