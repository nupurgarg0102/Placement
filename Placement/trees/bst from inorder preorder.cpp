#include<iostream>
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
     int search(int inorder[],int start,int end,int curr)
     {
         for(int i=start;i<=end;i++)
         {
             if(inorder[i]==curr)
             {
                 return i;
             }
         }
         return -1;
     }
     Node* buildheap(int inorder[],int preorder[],int start,int end)
     {
         static int index=0;
         if(start>end)
         {
             return NULL;
         }
         int curr=preorder[index];
         index++;
         Node* node=new Node(curr);
         if(start==end)
         {
             return node;
         }
         int pos=search(inorder,start,end,curr);
         node->left=buildheap(inorder,preorder,start,pos-1);
         node->right=buildheap(inorder,preorder,pos+1,end);
         return node;


     }
     void inorderprint(Node* root)
     {
         if(root==NULL)
            return;
         inorderprint(root->left);
         cout<<root->data<<" ";
         inorderprint(root->right);
     }
int main()
{
    int inorder[]={4,2,1,5,3};
    int preoder[]={1,2,4,3,5};
    Node* rt=buildheap(inorder,preoder,0,4);
    inorderprint(rt);

}
