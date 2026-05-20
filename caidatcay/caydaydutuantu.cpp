#include <iostream>
using namespace std;

#define MAXLENGTH 100
#define NIL -1

typedef int DataType;
typedef int Node;

struct Tree {
    DataType Data[MAXLENGTH];
    int MaxNode;
};

void InitTree(Tree &T) {
    T.MaxNode = 0;
}
//Kiểm tra cây rỗng
bool EmptyTree(Tree T) {
    return T.MaxNode == 0;
}

//Xác định nút gốc trong cây
Node Root(Tree T) {
    if (!EmptyTree(T))
        return 0;

    return NIL;
}

//Con trai cua nut p
Node LeftChild(Node p, Tree T) {

    Node c = 2 * p + 1;

    if (c >= T.MaxNode)
        return NIL;

    return c;
}

//Con phai cua nut p
Node RightChild(Node p, Tree T) {

    Node c = 2 * p + 2;

    if (c >= T.MaxNode)
        return NIL;

    return c;
}

//Nhập cây
void InputTree(Tree &T) {

    int n;

    cout << "Nhap so nut: ";
    cin >> n;

    T.MaxNode = n;

    for (int i = 0; i < n; i++) {

        cout << "Nut " << i << " = ";
        cin >> T.Data[i];
    }
}
// In cây
void PrintTree(Tree T) {

    for (int i = 0; i < T.MaxNode; i++) {

        cout << "\nNut " << i
             << " = " << T.Data[i];

        Node left = LeftChild(i, T);
        Node right = RightChild(i, T);
        

        if (left != NIL)
            cout << "\n   Con trai : "
                 << T.Data[left];

        if (right != NIL)
            cout << "\n   Con phai : "
                 << T.Data[right];

        cout << endl;
    }
}

int main() {

    Tree T;

    InitTree(T);

    InputTree(T);

    cout << "\nCay nhi phan day du\n";

    PrintTree(T);

    return 0;
}
