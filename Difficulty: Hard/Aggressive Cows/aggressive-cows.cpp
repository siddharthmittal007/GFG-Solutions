//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isValid(vector<int>& stalls,int k,int min_dist)
    {
        int count=1,last=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-last>=min_dist)
            {
                count++;
                last=stalls[i];
            }
            else
            {
                continue;
            }
        }
        if(count>=k)
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        // Sorting stalls by position
        sort(stalls.begin(),stalls.end());
        
        // Binary search
        int ans=0;
        int low=0,high=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(stalls,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return(ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends