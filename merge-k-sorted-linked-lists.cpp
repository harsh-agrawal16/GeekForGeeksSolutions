// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

void heapify(Node *arr[], int N, int i){

	int l = 2*i + 1;
	int r = 2*i + 2;
	int smallest = i;

	if(l<N && !arr[l] && arr[l]->data < arr[smallest]->data){
		smallest = l;
	}

	if(r<N && !arr[r] && arr[r]->data < arr[smallest]->data){
		smallest = r;
	}

	if(smallest!=i){
		swap(arr[i],arr[smallest]);
		heapify(arr,N,smallest);
	}
}

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKLists(Node *arr[], int N)
{
   // Your code hereo

   for(int i=N/2;i>=0;i--){
    	heapify(arr,N,i);
   }

   Node* head = arr[0];
   arr[0] = arr[0]->next;
   heapify(arr,N,0);

   int j=0;
   while(j<n){
   	  while(arr[j]!=NULL) j++;
   	  if(j>=n) break;
   	  temp->next = arr[j];
   	  //temp->data = arr[j]->data;
   	  arr[j] = arr[j]->next;
   	  temp = temp->next;
   	  heapify(arr,N,j);
   }

   temp->next = NULL;

   return head;

       
}
>
