class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mn= INT_MAX;
        int j=0; // taking to the left most element to the array 
        int sum=0; 
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                mn = min(mn,i-j+1); // i-j+1 will give the size of window and maintain the size of the window 
                sum-=nums[j]; // decrease the size of window by one.
                j++; // increment in order to maintain the window size.
            }
            
        }
        return (mn!=INT_MAX)? mn:0; // return the minimum size the window to get the target 
    }
};
