// aditya verma stack question varations 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>S;
        vector<int>ans;
        unordered_map<int, int>M;
        for (int i=nums2.size()-1;i>=0;i--)
        {
            while(S.size() and nums2[i]>S.top()) // when there is element in stack and element in array is greater then stack top ; then pop that elemet 
                S.pop();
            
            if(S.size())
                M[nums2[i]] = S.top();
      
            else
                 M[nums2[i]] = -1;
				 
            S.push(nums2[i]);
        }
        
        
        for(auto n:nums1)
            ans.push_back(M[n]);
        
        return ans;
            
    }
};
