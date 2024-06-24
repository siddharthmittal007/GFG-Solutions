//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isValid(bool graph[101][101],int n,int vertex,int c,vector<int>& colour)
    {
        for(int i=0;i<n;i++)
        {
            if(graph[vertex][i]==true && colour[i]==c)
            {
                return(false);
            }
        }
        return(true);
    }
    
    
    bool backtrack(bool graph[101][101],int n,int m,int vertex,vector<int>& colour)
    {
        if(vertex==n)
        {
            return(true); // Possible to colour
        }
        
        // Trying each colour for current vertex
        for(int c=1;c<=m;c++)
        {
            if(isValid(graph,n,vertex,c,colour))
            {
                colour[vertex]=c;
                if(backtrack(graph,n,m,vertex+1,colour)==true)
                {
                    return(true);
                }
                colour[vertex]=0;
            }
        }
        return(false);
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colour(n,0);
        return(backtrack(graph,n,m,0,colour));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends