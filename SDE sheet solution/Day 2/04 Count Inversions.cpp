#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
        long long int merge(long long int arr[], long long int s, long long int e, long long int N) {
    long long int mid = (s + e) / 2;
    long long int i = s;
    long long int j = mid + 1;
    long long int k = s;
    long long int temp[N];
    long long int invert = 0;
    while (i <= mid && j <= e) {
    if (arr[i] <= arr[j])
    temp[k++] = arr[i++];
    else {
    temp[k++] = arr[j++];
    invert += mid - i + 1;
    }
    }
    while (j <= e)
    temp[k++] = arr[j++];
    while (i <= mid)
    temp[k++] = arr[i++];
    for (int i = s; i <= e; i++)
    arr[i] = temp[i];
    return invert;
    
    }
    long long int inversion(long long arr[], long long int s, long long int e, long long int N) {
    if (s >= e)
    return 0;
    long long int mid = (s + e) / 2;
    long long int x = inversion(arr, s, mid, N);
    long long int y = inversion(arr, mid + 1, e, N);
    long long int z = merge(arr, s, e, N);
    return x + y + z;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return inversion(arr, 0, N - 1, N);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
