//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Custom comparator function
    struct comp
    {
        bool operator()(pair<pair<int,int>,int> x,pair<pair<int, int>,int> y)
        {
            return x.second < y.second;
        }
    };
    
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Sorting A and B in non-increasing order
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        
        // Max Heap
        typedef pair<pair<int,int>,int> pq_elem;
        priority_queue  <pq_elem,vector<pq_elem>,comp> pq;
                        
        // Adding pairs of elements of A with 0th element of B to 'pq'
        for(int i=0;i<N;i++)
        {
            pq.push({{i,0},A[i]+B[0]});
        }
        
        // To store max K sum combinations
        vector<int> ans;    
        
        // Obtaining max K sum combinations
        for(int i=1;i<=K;i++)
        {
            // Retrieving current max sum and popping
            pq_elem comb=pq.top();
            pq.pop();
            
            // Pushing max sum to answer
            ans.push_back(comb.second);
            
            // Adding successor of current max sum to 'pq'
            int x=comb.first.first,y=comb.first.second+1;
            if(y<N)
            {
                pq.push({{x,y},A[x]+B[y]});
            }
        }
        
        return(ans);    // Return K max sum combinations
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
