//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        sort(candies, candies+n);
        int a=0, b=0;
        int i=0, j=n-1;
        while(i<=j){
            a+=candies[i++];
            j-=k;
        }
        i=0, j=n-1;
        while(i<=j){
            b+=candies[j--];
            i+=k;
        }
        return {a, b};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends