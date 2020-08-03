Node* reverse(Node* head){
    Node* prev, *next, *curr;
    curr = head;
    prev = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}


Node* add(Node* h1, Node* h2, int carry){
    int sum;
    Node* result = NULL;
    
    //base cases
    if(h1==NULL && h2==NULL && carry){
        result = new Node(carry);
        return result;
    }
    
    if(h1==NULL){
        if(carry==0) return h2;
        sum = (h2->data + carry)%10;
        carry = (h2->data + carry)/10;
        Node* node = new Node(sum);
        result = node;
        result->next = add(h1, h2->next, carry);
        return result;
    }
    if(h2==NULL){
        if(carry==0) return h1;
        sum = (h1->data + carry)%10;
        carry = (h1->data + carry)/10;
        Node* node = new Node(sum);
        result = node;
        result->next = add(h1->next, h2, carry);
        return result;
    }
    
    
    sum = (h1->data + h2->data + carry) % 10;
    carry = (h1->data + h2->data + carry) / 10;
    
    Node* node = new Node(sum);
    result = node;
    result->next = add(h1->next, h2->next, carry);
    return result;
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node* rf = reverse(first);
    Node* rs = reverse(second);
    
    Node* result = add(rf, rs, 0);
    
    return reverse(result);
    
}