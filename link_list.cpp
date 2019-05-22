#include<stdio.h> 
#include<bits/stdc++.h> 
using namespace std;
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
/* Given a reference (pointer to pointer) to the head 
  of a list and an int, push a new node on the front 
  of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
            new Node(); 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
/* Counts the no. of occurrences of a node 
   (search_for) in a linked list (head)*/
int getCount(struct Node* head) 
{ 
    // Base case 
    if (head == NULL) 
        return 0; 
  
    // count is 1 + count of remaining list 
    return 1 + getCount(head->next); 
} 

//searching an element 
void search(struct Node * p,int data){
    if(p==NULL or (p->data != data and p->next==NULL))
    {
        cout<<"NOT FOUND"<<endl;
    }
    else{
        if(p->data==data)
        {
            cout<<"FOUND"<<endl;
        }
        else
        search(p->next,data);
    }
}



//delete entire link list
void deletelink(struct Node * p){
    if(p==NULL){
        
    cout<<"Link list freed"<<endl;
    return;}
    else
    {
        struct Node * q=NULL;
        q=p;
        p=p->next;
        free(q);
        deletelink(p);
    }
}
  
  
  
  
//detect loop in a link list

void detectloop(struct Node * p,map<struct Node *,int> m){
    cout<<"reached"<<endl;
    while(p->next!=NULL)
    {
        if(m.find(p)!=m.end()){
            cout<<"LPP present"<<endl;
            return;
        }
        
       
        m.insert(make_pair(p,1));
        p=p->next;
    
    }
    if(p->next==NULL)
        {
           cout<<"LOOP nahi"<<endl;
           
            return;
        }
}

//Floyd’s Cycle-Finding Algorithm:
//This is the fastest method. Traverse linked list using two pointers. 
//Move one pointer by one and other pointer by two.
//If these pointers meet at same node then there is a loop.  If pointers do not meet then linked list doesn’t have loop.
//https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/
















/* Driver program to test count function*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
    map<struct Node *,int> m;
    /* Use push() to construct below list 
     1->2->1->3->1  */
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 1); 
  
    /* Check the count function */
    printf("count of nodes is %d", getCount(head)); 
    search(head,6);
    //deletelink(head);
    //print(
        cout<<head->data<<endl;
        detectloop(head,m);
    return 0; 
} 
