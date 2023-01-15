//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int solve(int *wt, int w, int *val, int n){
        if(w<=0 || n<=0)
            return 0;
        if(dp[n][w]!=-1)
            return dp[n][w];
        if(wt[n-1]<=w){
            dp[n][w]=max(solve(wt, w-wt[n-1], val, n-1)+val[n-1], solve(wt, w, val, n-1));
        }
        else{
            dp[n][w]=solve(wt, w, val, n-1);
        }
        return dp[n][w];
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       dp.resize(n+1, vector<int> (w+1, -1));
       return solve(wt, w, val, n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends