#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;
typedef enum
{
    DO_AN,
    THUC_UONG
} Loai;

typedef enum
{
    PHA_CHE,
    PHUC_VU
} Vi_tri;

typedef enum
{
    CA_SANG,
    CA_CHIEU
} Thoi_gian_ca;

class ThongTinNhanVien
{
private:
    string ID;
    string TEN;
    int TUOI;
    Vi_tri VI_TRI;
    Thoi_gian_ca THOI_GIAN_CA;

public:
    ThongTinNhanVien(string ten, int tuoi, Vi_tri viTri, Thoi_gian_ca thoiGianCa);
    string getID() { return ID; }
    string getTEN() { return TEN; }
    int getTUOI() { return TUOI; }
    Vi_tri getVI_TRI() { return VI_TRI; }
    Thoi_gian_ca getTHOI_GIAN_CA() { return THOI_GIAN_CA; }
    string viTriToString(Vi_tri viTri) { return (viTri == PHA_CHE) ? "Pha che" : "Phuc vu"; }
    string thoiGianCaToString(Thoi_gian_ca thoiGianCa) { return (thoiGianCa == CA_SANG) ? "Ca sang" : "Ca chieu"; }
};

ThongTinNhanVien::ThongTinNhanVien(string ten, int tuoi, Vi_tri viTri, Thoi_gian_ca thoiGianCa)
{
    static int idNhanVien = 100;
    ID = "NV" + to_string(idNhanVien);
    idNhanVien++;
    TEN = ten;
    TUOI = tuoi;
    VI_TRI = viTri;
    THOI_GIAN_CA = thoiGianCa;
}

class DoAn
{
private:
    string ID;
    string TEN;
    Loai LOAI_DA_TU;
    float GIA;

public:
    DoAn(string ten, Loai loai, float gia);
    void setGia(float gia);
    string getID() { return ID; }
    string getTEN() { return TEN; }
    Loai getLOAI() { return LOAI_DA_TU; }
    string getLoaiChuoi() { return (LOAI_DA_TU == DO_AN) ? "TA" : "TU"; };
    float getGIA() { return GIA; }
};

void DoAn::setGia(float gia)
{
    GIA = gia;
}
DoAn::DoAn(string ten, Loai loai, float gia)
{
    static int id_do_an = 100;
    static int id_thuc_uong = 100;
    switch (loai)
    {
    case DO_AN:
        ID = "DA" + to_string(id_do_an);
        id_do_an++;
        break;
    case THUC_UONG:
        ID = "TU" + to_string(id_thuc_uong);
        id_thuc_uong++;
        break;
    default:
        cout << "Loai Do An khong hop le\n";
        break;
    }

    TEN = ten;
    LOAI_DA_TU = loai;
    GIA = gia;
}

class QuanLy
{
private:
    list<DoAn> *DATABASE_DO_AN;
    list<ThongTinNhanVien> *DATABASE_NHAN_VIEN;
    int *SO_LUONG_BAN;

public:
    QuanLy(list<DoAn> *DatabaseDoAn, int *soLuongBan, list<ThongTinNhanVien> *DatabaseNhanVien)
    {
        DATABASE_DO_AN = DatabaseDoAn;
        SO_LUONG_BAN = soLuongBan;
        DATABASE_NHAN_VIEN = DatabaseNhanVien;
    }

    void setSoBan();
    int getSoBan() { return *SO_LUONG_BAN; };
    void setMonAnThucUong();
    void displayMainMenu();
    void displayQuanLiMenu();
    void displayMonAnMenu();
    void themMon();
    void suaMon();
    void xoaMon();
    void hienThiDanhSachMon();
    void displayquanLiNhanVien();
    void themNhanVien();
    void xoaNhanVien();
    void hienThiDanhSachNhanVien();
    list<DoAn> *getDatabaseDoan()
    {
        return DATABASE_DO_AN;
    }
};

void QuanLy::displayMainMenu()
{
    cout << "\n----- Main Menu -----\n"
         << "1. Quan li\n"
         << "2. Nhan vien\n"
         << "0. Thoat\n"
         << "Nhap lua chon: ";
}

void QuanLy::displayQuanLiMenu()
{
    int choice;
    while (choice != 0)
    {
        cout << "\n----QUAN LI----\n"
             << "1. Setup so luong ban\n"
             << "2. Setup mon an/thuc uong\n"
             << "3. Quan li nhan vien\n"
             << "0. Quay lai\n"
             << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            setSoBan();
            break;
        case 2:
            displayMonAnMenu();
            break;
        case 3:
            displayquanLiNhanVien();
            break;
        case 0:
            displayMainMenu();
            break;
        default:
            cout << "Lua chon khong hop le.\n"
                 << endl;
            break;
        }
    };
}

void QuanLy::setSoBan()
{
    cout << "Vui long nhap so ban: ";
    cin >> *SO_LUONG_BAN;
    cout << "So luong ban la: "
         << *SO_LUONG_BAN
         << "\n----------" << endl;
}
void QuanLy::themMon()
{
    string ten;
    int loai;
    float gia;

    cout << "Nhap ten mon: ";
    cin.ignore();
    getline(cin, ten);

    cout << "Thuc an/thuc uong (0/1): ";
    cin >> loai;

    cout << "Gia: ";
    cin >> gia;
    Loai loaiDoAn;
    if (loai == 0)
    {
        loaiDoAn = DO_AN;
    }
    else if (loai == 1)
    {
        loaiDoAn = THUC_UONG;
    }
    else
    {
        cout << "Lua chon loai khong hop le." << endl;
        return;
    }
    DATABASE_DO_AN->push_back(DoAn(ten, loaiDoAn, gia));

    cout << "Them mon thanh cong!" << endl;
}
void QuanLy::suaMon()
{
    string id;
    cout << "Danh sach mon an/thuc uong\nID  Ten Loai Gia\n";
    for (DoAn &mon : *DATABASE_DO_AN)
    {
        cout << mon.getID() << "  " << mon.getTEN() << "  " << mon.getLOAI() << "  " << mon.getGIA() << endl;
    }

    cout << "Vui long nhap ID: ";
    cin >> id;

    for (auto it = DATABASE_DO_AN->begin(); it != DATABASE_DO_AN->end(); ++it)
    {
        if (it->getID() == id)
        {
            float inputGia;
            cout << "Gia: ";
            cin >> inputGia;
            it->setGia(inputGia);

            cout << "Sua mon thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay mon voi ID: " << id << endl;
}
void QuanLy::xoaMon()
{
    string id;
    cout << "Danh sach mon an/thuc uong\nID  Ten Loai Gia\n";
    for (DoAn &mon : *DATABASE_DO_AN)
    {
        cout << mon.getID() << "  " << mon.getTEN() << "  " << mon.getLOAI() << "  " << mon.getGIA() << endl;
    }

    cout << "Vui long nhap ID mon muon xoa: ";
    cin >> id;

    for (auto it = DATABASE_DO_AN->begin(); it != DATABASE_DO_AN->end(); ++it)
    {
        if (it->getID() == id)
        {
            it = DATABASE_DO_AN->erase(it);
            cout << "Xoa mon thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay mon voi ID: " << id << endl;
}
void QuanLy::hienThiDanhSachMon()
{

    cout << "Danh sach mon an/thuc uong\nID     Ten    Loai   Gia\n";
    for (DoAn &mon : *DATABASE_DO_AN)
    {
        cout << mon.getID() << "  " << mon.getTEN() << "    " << mon.getLoaiChuoi() << "    " << mon.getGIA() << endl;
    }
}

void QuanLy::displayMonAnMenu()
{
    int choice;
    while (choice != 0)
    {
        cout << "----- Mon An/Thuc Uong Menu -----\n"
             << "1. Them mon\n"
             << "2. Sua mon\n"
             << "3. Xoa mon\n"
             << "4. Hien thi danh sach mon\n"
             << "0. Quay lai\n"
             << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            themMon();
            break;
        case 2:
            suaMon();
            break;
        case 3:
            xoaMon();
            break;
        case 4:
            hienThiDanhSachMon();
            break;
        case 0:
            displayMainMenu();
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    };
}

void QuanLy::hienThiDanhSachNhanVien()
{
    cout << "Danh sach nhan vien:\nID      Ten   Tuoi   Vi tri      Ca\n";
    for (ThongTinNhanVien &nv : *DATABASE_NHAN_VIEN)
    {
        cout << nv.getID() << "   " << nv.getTEN() << "    " << nv.getTUOI() << "    " << nv.viTriToString(nv.getVI_TRI()) << "   " << nv.thoiGianCaToString(nv.getTHOI_GIAN_CA()) << endl;
    }
}

void QuanLy::xoaNhanVien()
{
    string id;
    cout << "Danh sach nhan vien:\nID    Ten    Tuoi   Vi tri   Ca\n";
    for (ThongTinNhanVien &nv : *DATABASE_NHAN_VIEN)
    {
        cout << nv.getID() << "   " << nv.getTEN() << "    " << nv.getTUOI() << "    " << nv.viTriToString(nv.getVI_TRI()) << "   " << nv.thoiGianCaToString(nv.getTHOI_GIAN_CA()) << endl;
    }

    cout << "Nhap ID nhan vien muon xoa: ";
    cin >> id;

    for (auto it = DATABASE_NHAN_VIEN->begin(); it != DATABASE_NHAN_VIEN->end(); ++it)
    {
        if (it->getID() == id)
        {
            it = DATABASE_NHAN_VIEN->erase(it);
            cout << "Xoa nhan vien thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay nhan vien voi ID: " << id << endl;
}
void QuanLy::themNhanVien()
{
    string ten;
    int tuoi;
    Vi_tri viTri;
    Thoi_gian_ca thoiGianCa;
    int loaiViTri, loaiCa;

    cout << "Nhap ten nhan vien: ";
    cin.ignore();
    getline(cin, ten);

    cout << "Nhap tuoi nhan vien: ";
    cin >> tuoi;

    cout << "Nhap vi tri (0 Pha che, 1 Phuc vu): ";
    cin >> loaiViTri;
    if (loaiViTri == 0)
    {
        viTri = PHA_CHE;
    }
    else if (loaiViTri == 1)
    {
        viTri = PHUC_VU;
    }

    cout << "Nhap thoi gian ca (0 Ca sang, 1 Ca chieu): ";
    cin >> loaiCa;
    if (loaiCa == 0)
    {
        thoiGianCa = CA_SANG;
    }
    else if (loaiViTri == 1)
    {
        thoiGianCa = CA_CHIEU;
    }

    DATABASE_NHAN_VIEN->push_back(ThongTinNhanVien(ten, tuoi, viTri, thoiGianCa));

    cout << "Them nhan vien thanh cong!" << endl;
}

void QuanLy::displayquanLiNhanVien()
{
    int choice;
    while (choice != 0)
    {
        cout << "----- Quan Li Nhan Vien -----\n"
             << "1. Them nhan vien\n"
             << "2. Xoa nhan vien\n"
             << "3. Danh sach nhan vien\n"
             << "0. Quay lai\n"
             << "Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            themNhanVien();
            break;
        case 2:
            xoaNhanVien();
            break;
        case 3:
            hienThiDanhSachNhanVien();
            break;
        case 0:
            displayQuanLiMenu();
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    };
}
class ThongTinDoAn
{
private:
    string TEN;
    float GIA;
    int SO_LUONG;

public:
    ThongTinDoAn(string ten, float gia, int soLuong);
    string getTen() { return TEN; }
    float getGia() { return GIA; }
    int getSoLuong() { return SO_LUONG; }
    void setSoLuong(int soLuong) { SO_LUONG = soLuong; };
};
ThongTinDoAn::ThongTinDoAn(string ten, float gia, int soLuong)
{
    TEN = ten;
    GIA = gia;
    SO_LUONG = soLuong;
}

class Ban
{
private:
    int SO_BAN;
    bool TRANG_THAI;
    list<ThongTinDoAn> DATABASE_THONG_TIN_MON;
    list<DoAn> *DATABASE_DO_AN;
    QuanLy &quanLy;
public:
    Ban(int soBan, bool trang_thai, QuanLy &ql);
    void setTrangThai(bool trang_thai);
    int getSoBan() { return SO_BAN; }
    bool getTrangThai() { return TRANG_THAI; }
    void themMon();
    void suaMon();
    void xoaMon();
    void hienThiDanhSachMon();
    float thanhToan();
};

Ban::Ban(int soBan, bool trang_thai, QuanLy &ql)
    : SO_BAN(soBan), TRANG_THAI(trang_thai), quanLy(ql) {}

void Ban::setTrangThai(bool trang_thai)
{
    TRANG_THAI = trang_thai;
}
void Ban::themMon()
{
    string id, ten;
    float gia;
    int soluong;
    cout << getSoBan();

    cout << "Danh sach mon an/thuc uong\nID      Ten     Loai      Gia\n";
    list<DoAn> *DATABASE_DO_AN = quanLy.getDatabaseDoan();
    for (DoAn &mon : *DATABASE_DO_AN)
    {
        cout << mon.getID() << "  " << mon.getTEN() << "   " << mon.getLoaiChuoi() << "     " << mon.getGIA() << endl;
    }
    cout << "Nhap ID mon: ";
    cin >> id;

    bool found = false;
    for (DoAn &mon : *DATABASE_DO_AN)
    {
        if (mon.getID() == id)
        {
            found = true;
            ten = mon.getTEN();
            gia = mon.getGIA();
        }
    }

    if (found)
    {
        cout << "Nhap so luong: ";
        cin >> soluong;
        DATABASE_THONG_TIN_MON.push_back(ThongTinDoAn(ten, gia, soluong));
        setTrangThai(true);
        cout << "Dat ban thanh cong!\n"
             << endl;
    }
    else
    {
        cout << "Khong tim thay mon voi ID: " << id << endl;
    }
}

void Ban::suaMon()
{
    string tenMon;
    int soLuongMoi;

    cout << "Danh sach mon an/thuc uong da dat:\n";
    cout << "Ten          So Luong     Gia\n";
    for (ThongTinDoAn &thongTinMon : DATABASE_THONG_TIN_MON)
    {
        cout << thongTinMon.getTen() << "        " << thongTinMon.getSoLuong() << "        " << thongTinMon.getGia() << endl;
    }
    cout << "Nhap ten mon muon sua: ";
    cin.ignore();
    getline(cin, tenMon);

    bool found = false;
    for (ThongTinDoAn &thongTinMon : DATABASE_THONG_TIN_MON)
    {
        if (thongTinMon.getTen() == tenMon)
        {
            found = true;
            cout << "Nhap so luong moi: ";
            cin >> soLuongMoi;
            thongTinMon.setSoLuong(soLuongMoi);
            cout << "Cap nhat so luong thanh cong!" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay mon voi ten: " << tenMon << endl;
    }
}
void Ban::xoaMon()
{
    string tenMon;

    cout << "Danh sach mon an/thuc uong da dat:\n";
    cout << "Ten          So Luong     Gia\n";
    for (ThongTinDoAn &thongTinMon : DATABASE_THONG_TIN_MON)
    {
        cout << thongTinMon.getTen() << "        " << thongTinMon.getSoLuong() << "        " << thongTinMon.getGia() << endl;
    }

    cout << "Nhap ten mon muon xoa: ";
    cin.ignore();
    getline(cin, tenMon);

    auto it = DATABASE_THONG_TIN_MON.begin();
    while (it != DATABASE_THONG_TIN_MON.end())
    {
        if (it->getTen() == tenMon)
        {
            it = DATABASE_THONG_TIN_MON.erase(it);
            cout << "Xoa mon thanh cong!" << endl;
            break;
        }
        else
        {
            ++it;
        }
    }

    if (it == DATABASE_THONG_TIN_MON.end())
    {
        cout << "Khong tim thay mon voi ten: " << tenMon << endl;
    }
}

void Ban::hienThiDanhSachMon()
{
    cout << "Danh sach mon an/thuc uong\nTen          So Luong     Gia\n";
    for (ThongTinDoAn &thongTinMon : DATABASE_THONG_TIN_MON)
    {
        cout << thongTinMon.getTen() << "        " << thongTinMon.getSoLuong() << "        " << thongTinMon.getGia() << endl;
    }
}
float Ban::thanhToan()
{
    float tongTien = 0;
    cout << "Danh sach mon an/thuc uong da dat:\n";
    cout << "Ten          So Luong     Gia\n";
    for (ThongTinDoAn &thongTinMon : DATABASE_THONG_TIN_MON)
    {
        cout << thongTinMon.getTen() << "        " << thongTinMon.getSoLuong() << "        " << thongTinMon.getGia() << endl;
        tongTien += thongTinMon.getGia() * thongTinMon.getSoLuong();
    }
    cout << "Tong tien: " << tongTien << " VND\n";
    return tongTien;
}

class NhanVien
{
private:
    vector<Ban> DATABASE_BAN;
    QuanLy &quanLy;
    bool banDaKhoiTao;
public:
    NhanVien(QuanLy &ql) : quanLy(ql) {}
    void displayNhanVienMenu(QuanLy ql);
    vector<Ban> &getDatabaseBan() { return DATABASE_BAN; }
};

void NhanVien::displayNhanVienMenu(QuanLy ql)
{
    int choice;
    int selectedBan;
    if (!banDaKhoiTao)
    {
        for (int i = 0; i < ql.getSoBan(); i++)
        {
            Ban ban(i + 1, true, ql);
            DATABASE_BAN.push_back(ban);
        }
        banDaKhoiTao = true;
    }
    cout << "Danh sach trang thai ban:\n";
    cout << "Ban     Trang Thai\n";

    for (Ban &ban : DATABASE_BAN)
    {
        cout << ban.getSoBan() << "           " << (ban.getTrangThai() ? "o" : "x") << endl;
    }
    cout << "Nhap ban muon dat: ";
    cin >> selectedBan;
    if (selectedBan < 1 || selectedBan > ql.getSoBan())
    {
        cout << "So ban khong hop le. Vui long chon lai." << endl;
        cout << "Nhap ban muon dat: ";
        cin >> selectedBan;
    }
    Ban &selectedTable = DATABASE_BAN[selectedBan - 1];
    if (!selectedTable.getTrangThai())
    {
        cout << "Ban dang co mon, khong the chon!\n";
        return;
    }

    while (choice != 0)
    {
        cout << "----- Quan Li Ban " << selectedTable.getSoBan() << " -----\n"
             << "1. Them mon\n"
             << "2. Sua mon\n"
             << "3. Xoa mon\n"
             << "4. Hien thi danh sach mon\n"
             << "5. Thanh toan\n"
             << "0. Quay lai\n"
             << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            selectedTable.themMon();
            selectedTable.setTrangThai(false);
            break;
        case 2:
            selectedTable.suaMon();
            break;
        case 3:
            selectedTable.xoaMon();
            break;
        case 4:
            selectedTable.hienThiDanhSachMon();
            break;
        case 5:
            selectedTable.thanhToan();
            break;
        case 0:
            ql.displayMainMenu();
            break;
        default:
            break;
        }
    }
}

int main()
{
    list<DoAn> DatabaseDoAn;
    int soLuongBan = 0;
    list<ThongTinNhanVien> DatabaseNhanVien;
    QuanLy ql(&DatabaseDoAn, &soLuongBan, &DatabaseNhanVien);
    NhanVien nv(ql);
    int choice;
    while (choice != 0)
    {
        ql.displayMainMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            ql.displayQuanLiMenu();
            break;
        case 2:
            nv.displayNhanVienMenu(ql);
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    };
    return 0;
}