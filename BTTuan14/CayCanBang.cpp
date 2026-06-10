#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
// chiều cao của cây
int height(Node* p) {
    if (p == NULL)
        return 0;
    return p->height;
}
// tạo nút
Node* taoNode(int x) {
    Node* p = new Node;

    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}
