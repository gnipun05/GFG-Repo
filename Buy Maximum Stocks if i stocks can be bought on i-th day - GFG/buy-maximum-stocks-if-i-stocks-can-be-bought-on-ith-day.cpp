//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++)
            arr.push_back({price[i], i+1});
        sort(arr.begin(), arr.end());
        int answer=0,i=0;
        while(i<n && k>=arr[i].first){
            int div=k/arr[i].first;
            k-=arr[i].first*min(div, arr[i].second);
            answer+=min(div, arr[i].second);
            i++;
        }
        return answer;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends