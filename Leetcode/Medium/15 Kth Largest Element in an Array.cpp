class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // declare a min heap // where in question it is given largest/greatest means create min heap and for smaller create max heap
       int val;
        priority_queue<int,vector<int>,greater<int>> minh;
        int n= nums.size();
        for (int i=0;i<n;i++)
        {
            minh.push(nums[i]);
            {
                if (minh.size()>k)
                    minh.pop();
            }
        }
        return minh.top();
        
    }
};
