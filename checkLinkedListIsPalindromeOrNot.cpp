Node* reverse(Node* head){
    Node* prev = NULL, *next, *curr = head;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

string generateString(Node* head){
    string ans = "";
    
    Node* curr = head;
    while(curr!=NULL){
        ans+=to_string(curr->data);
        curr = curr->next;
    }
    
    return ans;
}

bool isPalindrome(Node *head)
{
    string a="", b="";
    
    a = generateString(head);
    head = reverse(head);
    b = generateString(head);
    
    if(a==b) return true;
    else return false;
}