Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    Node* result = NULL;
    
    if(head_A == NULL) return head_B;
    if(head_B == NULL) return head_A;
    
    if(head_A->data < head_B->data){
        result = head_A;
        result->next = sortedMerge(head_A->next, head_B);
    }else{
        result = head_B;
        result->next = sortedMerge(head_A, head_B->next);
    }
    
    return result;
}  