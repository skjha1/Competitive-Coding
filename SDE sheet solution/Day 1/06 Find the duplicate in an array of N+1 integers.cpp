/* 

1.Take two pointers (basically integers) namely, slow and fast. Initially both will point to first element
2.Increase slow by 1 and fast by two.
3.Step 2 will be done as follows: slow = nums[slow]; fast = nums[nums[fast]].
4.There will be one time when slow and fast will meet. They will meet in a cycle.
5.At step 4 we have to stop.
6.Now move fast to initial position i.e. fast = nums[0].
7.Now move both slow and fast by one position till both of them meet.
8.Step 7 increment will be done as follows: slow = nums[slow]; fast = nums[fast].
9.The node at which both slow and fast will meet will be the duplicate number.
10Return slow or fast.

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};