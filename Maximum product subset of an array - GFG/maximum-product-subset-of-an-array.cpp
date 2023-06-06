//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        if(n==1)
            return a[0];
        long long int answer=1;
        int mod=1e9+7;
        int zero=0, neg=0, mnneg=INT_MIN;
        bool flag=false;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                zero++;
                continue;
            }
            answer*=a[i];
            answer=answer%mod;
            if(a[i]<0){
                mnneg=max(mnneg, a[i]);
                neg++;
            }
        }
        if(zero==n || (zero==n-1 && neg==1))
            return 0;
        if(neg%2)
            answer/=mnneg;
        return answer%mod;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends