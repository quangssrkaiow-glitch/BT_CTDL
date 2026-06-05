#include <iostream>
using namespace std;

struct Node
{
    int namSinh;
    Node *left;
    Node *right;
};

Node* taoNode(int x)
{
    Node* p = new Node;
    p->namSinh = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* themNode(Node* goc, int x)
{
    if(goc == NULL)
        return taoNode(x);

    if(x < goc->namSinh)
        goc->left = themNode(goc->left, x);
    else
        goc->right = themNode(goc->right, x);

    return goc;
}
Node* timKiem(Node* goc, int x)
{
    if(goc == NULL || goc->namSinh == x)
        return goc;

    if(x < goc->namSinh)
        return timKiem(goc->left, x);

    return timKiem(goc->right, x);
}
