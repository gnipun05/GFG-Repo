//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int solve(int *arr, int n, int t){
        long long sum=0, count=1;
        for(int i=0; i<n; i++){
            if(sum+arr[i]>t){
                count++;
                sum=0;
            }
            sum+=arr[i];
        }
        return count;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(n<m)
            return -1;
        long long sum=0;
        int mx=INT_MIN;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            mx=max(mx, arr[i]);
        }
        long long lo=mx, hi=sum;
        while(lo<hi){
            long long mid=(lo+hi)/2;
            int temp=solve(arr, n, mid);
            if(temp<=m)
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends