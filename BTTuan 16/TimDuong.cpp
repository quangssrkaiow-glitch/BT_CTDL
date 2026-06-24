#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *ds[11];

string ten[11] =
{ư
    "Ha Noi",
    "Thai Nguyen",
    "Bac Ninh",
    "Bac Giang",
    "Uong Bi",
    "Hai Phong",
    "Hai Duong",
    "Hung Yen",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay"
};

bool daXet[11]; // danh dau dinh da duoc tham
int truoc[11]; // luu dinh di truoc

// tao node moi
Node *taoNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// them vao cuoi DSLK
void themCuoi(Node *&head, int x)
{
    Node *p = taoNode(x);

    if(head == NULL)
    {
        head = p;
        return;
    }

    Node *q = head;

    while(q->next != NULL)
        q = q->next;

    q->next = p;
}
// them canh
void themCanh(int u, int v)
{
    themCuoi(ds[u], v);
    themCuoi(ds[v], u);
}
