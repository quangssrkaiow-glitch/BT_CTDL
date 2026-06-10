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
// tìm số lớn hơn
int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

// quay phải
Node* quayPhai(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
// quay trái
Node* quayTrai(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
// tính hệ số cân bằng
int getBalance(Node* p) {
    if (p == NULL)
        return 0;

    return height(p->left) - height(p->right);
}

// thêm vào cây AVL
Node* themNode(Node* root, int x) {

    if (root == NULL)
        return taoNode(x);

    if (x < root->data)
        root->left = themNode(root->left, x);

    else if (x > root->data)
        root->right = themNode(root->right, x);

    else
        return root;

    root->height =
        max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);
    // trái trái
    if (balance > 1 && x < root->left->data)
        return quayPhai(root);

    // phải phải
    if (balance < -1 && x > root->right->data)
        return quayTrai(root);

    // trái phải
    if (balance > 1 && x > root->left->data) {
        root->left = quayTrai(root->left);
        return quayPhai(root);
    }

    // phải trái
    if (balance < -1 && x < root->right->data) {
        root->right = quayPhai(root->right);
        return quayTrai(root);
    }

    return root;
}
// duyệt giữa LNR
void Duyet_giua(Node* root) {
    if (root != NULL) {
        Duyet_giua(root->left);
        cout << root->data << " ";
        Duyet_giua(root->right);
    }
}
int main() {

    int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(a) / sizeof(a[0]);

    Node* root = NULL;

    // thêm các phần tử vào cây AVL
    for (int i = 0; i < n; i++) {
        root = themNode(root, a[i]);
    }

    cout << "Cac phan tu tren cay AVL sau khi duyet LNR:\n";
    Duyet_giua(root);
    return 0;
}
