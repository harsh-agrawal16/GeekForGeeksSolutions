

void frontBackSplit(Node* source, Node** frontRef, Node** backRef);
Node* SortedMerge(Node*a , Node* b);


void frontBackSplit(Node* source, Node** frontRef, Node** backRef){
    Node* slow = source;
    Node* fast = source->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}


Node* SortedMerge(Node* a, Node* b){
    Node* result = NULL;

    if(a==NULL) return b;
    if(b==NULL) return a;

    if(a->data < b->data){
        result = a;
        result->next = SortedMerge(a->next, b);
    }else{
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

void compute(Node** headRef){
    Node* head = *headRef;
    Node* a;
    Node* b;

    if(head == NULL || head->next == NULL) return;

    frontBackSplit(head, &a, &b);

    compute(&a);
    compute(&b);

    *headRef = SortedMerge(a,b);
}

Node* mergeSort(Node* head){
    compute(&head);
    return head;
}