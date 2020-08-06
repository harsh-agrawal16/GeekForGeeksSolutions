#include <bits/stdc++.h>
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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}


// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    if(root==NULL) return;
    map<int,int> mp; //this map is used to check whether or not a node with the same horizontal distance have been visited before.
    
    queue<pair<Node*, int>> q;
    
    mp[0] = root->data;
    q.push({root, 0});
    
    while(!q.empty()){
        Node* temp = q.front().first;
        int hd = q.front().second;
        
        q.pop();
        
        if(mp.count(hd) == 0) mp[hd] = temp->data;
        
        if(temp->left){
            q.push({temp->left,hd-1});
        }
        if(temp->right){
            q.push({temp->right,hd+1});
        }
    }
    
    for(auto itr = mp.begin(); itr!=mp.end() ; itr++){
        cout<<itr->second<<" ";
    }
}

