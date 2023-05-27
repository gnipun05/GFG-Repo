//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        unordered_map<int, int> m;
        int answer=0;
        for(int i=0; i<n ;i++){
            if(!m.count(pages[i])){
                if(m.size()<c)
                    m[pages[i]]=i+1;
                else{
                    int mn=INT_MAX, key;
                    for(auto x:m){
                        if(x.second<mn){
                            key=x.first;
                            mn=x.second;
                        }
                    }
                    m.erase(key);
                    // unordered_map<int, int> temp;
                    // for(auto x:m){
                    //     if(x.first!=key)
                    //         temp[x.first]=x.second;
                    // }
                    // m=temp;
                    m[pages[i]]=i+1;
                }
                answer++;
            }
            else{
                m[pages[i]]=i+1;
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends