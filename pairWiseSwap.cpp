Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
    Node* temp = head;
    
    Node* prev = NULL;
    int  k = 0;
    
    while(k++<2 && temp!=NULL){
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    
    if(temp!=NULL) head->next = pairWiseSwap(temp);
    
    return prev;
 