#include<bits/stdc++.h>
using namespace std;
#define ll                long long
#define vll               vector<ll>
#define fastIO            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


Node* reverse(Node* head){
    if(head == NULL) return head;

    Node* curr = head;
    Node* prev = NULL;

    while(true){
        if(curr->next == NULL){
            curr->next = prev;
            head = curr;
            return head;
        }

        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return head;
}


Node* compute(Node* head){
    Node* reverseHead = reverse(head);

    Node* curr = reverseHead;

    while(curr->next != NULL){
        if(curr->next->data >= curr->data){
            curr = curr->next;
            continue;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return reverse(reverseHead);

}