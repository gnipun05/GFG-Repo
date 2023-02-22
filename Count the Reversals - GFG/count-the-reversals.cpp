//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n=s.size();
    if(n%2)
        return -1;
    int count=0, answer=0;
    for(char c:s){
        if(c=='{')
            count++;
        else
            count--;
        if(count==-1){
            answer++;
            count=1;
        }
    }
    if(count)
        answer+=count/2;
    return answer;
}