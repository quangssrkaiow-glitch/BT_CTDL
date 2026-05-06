#include <iostream>
#include <cstring>
using namespace std;

//================== KHAI BÁO ==================
struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Node {
    SinhVien data;
    Node *link;
};

struct List {
    Node *first;
    Node *last;
};

//================== KHỞI TẠO ==================
void init(List &L) {
    L.first = L.last = NULL;
}

Node* taoNode(SinhVien sv) {
    Node *p = new Node;
    p->data = sv;
    p->link = NULL;
    return p;
}

//================== NHẬP/XUẤT ==================
void nhapSV(SinhVien &sv) {
    cout << "Ma SV: ";
    cin.getline(sv.maSV, 8);

    cout << "Ho ten: ";
    cin.getline(sv.hoTen, 50);

    cout << "Gioi tinh (0-Nu,1-Nam): ";
    cin >> sv.gioiTinh;

    cout << "Ngay sinh (ngay thang nam): ";
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
    cin.ignore(1000, '\n');

    cout << "Dia chi: ";
    cin.getline(sv.diaChi, 100);

    cout << "Lop: ";
    cin.getline(sv.lop, 12);

    cout << "Khoa: ";
    cin.getline(sv.khoa, 7);
}

void xuatSV(SinhVien sv) {
    cout << sv.maSV << " | "
         << sv.hoTen << " | "
         << (sv.gioiTinh ? "Nam" : "Nu") << " | "
         << sv.ngaySinh.ngay << "/"
         << sv.ngaySinh.thang << "/"
         << sv.ngaySinh.nam << endl;
}

void xuatDS(List L) {
    Node *p = L.first;
    while(p != NULL) {
        xuatSV(p->data);
        p = p->link;
    }
}

//================== CHÈN THEO THỨ TỰ MSSV ==================
void chenTangTheoMa(List &L, SinhVien sv) {
    Node *p = taoNode(sv);

    if(L.first == NULL) {
        L.first = L.last = p;
        return;
    }

    if(strcmp(sv.maSV, L.first->data.maSV) < 0) {
        p->link = L.first;
        L.first = p;
        return;
    }

    Node *q = L.first;
    while(q->link != NULL &&
          strcmp(q->link->data.maSV, sv.maSV) < 0) {
        q = q->link;
    }

    p->link = q->link;
    q->link = p;

    if(p->link == NULL)
        L.last = p;
}

//================== SO SÁNH NGÀY ==================
bool trungNgay(Ngay a, Ngay b) {
    return a.ngay == b.ngay &&
           a.thang == b.thang &&
           a.nam == b.nam;
}

//================== TÌM SV TRÙNG NGÀY SINH ==================
void timSVCungNgaySinh(List L) {
    Node *p, *q;
    bool found = false;

    for(p = L.first; p != NULL; p = p->link) {
        for(q = p->link; q != NULL; q = q->link) {
            if(trungNgay(p->data.ngaySinh, q->data.ngaySinh)) {
                xuatSV(p->data);
                xuatSV(q->data);
                cout << "-------------------\n";
                found = true;
            }
        }
    }

    if(!found)
        cout << "Khong co sinh vien trung ngay sinh\n";
}

//================== XÓA SV TRÙNG NGÀY ==================
void xoaSVCungNgaySinh(List &L) {
    for(Node *p = L.first; p != NULL; p = p->link) {
        Node *prev = p;
        Node *q = p->link;

        while(q != NULL) {
            if(trungNgay(p->data.ngaySinh, q->data.ngaySinh)) {
                Node *tmp = q;
                prev->link = q->link;
                q = q->link;
                delete tmp;
            } else {
                prev = q;
                q = q->link;
            }
        }
    }
}

//================== MAIN ==================
int main() {
    List L;
    init(L);

    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    cin.ignore(1000, '\n');

    for(int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "\nNhap SV thu " << i + 1 << ":\n";
        nhapSV(sv);
        chenTangTheoMa(L, sv);
    }

    cout << "\nDanh sach sau khi sap xep:\n";
    xuatDS(L);

    SinhVien moi;
    cout << "\nNhap sinh vien moi:\n";
    nhapSV(moi);
    chenTangTheoMa(L, moi);

    cout << "\nDanh sach sau khi them:\n";
    xuatDS(L);

    cout << "\nCac sinh vien trung ngay sinh:\n";
    timSVCungNgaySinh(L);

    xoaSVCungNgaySinh(L);

    cout << "\nDanh sach sau khi xoa sinh vien trung ngay sinh:\n";
    xuatDS(L);

    return 0;
}