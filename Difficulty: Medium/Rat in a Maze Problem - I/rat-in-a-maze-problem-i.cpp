//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans; // To store all possible paths
    
    void backtrack(vector<vector<int>>& m,int n,string& path,vector<char>& dr,int r,int c)
    {
        if(r==n-1 && c==n-1)
        {
            ans.push_back(path); // Path found
            return;
        }
        
        // Exploring each direction from current position
        for(int i=0;i<dr.size();i++)
        {
            // Coordiantes of next position
            int next_r=(i/2?r:r-1+2*(i%2));
            int next_c=(i/2?c-1+2*(i%2):c);
            
            if  (next_r>=0 && next_r<n && next_c>=0 && next_c<n
                && m[next_r][next_c]==1)
            {
                m[r][c]=0;
                path.push_back(dr[i]);
                
                backtrack(m,n,path,dr,next_r,next_c);
                
                m[r][c]=1;
                path.pop_back();
            }
        }
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0)
        {
            return(ans); // Source cell is 0, no paths possible
        }
        
        string path;                        // To store traversed path
        vector<char> dr{'U','D','L','R'};   // Possible directions at each step
        
        backtrack(m,n,path,dr,0,0);         // Begin from cell (0,0)
        
        return(ans);                        // Return all possible paths
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends