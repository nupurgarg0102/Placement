#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
    Node (int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void levelorder(Node*root)
{
    if(root==nullptr)
        return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node*node=q.front();
        q.pop();
        if(node!=nullptr){
            cout<<node->data<<" ";
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(nullptr);
        }
    }
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
    levelorder(root);
    return 0;

}
