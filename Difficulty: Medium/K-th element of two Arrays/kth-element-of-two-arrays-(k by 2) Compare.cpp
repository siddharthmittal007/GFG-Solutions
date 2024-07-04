//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return(solve(arr1,0,arr2,0,k,n,m));
    }
    int solve(int nums1[],int low1,int nums2[],int low2,int k,int m,int n)
    {   
        if(low1==m || low2==n)
        {
            return(low1==m?nums2[low2+k-1]:nums1[low1+k-1]);
        }
        else
        {
            if(k==1)
            {
                return(nums1[low1]<=nums2[low2]?nums1[low1]:nums2[low2]);
            }
            int half=k/2;
            int ind1=min(m-1,low1+half-1);
            int ind2=min(n-1,low2+half-1);

            if(nums1[ind1]<=nums2[ind2])
            {
                k-=ind1-low1+1;
                return(solve(nums1,ind1+1,nums2,low2,k,m,n));
            }
            else
            {
                k-=ind2-low2+1;
                return(solve(nums1,low1,nums2,ind2+1,k,m,n));
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
