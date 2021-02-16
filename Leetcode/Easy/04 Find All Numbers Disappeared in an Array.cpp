class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int no= nums.size(); // taking the size of the vector 
        vector <int> result; // creating a vector variable 
        
        //In the first for-loop, I am taking the number and finding the index and then making the element at that index negative.
        
        for (int i=0;i<no;i++)
        {
            int position = abs(nums[i])-1;
            if (nums[position]>0)
                nums[position]=-nums[position];
        }
        
        
        for (int i=0;i<no;i++)
        {
            if (nums[i]>0)
            result.push_back(i+1);
        }
        
        return result;
        
        
    }
};

/* Suppose I have A[] as {2, 4, 1, 4}. Now I am taking each element and making the number at that index negative.
First iteration, I take A[0] = 2. Index = abs(A[0])-1 = 2 - 1 = 1. Now I am making element at A[1] negative. Array becomes = {2, -4, 1, 4}
Second iteration, I take A[1] = -4 (from last iteration). Index = abs(A[1])-1 = 4 - 1 = 3. Now making A[3] element negative. Array becomes = {2, -4, 1, -4}
Third iteration, I take A[2] = 1. Index = abs(A[2])-1 = 1 - 1 = 0. Now making A[0] element negative. Array becomes = {-2, -4, 1, -4}
Fourth iteration, I take A[3] = -4 (from second iteration). Index = abs(A[3])-1 = 4 - 1 = 3. Now making A[3] element negative. Array becomes = {-2, -4, 1, -4}
Now the only positive number present is 1 which is at index 2. So the missing number is 2+1 (as we are using 0 indexing).
What we did is suppose we have number j from the array. We make the number present at index j negative. In way we are marking what all numbers we have seen while 
traversing the array.

*/
