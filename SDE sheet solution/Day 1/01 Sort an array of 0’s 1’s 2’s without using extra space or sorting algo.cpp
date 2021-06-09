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
        
    }
};