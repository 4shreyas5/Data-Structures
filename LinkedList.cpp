#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node * next;

    Node(){
        data = 0;
        next = 0;
    }
    Node (int i, Node* n){
        data = i;
        next = n;
    }

};

class List {

    Node * head, * tail;
    public:
    List (){
        head = tail = 0;
    }
    
    void addtohead(int el);
    void addtotail(int el);
    void deletehead();
    void deletetail();
    void search(int el);
    void insertAtIndex(int el, int p);
    void middle();
    void display();

};

void List :: addtohead(int el){
    
     head = new Node(el,head);
     if (tail == 0){
        tail = head;
     }

}

void List :: addtotail(int el){

     tail->next = new Node (el,0);
     tail = tail->next;

}

void List :: deletehead(){

    Node * temp = head;
    head = temp->next;
    delete temp;
}

void List :: deletetail(){

    Node * temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = NULL;
    tail = temp;
    delete todelete;
    
    
}

void List :: search (int el){

    Node *temp = head;
    int a = 0;
    for (int x = 0; temp -> next !=0 ; x++ ){
        temp = temp -> next;
         if (temp->data == el){
            a++;
        cout<<"Element found at index "<<x<<endl;
    }
    }
    if (a == 0){cout<<"Element Does Not Exists"<<endl;}
   
}

void List :: insertAtIndex (int el, int p){

    Node * temp = head;
    for (int i = 0; i<p-1; i++){
        temp = temp -> next;
    }
    temp -> next = new Node (el, temp -> next);    
}



void List :: display(){

    Node *temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;

}

int main (){
    List l;
    l.addtohead(5);
    l.addtohead(4);
    l.addtohead(3);
    l.addtohead(2);
    l.addtohead(1);
    l.addtotail(6);
    l.deletetail();
    l.search(2);
    l.search(5);
    l.search(3);
    l.search(100);
    l.insertAtIndex(8,2);
    l.display();

    return 0;
}