#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void push(int, node**);
void traverseStack(node*);
int size(node*);
void content(node*, node*);

int main(void) {
    int aux = 0;
    node* stk = NULL;
    node* stk2 = NULL;
    
    cout << "Enter a number (Press enter to add, Ctrl + D to stop input): ";

    while(cin >> aux) {
        if(aux%2 ==0){
            push(aux, &stk2);
        }
        else{
            push(aux, &stk);
        }
        
    }

    traverseStack(stk);
    cout << endl;
    traverseStack(stk2);
    cout << endl;

    content(stk,stk2);

    return 0;
}

int size(node* stk) {
    return stk ? 1 + size(stk->next) : 0;
}

void content(node* stk, node* stk2){
    if(size(stk) > size(stk2)){
        cout<< "Odd list is largest than pair list";
    }
    else{
        cout<< "Pair list is largest than odd list";
    }
}

void push(int data, node** stk) {
    node*n = new node;
    n->data = data;

    n->next = *stk;
    *stk = n;
}

// TraverseStack used only to verify mod content
void traverseStack(node* stk) {
    if(stk) {
        cout << stk->data << "  ";
        traverseStack(stk->next);
    }
    else {
        cout << endl;
    }
}