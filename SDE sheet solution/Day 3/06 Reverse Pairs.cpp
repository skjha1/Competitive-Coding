class Solution {
public:
    int merge(vector<int> &nums, int l, int m, int h) {
        int count=0;
        int j=m+1;
        for(int i=l;i<=m;++i) {
            while(j<=h && nums[i] > 2LL*nums[j]) ++j;
            count += (j - (m+1));
        }
        // merge of two sorted array
        vector<int> temp;
        int left=l,right=m+1;
        // loop till on of them execuested
        while(left<=m && right<=h) {
            if(nums[left]<=nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }
        // remaining elements of left side
        while(left<=m) temp.push_back(nums[left++]);
        // remaining elements of right side
        while(right<=h) temp.push_back(nums[right++]);
        // assingn in main vector after merging
        for(int i=l;i<=h;++i) {
            nums[i]=temp[i-l];
        }
        return count;
    }
    int mergeSort(vector<int> &nums, int l, int h) {
        if(l>=h) return 0; // A single element does not contain any pair 
        int m=(l+h)/2;
        int count=0;
        count += mergeSort(nums,l,m);    // count from left side of vector
        count += mergeSort(nums,m+1,h);  // count from right side of vector
        count += merge(nums,l,m,h);      // count merge 
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
