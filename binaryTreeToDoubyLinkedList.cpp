/*author : Harsh Agrawal , 
  Birla Insttute of Tehnoloy , Mesra.
  */

void rec(Node** headRef, Node** tailRef, Node* root){
    
    if(root==NULL) return;
    
    Node* head = root;
    Node* tail = root;
    
    rec(&head,&tail,root->left);
    if(tail!=root){
        root->left = tail;
        tail->right = root;
    }
    
    *headRef = head;
    
    head = root;
    tail = root;
    
    rec(&head,&tail,root->right);
    
    if(head!=root){
        root->right = head;
        head->left = root;
    }
    
    *tailRef = tail;
}


Node * bToDLL(Node *root)
{
    if(root==NULL) return NULL;
    Node* head = root;
    Node* tail = root;
    
    rec(&head, &tail,root);
    
    return head;
}