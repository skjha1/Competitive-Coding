class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int x=0,m=0;
        map<int,int> h;
        for(int i=0;i<nums.size();i++) h[nums[i]]++;                                                  
        int n=h.size();
        if(n==1) return 1;        
        for(auto y:h)
        {   
            if(h.find(y.first+1)!=h.end()) m++;
            else {x=max(m,x);m=0;}
        }
        return max(x+1,m+1);
        
    }
};
