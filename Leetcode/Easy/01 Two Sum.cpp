// https://leetcode.com/problems/two-sum/discuss/1162422/Explained-with-pen-and-paper-and-gfg-ref


---------------------------------------------------------
	class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> hmap;
        for (int i=0;i<nums.size();i++){
            if (hmap.count(target-nums[i]))
                return {i,(hmap[target-nums[i]])};
            hmap[nums[i]]=i;
        }
        return {};
} 
        
};
------------------------------------------------------------------------
	
	class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
               int res= nums[i]+nums[j];
                if (res==target)
                    return {i,j};
            }
        }
        return {};
    }
        
        
};

----------------------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    //Key is the number and value is its index in the vector.
        unordered_map<int,int> hash;
        vector<int> res;
        for (int i=0;i<nums.size();++i)
        {
            int numbertofind=target-nums[i];
		//if numberToFind is found in map, return them
            if (hash.find(numbertofind)!=hash.end())
            {
                res.push_back(hash[numbertofind]); // take index from map where the target element is found
                res.push_back(i);
                return res;
            }
            hash[nums[i]]=i;
        }
        return res;
        
    }
};

#include <vector>
#include <iostream>

using namespace std;

// ---------------------------------------------------------- O(n*m)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for (int i=0;i<nums.size();i++){
           for (int j=i+1;j<nums.size();j++){
               int complement =target-nums[i];
               if (complement == nums[j]){
                   return {i,j};
               }
           }
       }
        return {};
        
    }
};
// -------------------------------------------------------------
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n= nums.size();
        unordered_map<int,int> hmap;
        vector <int> ans;
        for (int i=0;i<n;i++)
        {
            if (hmap.find(target-nums[i])!=hmap.end()){
                ans.push_back(hmap[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            hmap[nums[i]]=i; // store current nums of i in the hash table 
        }
        return ans;
    }
};

//---------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoSumAns;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[i] + nums[j] == target) {
                    twoSumAns.push_back(i);
                    twoSumAns.push_back(j);
                }
            }
        }
        return twoSumAns;
    }
};
void PrintVector(vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
       vector<int> nums = {2,7,11,15};
        int Sum = 9;
  /*  vector<int> nums = { 3,2,4 };
    int Sum = 6;*/
    vector<int> result = solution.twoSum(nums, Sum);
    PrintVector(result);
}



-----------------------------------------------------------------------------------------------------------------------
    
    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num1; // make a variable for finding the element
        for (int i = 0; i < nums.size(); i++)  // iterate through the vector 
        {
            num1 = target - nums[i]; // we will get the 2nd item to bve find 
            for (int k = i+1; k < nums.size(); k++ ) // for finding the position 
            {
                 if(nums[k] == num1)
                 {
                     return {i,k}; // just take both the subscript 
                 }
            }
        }
        return {};
    }
};
// ------------------------------------------------------------------------------------------------------------


class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
        
//map for finding the complement of current number in the vector
        std::unordered_map<int, int> hashmap; 
        
        //loop for checking if the complement of the current integer exist in the map
        for(int i = 0; i < nums.size(); i++){
            //if complement has found, return current index and index of compliment
            //index of complement is its value in the map
			//with C++20, mappy.contains would probably been better
            if(hashmap.count(target-nums[i])){
				//return the index of the current integer in the vector, and the index of the complement
                return {i,(hashmap[target - nums[i]])};
            }
            //if complement has not been passed by yet, modify the complement's value with its index
            hashmap[nums[i]] = i;
        }
        //return empty vector if no integers answer found
        return {};
}
};

------------------------------------------------------------------------------------------------------------------
	
	class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> hmap;
        for (int i=0;i<nums.size();i++)
        {
            if (hmap.count(target-nums[i]))
                return {i,hmap[target-nums[i]]};
            hmap[nums[i]]=i;
        }
        return {};
    }
};

------------------------------------------------------------------------------------------------------------------------
	
	class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap();
        
        for(int i = 0; i < nums.length; i++)
            map.put(nums[i], i);
        
        for(int i = 0; i < nums.length; i++)
            if(map.containsKey(target - nums[i]) && i != map.get(target - nums[i]))
                return new int[] {i, map.get(target - nums[i])};
        
        return new int[2];
    }
}
