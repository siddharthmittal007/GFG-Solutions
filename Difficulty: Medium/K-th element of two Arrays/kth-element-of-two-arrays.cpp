//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return(solve(arr1,0,n-1,arr2,0,m-1,k));
    }
    int solve(int nums1[],int low1,int high1,int nums2[],int low2,int high2,int k)
    {   
        if(low1>high1)      // 'nums1' empty
        {
            return(nums2[k-low1-1]);
        }
        else if(low2>high2) // 'nums2' empty
        {
            return(nums1[k-low2-1]);
        }
        else                // 'nums1' and 'nums2' non-empty
        {
            int mid1=low1+(high1-low1)/2;
            int mid2=low2+(high2-low2)/2;
            int count=(mid1+1)+(mid2+1);

            if(count<=k)        // Eliminate first half
            {
                if(nums1[mid1]<=nums2[mid2])        
                {
                    // Eliminate first half of 'nums1'
                    return(solve(nums1,mid1+1,high1,nums2,low2,high2,k));
                }
                else
                {
                    // Eliminate first half of 'nums2'
                    return(solve(nums1,low1,high1,nums2,mid2+1,high2,k));
                }
            }
            else                // Eliminate second half
            {
                if(nums1[mid1]<=nums2[mid2])
                {
                    // Eliminate second half of 'nums2'
                    return(solve(nums1,low1,high1,nums2,low2,mid2-1,k));
                }
                else
                {
                    // Eliminate second half of 'nums1'
                    return(solve(nums1,low1,mid1-1,nums2,low2,high2,k));
                }
            }
        }       
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends