//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> arr={x, y, z};
        vector<vector<int>> dp(3+1, vector<int> (n+1, 0));
        for(int j=1; j<=n; j++)
            dp[0][j]=INT_MIN;
        for(int i=1; i<=3; i++){
            for(int j=1; j<=n; j++){
                if(arr[i-1]<=j)
                    dp[i][j]=max(dp[i-1][j], dp[i][j-arr[i-1]]+1);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[3][n]<0)
            return 0;
        return dp[3][n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends