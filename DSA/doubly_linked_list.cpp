#include<iostream>
using namespace std;

//execution of a doubly linked list

struct node{
    int data;
    struct node*next;
    struct node*prev;

    node(int d){ //constructor
        data=d;
        prev=NULL;
        next=NULL;
    }
};

struct node*first=NULL;

void insert(int x){
    struct node*pnode=new node(x);

    if(first==NULL){ //when we are making the very first node;
        first=pnode;
        return;
    }

    if(pnode->data <= first->data){ //suppose this is the node having minimum priority
        pnode->next=first;
        first->prev=pnode;
        first=pnode;
        return;
    }

    if(first->next == NULL){  //case where there is only one node in the list and what we are inserting doesn't have minimum priority
        first->next=pnode;
        pnode->prev=first;
        return;
    }

    struct node*follow=first;
    struct node*p=first->next;

    while(p != NULL){
        if(x == follow->data && x <= p->data){
            //we are inserting this node between follow and p pointers
            follow->next=pnode;
            pnode->prev=follow;
            pnode->next=p;
            p->prev=pnode;
            return;
        }
        follow = p;
        p = p->next;
    }
    //if p reaches null, it means follow is at the last node and we have to insert after the last node
    follow->next=pnode;
    pnode->prev=follow;
}

int deleteNode(int x){
    struct node* p=first;
    int info;

    // user is going to provide us with 5 elements to be deleted
    if(x == first->data){ // deleting the first node
        first = first->next;
        if(first != NULL)
            first->prev = NULL;
        info = p->data;
        delete p;
        return info;
    }

    while(p != NULL){
        if(x == p->data){
            if(p->next == NULL){ // We are deleting the last node
                info = p->data;
                p->prev->next = NULL;
                delete p;
                return info;
            }
            else{
                info = p->data;
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
                return info;
            }
        }
        p = p->next;
    }
    return -1; // Element not found
}

void display(){
    struct node *p=first;
    while(p != NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout << "NULL" << endl;
}

int main(){
    cout<<"Enter number of elements in LL"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements you want to store in the linked list"<<endl;
    int x;

    for(int i=1;i<=n;i++){
        cin>>x;
        insert(x);
    }
    //displaying the list
    cout << "The linked list: ";
    display();

    cout<<"Enter any five elements to be deleted"<<endl;
    for(int j=1;j<=5;j++){
        cin>>x;
        int deleted = deleteNode(x);
        if(deleted != -1)
            cout << "Deleted: " << deleted << endl;
        else
            cout << "Element not found" << endl;
    }

    //displaying the list again after deletion
    cout << "The linked list after deletion: ";
    display();

    return 0;
}

