//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    // Custom comparator function
    struct comp
    {
        bool operator()(pair<pair<int,int>,int> x,pair<pair<int, int>,int> y)
        {
            return x.second > y.second;
        }
    };
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // Min Heap
        typedef pair<pair<int,int>,int> pq_elem;
        priority_queue  <pq_elem,vector<pq_elem>,comp> pq;
        
        for(int i=0;i<K;i++)
        {
            pq.push({{i,0},arr[i][0]});
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            pq_elem elem=pq.top();
            pq.pop();
            ans.push_back(elem.second);
            
            int i=elem.first.first,j=elem.first.second+1;
            if(j<arr[i].size())
            {
                pq.push({{i,j},arr[i][j]});
            }
            
            
        }
        
        return(ans);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends