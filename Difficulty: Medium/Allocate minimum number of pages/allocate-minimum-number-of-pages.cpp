//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(n<m)
        {
            return(-1); // No valid assignment possible
        }
        
        long long min_val=1;
        
        for(int i=0;i<n;i++)
        {
            min_val=max(min_val,arr[i]*1LL);
        }
        
        // Binary Search
        long long low=min_val,high=INT_MAX;
        while(low<high)
        {
            long long mid=low+(high-low)/2;
            
            int count=1;
            long long pages=0;
            for(int i=0;i<n;i++)
            {
                if(pages<=mid-arr[i]*1LL)
                {
                    pages+=arr[i]*1LL;
                }
                else
                {
                    count++;
                    pages=arr[i]*1LL;
                }
            }
            if(count<=m)
            {
                high=mid;
            }
            
            else    // (count>m)
            {
                low=mid+1;
            }
        }
        
        return(low);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends