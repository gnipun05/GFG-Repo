//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> s(B.begin(), B.end());
        int n=A.size();
        vector<bool> dp(n+1, 0);
        dp[0]=1;
        for(int i=0; i<n; i++){
            if(!dp[i])
                continue;
            for(int j=1; j<=n-i; j++){
                string str=A.substr(i, j);
                if(s.find(str)!=s.end())
                    dp[i+j]=true;
            }
            if(dp[n])
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends