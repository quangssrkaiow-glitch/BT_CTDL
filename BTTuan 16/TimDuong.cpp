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
// BFS tim duong di ngan nhat
void BFS(int start)
{
    int q[100];

    int phiatruoc = 0;
    int phiasau = -1;

    daXet[start] = true;
    q[++phiasau] = start;

    while(phiatruoc <= phiasau)
    {
        int u = q[phiatruoc++];

        Node *p = ds[u];

        while(p != NULL)
        {
            int v = p->data;

            if(!daXet[v])
            {
                daXet[v] = true;
                truoc[v] = u;

                q[++phiasau] = v;
            }

            p = p->next;
        }
    }
}
// in duong di
void inDuongDi(int s, int t)
{
    if(!daXet[t])
    {
        cout << "Khong ton tai duong di!";
        return;
    }

    int duongdi[20];
    int n = 0;

    while(t != s)
    {
        duongdi[n++] = t;
        t = truoc[t];
    }

    duongdi[n++] = s;

    cout << "\nDuong di tu Ha Noi den Uong Bi:\n";

    for(int i = n - 1; i >= 0; i--)
    {
        cout << ten[duongdi[i]];

        if(i > 0)
            cout << " -> ";
    }

    cout << "\nSo canh di qua: " << n - 1;
}
