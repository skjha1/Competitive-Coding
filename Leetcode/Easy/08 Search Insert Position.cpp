class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (nums[mid]<target) low= mid+1;
            else if (nums[mid]>target) high=mid-1;
            else return mid;
        }
        return low;
    }
};

--------------------------------------------------------------------------------------------------------
    
    class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int start=0;
        int end= n-1;
        while (start <=end){
            int mid = start + (end-start)/2;
            if (target== nums[mid])
                return mid;
            else if (target<nums[mid])
                end=mid-1;
            else
            {
                int res=mid;
                start=mid+1;
            }
            
        }
        return start;
    }
};
