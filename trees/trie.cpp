#include<bits/stdc++.h>
using namespace std;
struct trieNode{
struct trieNode*next[26];
bool isword;
trieNode()
{
    isword=false;
    for(int i=0;i<26;i++)
    {
       next[i]=nullptr;
    }
}
};
void insert(trieNode* root,string key)
{
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]='a';
        if(root->next[index]==NULL){
           root->next[index]=new trieNode();}
            root=root->next[index];
    }
    root->isword=true;
}
bool search(trieNode* root,string key)
{
    for(int i=0;i<key.length();i++)
    {
        if(root->next[key[i]-'a']==nullptr)
            return false;
        root=root->next[key[i]-'a'];
    }
    return (root!=nullptr&&root->isword);
}
bool isEmpty(trieNode*root)
{
    for(int i=0;i<26;i++)
    {
        if(root->next[i])
            return true;
    }
    return false;
}
trieNode *deletekey(trieNode* root,string key,int depth)
{
    if(!root)return NULL;
    if(depth==key.size())
    {
        if(root->isword)root->isword=false;
        if(isEmpty(root))
        {
            delete (root);
            root=nullptr;
        }return root;
    }

    int index=key[depth]-'a';
    root->next[index]=deletekey(root->next[index],key,depth+1);
    if(!isEmpty(root)&&!root->isword)
    {
        delete(root);
        root=nullptr;
    }
    return root;
}
int main()
{
    trieNode* root=new trieNode();
    int ch;
    string key;
    do{
        cout<<"Menu\n1. Insert\n2. Search\n3. Delete\nEnter Choice: ";
        cin>>ch;
        switch(ch)
        {

            case 1:cin>>key;
                   insert(root,key);
                 break;
            case 2:cin>>key;
                  if(search(root,key))
                    cout<<key<<" is present\n";
                  else
                  cout<<key<<" is not present\n";
                break;
            case 3:cin>>key;
                  deletekey(root,key,0);
                  cout<<key<<" is deleted\n";
                  break;
            default:
                cout<<"Choose the correct choice";
        }
    }while(1);

}

