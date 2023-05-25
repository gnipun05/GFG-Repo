//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int a=0, b=0, c=0;
        for(int i:S1)
            a+=i;
        for(int i:S2)
            b+=i;
        for(int i:S3)
            c+=i;
        int i=0, j=0, k=0;
        while(i<S1.size() && j<S2.size() && k<S3.size()){
            if(a>b || a>c)
                a-=S1[i++];
            if(b>a || b>c)
                b-=S2[j++];
            if(c>a || c>b)
                c-=S3[k++];
            if(a==b && a==c)
                return a;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends