//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // link to the explaination to the approach
    // https://www.youtube.com/watch?v=YHSjvswCXC8&t=1464s&ab_channel=Pepcoding
    public:
    #define mod 1000000007
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.size();
       long long dp[n][n];
       memset(dp, 0, sizeof(dp));
       for(int gaps=0; gaps<n; gaps++){
           for(int i=0, j=gaps; j<n; i++, j++){
                if(gaps==0)
                    dp[i][j]=1;
                else if(str[i]==str[j])
                    dp[i][j] = (dp[i+1][j]+dp[i][j-1]+1)%mod;
                else
                    dp[i][j] = ((dp[i+1][j]+dp[i][j-1])%mod + mod -dp[i+1][j-1])%mod;
           }
       }
       return dp[0][n-1];
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends