//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        long lo=0, hi=N;
        while(lo<hi){
            long mid=(lo+hi)/2, pmid=mid*mid;
            if(pmid==N)
                return mid-1;
            else if(pmid>N)
                hi=mid;
            else
                lo=mid+1;
        }
        return lo-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends