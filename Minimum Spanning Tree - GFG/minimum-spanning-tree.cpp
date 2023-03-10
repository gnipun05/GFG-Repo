//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(V, false);
        vector<int> key(V, INT_MAX);
        visited[0]=true;
        key[0]=0;
        pq.push({0,0});
        while(pq.empty()==false){
            int i=pq.top().second; pq.pop();
            visited[i]=true;
            for(auto x:adj[i]){
                int node=x[0];
                int wt=x[1];
                if(visited[node]==false && wt<key[node]){
                    key[node]=wt;
                    pq.push({key[node], node});
                }
            }
        }
        int answer=0;
        for(int i=0; i<V; i++)
            answer+=key[i];
        return answer;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends