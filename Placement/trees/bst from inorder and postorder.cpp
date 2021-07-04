#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
int data;
struct Node* left;
struct Node* right;
Node(int val)
     {
         data=val;
         left=NULL;
         right=NULL;
     }
};
int search(vector<int>inorder,int start,int end,int curr)
{

    for(int i=start;i<end;i++){
        if(inorder[i]==curr)
        return i;
    }
    return -1;
}

 Node* buildtree(vector<int>postorder,vector<int>inorder,int start,int end)
 {
     static int index=end;
     if(start>end)
        return nullptr;
        int curr=postorder[index];
        index--;
        Node* node=new Node(curr);
        if(start==end)
            return node;
        int position=search(inorder,start,end,curr);
        node->right=buildtree(postorder,inorder,position+1,end);
        node->left=buildtree(postorder,inorder,start,position-1);
        return node;

 }
 void inorderprint(Node* root)
 {
     if(root==NULL)
        return;
     inorderprint(root->left);
     cout<<root->data;
     inorderprint(root->right);
 }
int main()
{
    int n;
cin>>n;
vector<int> inorder(n),postorder(n);
for(int i=0;i<n;i++)
{
    cin>>inorder[i];
}
for(int i=0;i<n;i++)
{
    cin>>postorder[i];
}

Node*root=buildtree(postorder,inorder,0,n-1);
inorderprint(root);
}
