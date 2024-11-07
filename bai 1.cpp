#include <iostream>
using namespace std;

struct Node {
    int giatri;       // Giá trị của node
    Node* tieptheo;   // Con trỏ đến node tiếp theo
};

// Hàm chèn một node sau node T
void chenSau(Node* T, int giatriMoi) {
    Node* nodeMoi = new Node();
    nodeMoi->giatri = giatriMoi;

    nodeMoi->tieptheo = T->tieptheo;  // Gán next của node mới trỏ đến node tiếp theo của T
    T->tieptheo = nodeMoi;            // Rồi Gán next của T trỏ đến node mới
}

// Hàm xóa node cuối trong danh sách
void xoaCuoi(Node* &nodedau) {
    if (nodedau == nullptr) return; // Danh sách trống

    if (nodedau->tieptheo == nullptr) { // Nếu chỉ 1 node
        delete nodedau;
        nodedau = nullptr;
        return;
    }

    Node* tam = nodedau;
    while (tam->tieptheo->tieptheo != nullptr) {
        tam = tam->tieptheo; // Duyệt đến node trước node cuối
    }

    delete tam->tieptheo; // Xóa node cuối
    tam->tieptheo = nullptr; // Gán next của node trước node cuối
}

// xóa một node bất kỳ được trỏ bởi T
void xoaNode(Node* &nodedau, Node* T) {
    if (T == nullptr || nodedau == nullptr) return;

    if (T == nodedau) { // Nếu node cần xóa là node đầu
        nodedau = nodedau->tieptheo;
        delete T;
        return;
    }

    Node* tam = nodedau;
    while (tam->tieptheo != T && tam->tieptheo != nullptr) {
        tam = tam->tieptheo; // Tìm node trước node cần xóa
    }

    if (tam->tieptheo == T) { // Nếu tìm thấy node trước T
        tam->tieptheo = T->tieptheo; // Bỏ qua node T
        delete T; // Giải phóng bộ nhớ của T
    }
}

// hiển thị danh sách
void hienThiDanhSach(Node* nodedau) {
    Node* hientai = nodedau;
    while (hientai != nullptr) {
        cout << hientai->giatri << " -> ";
        hientai = hientai->tieptheo;
    }
    cout << "null" << endl;
}

int main() {
    Node* danhsach = new Node();
    danhsach->giatri = 1;
    danhsach->tieptheo = nullptr;

    // Thêm các phần tử vào danh sách
    chenSau(danhsach, 2);
    chenSau(danhsach->tieptheo, 3);
    chenSau(danhsach->tieptheo->tieptheo, 4);

    cout << "Danh sách sau khi chèn: ";
    hienThiDanhSach(danhsach);

    // Xóa node cuối
    xoaCuoi(danhsach);
    cout << "Danh sách sau khi xóa node cuối: ";
    hienThiDanhSach(danhsach);

    // Xóa node đầu
    xoaNode(danhsach, danhsach);
    cout << "Danh sách sau khi xóa node đầu: ";
    hienThiDanhSach(danhsach);

    return 0;
}
