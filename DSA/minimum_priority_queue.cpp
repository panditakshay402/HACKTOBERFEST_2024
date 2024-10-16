#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;

    // Added constructor
    node(int d) {
        data = d;
        next = NULL;
    }
};

struct node* first=NULL; 

void insert(int x){
    struct node *pnode = new node(x);

    if (first==NULL) {              //case when we are making the first node
        first=pnode;
        return;             
    }
    
    /* Added a case where the node to be inserted has minimum priority/value. In this case we simply insert at head.
    This works even if theres one node in the list
    */
    if (pnode->data <= first->data) {
        pnode->next = first;
        first = pnode;
        return;
    }
    
    // Added a case where there is only one node in list and the node to be inserted doesnt have minimum priority
    if (first->next == NULL) {
        first->next = pnode;
        return;
    }

    /*follow and p can point to the first two nodes in the list
    Instead of 'null' and the first element of list
    Becase we have already handled the case where we will have to insert at head*/
    node* follow = first;
    node* p = first->next;           

    
    while(p!=NULL){
        if (follow->data <= x && x <= p->data){
            pnode->next=p;
            follow->next=pnode;
            return;                    
        }
        
        follow = p;
        p = p->next;
    }

    //If p reaches null, insert at end
    follow->next = pnode;
}

int extract() {
    //now our linked list is arranged in ascending order so we directly delete from the beginning
    if (first!=NULL) {                       
        struct node *p;
        p=first;
        first=first->next;
        int e=p->data;
        delete(p);
        cout<<"The element deleted was "<<e<<endl;
    }
  }

  int minpeek()
  {
    if (first!=NULL) {                   
    return first->data;
    }
  }

  int empty() {
    if(first==NULL) return 1;
    else return 0;
  }

  void show() {
    cout<<"The linked list from beginning is "<<endl;
    node* q=first;
    while(q!=NULL){
        cout<<q->data<<"->";
        q=q->next;
    }
    cout<<"NULL";
  }

int main()
{
    cout<<"Enter what you want to do "<<endl;
    int ch;
    
    do{
        cout<<"1.Insert\n2.Delete\n3.Peek\n4.Show list\n5.Exit"<<endl;
        cin>>ch;
        switch(ch) {
            case 1:
                cout<<"Enter the element you want to insert"<<endl;
                int x;
                cin>>x;        
                insert(x);
                break;

            case 2:
                extract();
                break;

            case 3:
                cout<<"Value with smallest priority: "<<minpeek()<<endl;
                break;

            case 4:
                show();
                cout<<endl;
                break;

            case 5:
                break;
        }
    } while(ch<=5);

    return 0;
}
