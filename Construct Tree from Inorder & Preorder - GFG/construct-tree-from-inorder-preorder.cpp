//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int *in, int a, int b, int* pre, int c, int d){
        if(b<a || d<c)
            return NULL;
        int i=a;
        for(; i<=b; i++){
            if(in[i]==pre[c])
                break;
        }
        Node* node = new Node(pre[c]);
        node->left=solve(in, a, i-1, pre, c+1, c+i-a);
        node->right=solve(in, i+1, b, pre, c+i-a+1, d);
        return node;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return solve(in, 0, n-1, pre, 0, n-1);
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
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends