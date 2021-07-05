#include<iostream>
#include<cstdio>
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

int calcheight(Node*root)
{
    if(root==nullptr)return 0;
    int lhgt=calcheight(root->left);
    int rhgt=calcheight(root->right);
    return max(lhgt,rhgt)+1;
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
    cout<<calcheight(root);
}
