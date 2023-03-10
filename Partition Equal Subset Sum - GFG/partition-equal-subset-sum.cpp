//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int solve(int *arr, int n, int sum){
        if(sum==0)
            return true;
        if(n==0)
            return false;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        if(arr[n-1]<=sum)
            dp[n][sum]=solve(arr, n-1, sum-arr[n-1]) || solve(arr, n-1, sum);
        else
            dp[n][sum]=solve(arr, n-1, sum);
        return dp[n][sum];
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=arr[i];
        if(sum%2)
            return false;
        dp.resize(n+1, vector<int> (sum/2+1, -1));
        return solve(arr, n, sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends