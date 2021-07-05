#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
struct Node*left;
struct Node*right;
 Node(int val)
      {
          data=val;
          left=nullptr;
          right=nullptr;
      }
};
int sumatk(Node*root,int k)
{
    if(root==nullptr)return -1;
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    int level=0,sum=0;
    while(!q.empty())
    {
        int n=q.size();
        Node*node=q.front();
        q.pop();
       if(node!=nullptr)
        {
        if(level==k)
            sum+=node->data;
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);

    }
    else if(!q.empty())
    {
        q.push(nullptr);
        level++;
    }
    }
    return sum;
}
int main()
{
     Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
  cout<<sumatk(root,2);
}
