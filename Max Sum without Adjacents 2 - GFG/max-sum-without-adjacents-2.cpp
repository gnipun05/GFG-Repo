//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  int maxSum(vector<int> &arr, int i, vector<int> &dp){
        if (i < 0)
    	    return 0;
    
    	if (i == 0)
    		return arr[i];
    
    	if (dp[i] != -1)
    		return dp[i];
    
    	// including current element and the next consecutive element in subsequence
    	int a = arr[i] + arr[i - 1] + maxSum(arr, i - 3, dp);
    
    	// not including the current element in subsequence
    	int b = maxSum(arr, i - 1, dp);
    
    	// including current element but skipping next consecutive element
    	int c = arr[i] + maxSum(arr, i - 2, dp);
    
    	// returning the max of above 3 cases
    	return dp[i] = max(a, max(b, c));
  }
  int findMaxSum(vector<int>& a){
      //Code Here
        int n=a.size();
        vector<int>dp(n, -1);
        return maxSum(a, n-1, dp);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends