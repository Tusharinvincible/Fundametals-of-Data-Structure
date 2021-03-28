#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* prev;
        Node* next;
        Node(int x){
            data=x;
            prev=NULL;
            next=NULL;
        }
};

void print(Node* &head){
    
    Node* temp=head;
    if(head==NULL){
        cout<<"No element empty LL";
        return;
    }
    while(temp->next!=head){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<temp->data<<"\n";
}

void insert(Node* &head,int val){
    Node* temp=head;
    Node* new_node=new Node(val);
    if(temp==NULL){
        head=new_node;
        head->next=new_node;
        head->prev=new_node;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    new_node->next=temp->next;
    new_node->prev=temp;
    temp->next=new_node;
    head->prev=new_node;
}

bool search(Node* &head,int val){
    Node* temp=head;
    if(temp==NULL){
        return false;
    }
    while(temp!=head && temp->data!=val){
        temp=temp->next;
    }
    if(temp==head){
        return false;
    }
    else{
        return true;
    }
}
void delete_node(Node* &head,int val){
    Node* temp=head;
    if(temp==NULL){
        return;
    }
    if(head->data==val){
        if(head->next!=head){
            temp->prev->next=head->next;
            
            head->next->prev=head->prev;
            head=head->next;
            delete temp;
            


        }
        else{
            delete head;
            head=NULL;
        }
        return ;
    }
    while(temp->next!=head && temp->data!=val){
        temp=temp->next;
    }
    if(temp==head){
        return;
    }
    else{
        
        Node* prev_ptr=temp->prev;
        prev_ptr->next=temp->next;
        temp->next->prev=prev_ptr;
        delete temp;
    }
}


int main(){
    Node* head=NULL;
    insert(head,1);   // Insert Node 
    insert(head,2);   
    insert(head,3);
    cout<<"Print Linked List : ";
    print(head);
    delete_node(head,1);
    cout<<"Print Linked List After Deleting node->data==1 : ";
    print(head);
    delete_node(head,3);
    cout<<"Print Linked List After Deleting node->data==3 : ";
    print(head);
    cout<<"Print Linked List After Deleting node->data==2 : ";
    delete_node(head,2);
    print(head);
   
    

    return 0;
}