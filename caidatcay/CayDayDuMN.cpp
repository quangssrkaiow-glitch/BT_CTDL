#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};
//tạo nốt
Node* buildTree() {

    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');
    Node* K = new Node('K');

    // level 1
    A->left = B;
    A->right = C;

    // level 2
    B->left = D;
    B->right = E;

    C->left = F;
    C->right = G;

    // level 3
    D->left = H;
    D->right = I;

    E->left = J;
    E->right = K;

    // F, G, H, I, J, K là lá (NULL con)

    return A; //gốc
}
