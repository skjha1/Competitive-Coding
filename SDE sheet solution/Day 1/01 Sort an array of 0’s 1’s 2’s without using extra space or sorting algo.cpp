https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
// this is the variation of dutch national flag algo it states that
// all element towards the left of low will be zero
// all element towards right of high will be two
// everything between (Low and mid-1) will be one 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while (mid<=high) // we will move mid pointer untill it crosses high pointer
        {
            switch(nums[mid]){
            // In between we will be doing three checks i.e when mid is pointing to 0,1 and 2;
            case 0://1st mid is pointing to zero // then we will swap index low with the index mid and increment both (low &mid)
            swap(nums[low],nums[mid]);
            low++;
            mid++;
            break; 
            
            
            
            case 1: // now mid is pointing to 1 // then simply move mid pointer by one 
            mid++;
            break;
            
            
            case 2:// now mid is pointing two // then we will swap index high with the index mid and decrement only high
            swap(nums[mid],nums[high]); // this time mid pointer will not be incremented 
            high--;   
            break;   
            
            }
        }
        
        
----------------------------------------------------------------------------
            class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        
        while (mid<=high)
        {
            switch(nums[mid]){
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high--]); 
                    break;
            }
        }
    }
};
        
    }
};

Complexity Analysis: 
Time Complexity: O(n). 
Only one traversal of the array is needed.
Space Complexity: O(1). 
No extra space is required.
Approach: Count the number of 0s, 1s and 2s in the given array. Then store all the 0s in the beginning followed by all the 1s then all the 2s.

-----------------------------------------------------------------------
    class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i;
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        for (i=0;i<n;i++)
        {
            switch(nums[i])
            {
                case 0:
                    cnt0++;
                    break;
                case 1:
                    cnt1++;
                    break;
                case 2:
                    cnt2++;
                    break;
            }
        }
        // Now update the array 
        // store zero in the beginning
        i=0;
        while (cnt0>0)
        {
            nums[i++]=0; // store zero in the array and move ahead;
            cnt0--;            
        }
        // now update 1 in the array
        while (cnt1>0)
        {
            nums[i++]=1;
            cnt1--;
        }
        // now keep 2 in the array 
        while (cnt2>0)
        {
            nums[i++]=2;
            cnt2--;
        }
   
    }
};
Complexity Analysis: 
Time Complexity: O(n). 
Only two traversals of the array is needed.
Space Complexity: O(1). 
As no extra space is required.
