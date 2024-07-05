//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    bool isValid(int arr[],int n,int m,long long max_pages)
    {
        // Checking no book with pages greater than 'max_pages'
        for(int i=0;i<n;i++)
        {
            if(max_pages<arr[i])
            {
                return(false);
            }
        }
        
        // Counting minimum number of students for valid assignment
        // given max 'max_pages' pages per student
        int count=1;
        long long pages=0;
        for(int i=0;i<n;i++)
        {
            if(pages+arr[i]<=max_pages)
            {
                pages+=arr[i];
            }
            else
            {
                count++;
                pages=arr[i];
            }
        }
        
        if(count<=m)
        {
            return(true);   // Valid assignment possible
        }
        else
        {
            return(false);  // Valid assignment not possible
        }
    }
    
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(n<m)
        {
            return(-1); // No valid assignment possible
        }
        
        // Finding sum of pages of all books
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        // Binary Search
        long long ans=sum;
        long long low=1,high=sum;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            
            if(isValid(arr,n,m,mid))
            {
                ans=mid;
                high=mid-1;   
            }
            
            else    
            {
                low=mid+1;  
            }
        }
        
        return(ans);
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
