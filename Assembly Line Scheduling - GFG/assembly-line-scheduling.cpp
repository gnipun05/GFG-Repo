//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      //Code Here
      int first=a[0][0]+e[0];
      int second=a[1][0]+e[1];
      int n=a[0].size();
      for(int i=1; i<n; i++){
          int up=a[0][i]+min(first, T[1][i]+second);
          int down=a[1][i]+min(second, T[0][i]+first);
          first=up;
          second=down;
      }
      return min(first+x[0], second+x[1]);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends