//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(vector<vector<int>> &dp, int W, int wt[], int val[], int n, int i){
        if(W == 0) return 0;
        if(i == n) return 0;
        int take = INT_MIN, notTake = INT_MIN;
        if(dp[i][W] != -1){
            return dp[i][W];
        }
        if(wt[i] <= W){
            take = helper(dp, W-wt[i], wt, val, n, i+1) + val[i];
        }
        notTake = helper(dp, W, wt, val, n, i+1);
        return dp[i][W] = max(take, notTake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int ans;
        vector<vector<int>> dp(n+1, vector<int> (W+1, -1));
        ans = helper(dp, W, wt, val, n, 0);
        return ans;
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