class Solution {
public:
    double mediann(vector<int>&a,vector<int>&b){
        int m=a.size();
        int n=b.size();
        if(m>n)
            return mediann(b,a);
        int l=0,r=m;
        while(l<=r){
            int partx=l+(r-l)/2;
            int party=(m+n+1)/2-partx;
            int maxlx=(partx==0)?INT_MIN:a[partx-1];
            int minrx=(partx==m)?INT_MAX:a[partx];
            int maxly=(party==0)?INT_MIN:b[party-1];
            int minry=(party==n)?INT_MAX:b[party];
            if(maxlx<=minry&&maxly<=minrx){
                if((m+n)%2==0)
                    return (double)(max(maxlx,maxly)+min(minrx,minry))/2;
                else
                    return (double)(max(maxlx,maxly));
            }else if(maxlx>minry)
                r=partx-1;
            else
                l=partx+1;
        }
        return -1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        ans=mediann(nums1,nums2);
        return ans;   
    }
};

--------------------------------------------------------------------------------------------------------------
    
    class Solution {
public:
    int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
    {
        // most important thing, initialization of low, high
        int low = max(0, k-m), high = min( n, k );
        int indx, indx2;
        while(low <= high)
        {
            
            int mid = low + (high - low) / 2;
            int x = mid;
            int y = k - x;  // x + y == k

            int A = ( x==0 ) ? INT_MIN : arr1[x-1];
            int B = ( y==0 ) ? INT_MIN : arr2[y-1];
  
            int C = ( x+1 <= n) ? arr1[x] : INT_MAX ;
            int D = ( y+1 <= m) ? arr2[y] : INT_MAX ;

			// Array visualization
            // ---------A     C---------
            // ---------B     D---------
            
            if( (A<=D) && (B<=C) )
            {
                indx = mid;
                indx2 = k - mid;
                break;
            }
            else if( A > D )
                high = mid - 1;
            else 
                low = mid + 1;
        }

        int ans;
        if(indx <= n)
        {
            int a = (indx > 0) ? arr1[indx - 1] : INT_MIN;
            int b = (indx2 > 0) ? arr2[ indx2 - 1] : INT_MIN;
            return max(a, b);
        }
        return arr2[ indx2 - 1];
    }
    
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        if( (n+m)%2 ) return kthElement(arr1, arr2, n, m, (n+m+1)/2);
        
        int a = kthElement(arr1, arr2, n, m, (n+m)/2);
        int b = kthElement(arr1, arr2, n, m, (n+m)/2 + 1);

        return (a + b) / 2.0 ;
    }
};

/*
Intuition :
We have to select first K elements from the final merged array. So we can suppose some x elements are coming from where arr1 and some y elements are coming from arr2 where x or y may be zero but x+y==k.

Question 1 : How to find x and y ?
For some fixed value of x , y = k - x becuase x+y==k.
And to find x naive approach is we can iterate the arr1 from start to end and it will take O(n) time.
But as array is sorted if we choose some pivot point as x and if it will not be satisfying the criteria of partition ( we will see the criteria later) then we can move the pivot to the right or left by checking the condition. Here moving the pivot to the right or left gives the idea of using Binary Search to find the value of x.

Question 2 : How to use Binary Search?
If we select first x elements from array1 and first y elements from array2 then it will divide the array in two part.

arr1    :    ---------A     C---------
arr2    :    ---------B     D---------
Here A is the xth element of arr1 and C is x+1th element of first array
Similary B is the yth element of arr1 and D is y+1th element of second array.

Suppose it is valid partioning of both the array, here valid partioning means

merged(arr1, arr2) = merged( ------A, ------B ) + merged( C----------, D-------- )
							(first k elements)               (last n-k elements)
							  first part                        second part
And if it is proper division of both array to merged then Kth smallest element will be last element of first part, which can be either A or B. So our problem reduced to find maximum between A and B.

Question 3 : What will be criteria to check valid partioning?
To be valid partioning each element of first part must be less than or equal to second element.
But as arrays are already sorted, we only need to check that maxElement(part1) <= maxElement(part2).

A <= C  (trivial because  [ -----A   C------] was sorted array)
A <= D  

B <= C
B <= D (trivial because  [ -----B   D------] was sorted array)
So we only need to check (A<=D) && (B<=C) to be a valid partioning.

Question 4 : How to move left or right if the condition is false?

Let's suppose ( A > D ) which is false condition, then we have to move in direction where it becomes true ( A <= D ), so we can move pointer x to left becuase it will decrease A and condition ( A <= D ) may become true.
high = mid - 1.

Let's suppose ( B > C ) which is false condition, then we have to move in direction where it becomes true ( B <= C ), so we can move pointer y to left ( indirectly pointer x to right, because x+y is always equal to k, if x moves toward right then y will move left and vice versa) so it will decrease B and condition ( B <= C ) may become true.
low = mid + 1.

Initialising range for binary search
Here n1 and n2 are length of array1 and array2

				x
                ↓
arr1 :  0 ----------------- n1
arr2 :  0 ----------------------- n2
						↑
						y
x >= 0                                             -- eq 1
x <=n1                                             -- eq 2
(y = k - x )  >= 0  => ( x <= k )                  -- eq 3
(y = k - x ) <= n2  => ( x >= k-n2 )               -- eq 4


From eq 1 & eq 4 
	x >= max(0, k-m)  // low = max(0, k-n1)
From eq 2 & eq 3
	x <= min( n2, k ) // high = min( n2, k )
Corner Condition :

if x == 0, then arr1[ x - 1 ] will not exist and as this can be valid partioning and we are always comparing A <= D, so to get condition always true (because valid partionining) we have set A as minimum possible value, A = INT_MIN
Same case y == 0, then arr2[ y - 1 ] will not exist and as this can be valid partioning and we are always comparing B <= C, so to get condition always true (because valid partionining) we have set B as minimum possible value, B = INT_MIN
Similary if x == n1, then arr1[ x ] will not exist and as this can be valid partioning and we are always comparing B <= C, so to get condition always true (because valid partionining) we have set C as maximum possible value, C = INT_MAX.
Similary if y == n2, then arr2[ y ] will not exist and as this can be valid partioning and we are always comparing A <= D, so to get condition alway0s true (because valid partionining) we have set D as maximum possible value, D = INT_MAX.

*/
