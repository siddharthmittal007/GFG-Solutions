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
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        // Max Heap
        typedef pair<pair<int,int>,int> pq_elem;
        priority_queue<pq_elem,vector<pq_elem>,comp> pq;
        
        // Set
        set<pair<int,int>> s;
                        
        // Adding max pair to 'pq' and set 's'
        pq.push(make_pair(make_pair(N-1,N-1),A[N-1]+B[N-1]));
        s.insert(make_pair(N-1,N-1));
        
        // To store max K sum combinations
        vector<int> ans;    
        
        // Obtaining max K sum combinations
        for(int cnt=1;cnt<=K;cnt++)
        {
            // Retrieving current max sum and popping
            pq_elem comb=pq.top();
            pq.pop();
            
            // Pushing max sum to answer
            ans.push_back(comb.second);
            
            // Adding successors of current max sum to 'pq'
            int i=comb.first.first,j=comb.first.second;
            if(i-1>=0)
            {
                if(s.find(make_pair(i-1,j))==s.end())
                {
                    s.insert(make_pair(i-1,j));
                    pq.push(make_pair(make_pair(i-1,j),A[i-1]+B[j]));
                }
            }
            if(j-1>=0)
            {
                if(s.find(make_pair(i,j-1))==s.end())
                {
                    s.insert(make_pair(i,j-1));
                    pq.push(make_pair(make_pair(i,j-1),A[i]+B[j-1]));
                }
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