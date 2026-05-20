#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//tạo cây lệch trái
Node* TaoCayLechTrai() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->left = n2;
    n2->left = n3;
    n3->left = n4;
    n4->left = n5;

    return n1; //gốc
}