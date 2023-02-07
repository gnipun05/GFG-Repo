//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &nums,int n){
           //code here
           int framestart = -1, firstneg = -2, len = 0, neg = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0){ // reset everytime if zero
                    neg = 0;framestart = i;firstneg = -2;
                } 
                else {
                    if (nums[i] < 0) neg++;
                    if (neg == 1 && firstneg == -2) 
                        firstneg = i;   // init firstneg cnt neg;
                    if (neg % 2 == 0) 
                        len = max(len, i - framestart);  //if curr cnt neg is framestart;
                    else 
                        len = max(len, i - firstneg);  // first firstneg after last zero;
                }
            }
            return len;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends