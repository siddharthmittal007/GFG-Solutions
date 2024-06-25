//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Assuming no duplicate words in dictionary
class Solution{
public:
    vector<string> ans; // To store possible sentences
    
    bool checkWord(vector<string>& dict,int word,string& s,int index)
    {
        for(int i=0;i<dict[word].size();i++)
        {
            if(index+i==s.size() || s[index+i]!=dict[word][i])
            {
                return(false);
            }
        }
        return(true);
    }
    
    void backtrack(vector<string>& dict,string& s,vector<string>& v,int index)
    {
        if(index==s.size())
        {
            string snt;
            for(int i=0;i<v.size();i++)
            {
                snt.append(v[i]);
                snt.append(1,' ');
            }
            snt.pop_back();
            ans.push_back(snt);
            return;
        }
        
        for(int i=0;i<dict.size();i++)
        {
            if(checkWord(dict,i,s,index))
            {
                v.push_back(dict[i]);
                backtrack(dict,s,v,index+dict[i].length());
                v.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector <string> v;
        backtrack(dict,s,v,0);
        return(ans);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends