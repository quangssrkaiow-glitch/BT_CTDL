#include <iostream>  
using namespace std; 
const int V = 11; // Tổng số 11 tỉnh thành trong hệ thống giao thông
// Chỉ số mảng: 0->HN, 1->TN, 2->BN, 3->BG, 4->UB, 5->HP, 6->HD, 7->HY, 8->PL, 9->HB, 10->ST
const char* tendinh[V] = {"HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST"};
struct queue {
    int data[V + 1]; 
    int dau;                 // Vị trí đầu hàng đợi (để lấy phần tử ra)
    int cuoi;                // Vị trí cuối hàng đợi (để thêm phần tử vào)
    void khoitao() {
        dau = 0;
        cuoi = 0;
    }
    bool larong() {
        return dau == cuoi; 
    }
    void them(int gtri) {
        data[cuoi] = gtri;
        cuoi++;
    }
    int bot() {
        int gtridau = data[dau];
        dau++;
        return gtridau;
    }
};
