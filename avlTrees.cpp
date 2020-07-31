/* 
Author : agrwl.harsh (COdeforces)
         Harshagrawal16 (Codechef)
*/


#include <bits/stdc++.h>
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define fastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define for0(i,n)               for(ll i=0;i<n;i++)
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define pll                     pair<long,long>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795

using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;
        int height;
};

//function to get a new node
Node* newNode(int key){
    Node* node = new Node();
    node->left = node->right = NULL;
    node->height = 1;
    node->key = key;
    return node;
}


//function to update the height of a node after insertion/deletion
int getNewHeight(Node* p){
    int hl, hr;

    hl = p->left==NULL?0:p->left->height;
    hr = p->right==NULL?0:p->right->height;

    return hl>hr?hl+1:hr+1;
}

//function to return the balance factor of the node
int balancefactor(Node* p){
    int hl, hr;

    hl = p->left==NULL?0:p->left->height;
    hr = p->right==NULL?0:p->right->height;

    return hl-hr;
}

//LL rotation or right rotate
Node* LLRotate(Node* p){
    Node* pl = p->left;
    Node* plr = pl->right;
    
    p->left = plr;
    pl->right = p;

    pl->height = getNewHeight(pl);
    p->height = getNewHeight(p);

    return pl;
}


//RR rotation or left rotate
Node* RRRotate(Node* p){
    Node* pr = p->right;
    Node* prl = pr->left;
    
    p->right = prl;
    pr->left = p;

    pr->height = getNewHeight(pr);
    p->height = getNewHeight(p);

    return pr;
}


//Function to insert a new node, calls the function update height and also make the appropriate rotation to keep the tree balanced
Node* insert(Node* p, int key){
    if(p==NULL){
        return newNode(key);
    }

    if(key < p->key){
        p->left = insert(p->left, key);
    }

    else if(key >= p->key){
        p->right = insert(p->right, key);
    }

    else{
        return p;
    }
    
    p->height = getNewHeight(p);
    // cout<<p->key<<" :"<<p->height<<endl;

    if(balancefactor(p) == 2 && balancefactor(p->left)==1){
        //LL Rotate.
        p = LLRotate(p);
    }
    else if(balancefactor(p) == 2 && balancefactor(p->left)==-1){
        p->left = RRRotate(p->left);
        p = LLRotate(p);
    }
    else if(balancefactor(p) == -2 && balancefactor(p->right)== 1){
        //RL Rotate  
        p->right = LLRotate(p->right);
        p = RRRotate(p);    
    }
    else if(balancefactor(p) == -2 && balancefactor(p->right)== -1){
        //RR Rotate 
        p = RRRotate(p);    
    }
    return p;
}

Node* findInorderPredecessor(Node* p){
    Node* current = p;
    while(current->right != NULL){
        current = current->right;
    }

    return current;
}

Node* delete_(Node* p, int key){

    if(p==NULL) return p;
    
    if(p->key > key){
        p->left = delete_(p->left, key);
    }
    else if(p->key < key){
        p->right = delete_(p->right, key);
    }
    else{
        if(p->right== NULL && p->left == NULL){
            Node* temp = p;
            free(temp);
            return NULL;
        }
        else if(p->right == NULL){
            Node* temp = p;
            p = p->left;
            free(temp);
        }
        else if(p->left == NULL){
            Node* temp = p;
            p = p->right;
            free(temp);
        }
        else{
            Node* temp = findInorderPredecessor(p->left);
            p->key = temp->key;

            p->left = delete_(p->left, temp->key);
        }       
    }

    p->height = getNewHeight(p);

    int bf = balancefactor(p);

    if(bf < -1 && (balancefactor(p->right) <= -1 || balancefactor(p->right) == 0)){
        p = RRRotate(p);
    }
    else if(bf < -1 && balancefactor(p->right)>=1){
        p->right = LLRotate(p->right);
        p = RRRotate(p);
    }
    else if(bf > 1 && (balancefactor(p->left) >=1 || balancefactor(p->left) == 0)){
        p = LLRotate(p);
    }
    else if(bf > 1 && balancefactor(p->left) <=-1){
        p->left = RRRotate(p->left);
        p = LLRotate(p);
    }

    return p;
}

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
} 

int findMaximum(Node* root){
    Node* current = root;
    while(current->right!=NULL){
        current = current->right;
    }

    return current->key;
}

int main(){
     Node *root = NULL;  
     fastIO;
      
    /* Constructing tree given in  
    the above figure */
    // root = insert(root, 10);  
    // root = insert(root, 20);  
    // root = insert(root, 30);  
    // root = insert(root, 40);  
    // root = insert(root, 50);  
    // root = insert(root, 25); 
    // root = delete_(root, 50);
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    // cout << "Preorder traversal of the "
    //         "constructed AVL tree is \n";  
    // preOrder(root);  


     ll t;
     cin>>t;
     while(t--){
        ll n,k;
        cin>>n>>k;
        vll arr(n);
        root = NULL;
        for0(i,n) cin>>arr[i];

        for0(i,k){
            root = insert(root, arr[i]);
        }

        cout<<findMaximum(root)<<" ";

        ll i=0, j=k-1;
        while(j<n-1){
            root = delete_(root, arr[i++]);
            root = insert(root, arr[++j]);
            cout<<findMaximum(root)<<" ";
        }
        cout<<endl;
     }
      
    return 0;

}