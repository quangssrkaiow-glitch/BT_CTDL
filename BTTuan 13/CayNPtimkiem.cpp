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
int main()
{
    int a[] ={2001,2002,2006,2007,2008,2004,2005,2001,1999,2004};
    int n = sizeof(a)/sizeof(a[0]);

    Node* goc = NULL;

    for(int i=0;i<n;i++)
        goc = themNode(goc,a[i]);
    cout << "\n\nTim nam sinh 2004\n";

    Node* p = timKiem(goc,2004);

    if(p != NULL)
        cout << "Tim thay nam sinh " << p->namSinh;
    else
        cout << "Khong tim thay nam sinh can tim";

    return 0;
}