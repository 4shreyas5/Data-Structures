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
    void insert(int el, int p);
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

    Node * temp = head;
    int x = 0;
    while (temp->data != el){
        temp = temp -> next; x++;
        if (temp == 0){ cout<<"Element Does Not Exists"<<endl; break; }
    }
    if (temp->data == el){
        cout<<"Element found at index "<<x<<endl;
    }
}

// void List :: insert (int el, int p){

//     Node * temp = head ;
//     int c = 0;
//     while(c < p-1){
//         temp = temp -> next;
//         c++;
//     }
//     temp->next = new Node(el,temp->next);
    
// }



void List :: display(){

    Node * temp = head;
    while(temp != 0){
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
    l.deletehead();
    l.deletetail();
    l.search(2);
    l.search(5);
    l.search(3);
    l.search(100);
    // l.insert(8,2);

    l.display();

    return 0;
}