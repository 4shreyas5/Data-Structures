#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        data = 0;
        next = 0;
        prev = 0;
    }
    Node (Node*p, int d, Node*n){
        prev = p;
        data = d;
        next = n;
    }
};

class List {

    Node* head,* tail;
    public:

    List (){
        head = tail = 0;
    }

    void addtohead(int el);
    void addtotail(int el);
    void deletehead();
    void deletetail();

};

void List :: addtohead(int el){
    head = new Node ();

}