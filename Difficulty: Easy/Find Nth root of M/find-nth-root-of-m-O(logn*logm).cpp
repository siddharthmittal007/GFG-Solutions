//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int pow(int base,int exp)
	{
	    // Base case
	    if(exp==1)
	    {
	        return(base);
	    }
	    
	    if(base>INT_MAX/base)
	    {
	        return(-1); // Overflow
	    }
	    // Checking for overflow
	    int val=pow(base*base,exp/2);
	    if(val==-1 || (exp%2 && val>INT_MAX/base))
	    {
	        return(-1); // Overflow
	    }
	    
	    return(exp%2?base*val:val); // No overflow
	}
	
	int NthRoot(int n, int m)
	{
	   // Binary search
	   int low=1,high=m;
	   
	   while(low<=high)
	   {
	       int mid=(low+high)/2;
	       
	       int val=pow(mid,n);
	       
	       if(val==-1 || m<val)
	       {
	           high=mid-1;
	       }
	       else if(m>val)
	       {
	           low=mid+1;
	       }
	       else //(m==val)
	       {
	           return(mid); // 'nth' root of 'm'
	       }
	   }
	   
	   return(-1); // 'nth' root of 'm' doesnt exist
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
