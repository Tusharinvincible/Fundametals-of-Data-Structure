#include <iostream>
using namespace std;
class Node{  // Creating linked list as a User defined DS 
    public:
    int data;            // Data section 
    Node* next;          // Pointer to next node
    Node(int x){         // Constructor 
        data=x;          // Assigning value to the data 
        next=NULL;       // next==NULL
    }
};
void print(Node* head){     // O(n)
    Node* temp=head;        // Assign head to temp node  
    while(temp!=NULL){              // Run while loop until end of linked list 
        cout<<temp->data<<"  ";     //Printing data 
        temp=temp->next;            // Changing current node to nex node 
    }
    cout<<"\n";
}
void insert(Node* &head,int val){  // Insert at beginning or head O(1) || overall O(n)
    Node* temp=head;                // Assign head to temp node  
    Node* new_node=new Node(val);   // Create new node using "new" keyword in cpp
    if(temp==NULL){        // if temp==NULL LL is empty i.e new node become its head node 
        head=new_node;      
        head->next=NULL;
        return;
    }
    while(temp->next!=NULL){    //  Run while loop until end of linked list
        temp=temp->next;        // Changing current node to nex node 
    }
    temp->next=new_node;       // add new node to last node's next
    new_node->next=NULL;
   
}
void delete_node(Node* &head,int val){    // deletion at begining or head O(1)  || overall O(n)
    Node* temp=head;      
    Node* prev=NULL;
   
    if(temp==NULL){         // If linked list is empty nothing to delete 
        return;       
    }
    while(temp->data!=val && temp!=NULL){    // Iterate over LL until we get temp->data!=val 
        prev=temp;
        temp=temp->next;
       
    }
    if(prev==NULL){             // If prev==NULL means delete the first node i.e head node
        Node* temp2=head;       
        temp=temp->next;
        head=temp;
        delete temp2;
       
    }
    else{
        if(temp!=NULL)                  // If the element is found in LL
             prev->next=temp->next;         // Change the next pointer of prev node to temp next
             
             delete temp;           // free the memory 
    }
}
void reverse(Node* &head){   //O(n)
    Node* prev=NULL;         // Define prev node as NULL 
    Node* curr=head;         // Assign head to curr node 
    Node* next_node;        // Creating next_node to store the address of currents next
    while(curr!=NULL){     // Iterate till end of LL
        next_node=curr->next;   // stor the address of curr next node in next_node 
        curr->next=prev;      // Changing curr to prev
        prev=curr;              // changing prev to curr node 
        curr=next_node;         // Changing curr node to next node 
    
    }
    head=prev;      // Changing head to prev node 

}
bool search_node(Node* &head,int val){    // worst case -> O(n)  || best case->O(1)
    Node* temp=head;                        // Assign head to temp node 
    while(temp->data!=val && temp!=NULL){   // Iterate over LL until we find val
        temp=temp->next;
    }
    if(temp==NULL){     // if we reach at the null ptr i.e element is not found
        return false;   // return false
    }
    return true;       // return true

}

int main()
{
    Node* head=NULL;
    cout<<sizeof(Node)<<endl;
    insert(head,1);  // Insert node 
    insert(head,2);
    insert(head,3);
    insert(head,4);
    cout<<"Printing linked list : ";
    print(head);
    delete_node(head,1);  // Delete node 
    cout<<"Printing linked list : ";
    print(head);  
    reverse(head);  // Reversing linked list
    cout<<"Printing List list in reversing manner : ";
    print(head);
    insert(head,1);
    insert(head,10);
    cout<<"Printing linked list : ";
    print(head);
    if(search_node(head,10)){
        cout<<"Element found 10";
    }
    else{
        cout<<"Element Not found";
    }

    return 0;
}