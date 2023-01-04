//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool isSafe(int n,int m,int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}
long long numOfWays(int N, int M)
{
    // write code here
    const long long mod = 1e9+7;
    long long ans=0;
    int total = N*M;
    int dx[] = {2,2,-2,-2,1,1,-1,-1};
    int dy[] = {1,-1,1,-1,2,-2,2,-2};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int count = 1;
            for(int k=0;k<8;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(isSafe(N,M,x,y))
                    count++;
            }
            ans = (ans + (total - count))%mod;
        }
    }
    return ans;
}