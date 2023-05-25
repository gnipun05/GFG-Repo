//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        int a=0;
        for(int i=0; i<D; i++)
            a+=9;
        if(S>=a)
            return "-1";
        string answer(D, '0');
        int i=0;
        while(S>=10){
            S-=9;
            answer[i++]='9';
        }
        if(i!=D-1){
            S--;
            answer[D-1]='1';
        }
        answer[i]='0'+S;
        reverse(answer.begin(), answer.end());
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends