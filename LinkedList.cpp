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