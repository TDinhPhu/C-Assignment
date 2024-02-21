#include <iostream>
#include "QuanLySinhVien.h"

int main()
{
    QuanLySinhVien quanLy;
    int choice;

    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Them sinh vien\n";
        std::cout << "2. Sua diem sinh vien\n";
        std::cout << "3. Xoa sinh vien\n";
        std::cout << "4. Danh sach sinh vien\n";
        std::cout << "5. Sap xep sinh vien\n";
        std::cout << "0. Thoat\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string mssv;
            std::string ten;
            float diemToan, diemLy, diemHoa;
            TypeGioiTinh gioiTinh;
            int gioiTinhChoice;
            std::cout << "Nhap MSSV: ";
            std::cin >> mssv;
            std::cin.ignore();
            std::cout << "Nhap ten: ";
            std::getline(std::cin, ten);
            std::cout << "Nhap diem Toan: ";
            std::cin >> diemToan;
            std::cout << "Nhap diem Ly: ";
            std::cin >> diemLy;
            std::cout << "Nhap diem Hoa: ";
            std::cin >> diemHoa;
            std::cout << "Chon gioi tinh (0 - Nam, 1 - Nu): ";
            std::cin >> gioiTinhChoice;
            if (gioiTinhChoice == 0)
            {
                gioiTinh = NAM;
            }
            else if (gioiTinhChoice == 1)
            {
                gioiTinh = NU;
            }
            else
            {
                std::cout << "Lua chon gioi tinh khong hop le.\n";
                continue;
            }
            quanLy.themSinhVien(SinhVien(mssv, ten, (diemToan + diemLy + diemHoa) / 3, gioiTinh, diemToan, diemLy, diemHoa));
            break;
        }
        case 2:
        {
            std::string mssv;
            float diem;
            std::string monHoc;
            std::cout << "Nhap MSSV can sua diem: ";
            std::cin >> mssv;
            std::cout << "Nhap mon hoc can sua diem (Toan, Ly, Hoa): ";
            std::cin >> monHoc;
            std::cout << "Nhap diem moi: ";
            std::cin >> diem;
            quanLy.suaSinhVien(mssv, diem, monHoc);
            break;
        }
        case 3:
        {
            std::string mssv;
            std::cout << "Nhap MSSV can xoa: ";
            std::cin >> mssv;
            quanLy.xoaSinhVien(mssv);
            break;
        }
        case 4:
            quanLy.hienThiDanhSachSinhVien();
            break;
        case 5:
        {
            int sapXepChoice;
            std::cout << "Chon tieu chi sap xep:\n";
            std::cout << "1. Theo ten\n";
            std::cout << "2. Theo MSSV\n";
            std::cout << "3. Theo diem trung binh\n";
            std::cin >> sapXepChoice;

            TypeSapXep sapXep;
            switch (sapXepChoice)
            {
            case 1:
                sapXep = THEO_TEN;
                break;
            case 2:
                sapXep = THEO_MSSV;
                break;
            case 3:
                sapXep = THEO_DIEM_TRUNG_BINH;
                break;
            default:
                std::cout << "Lua chon khong hop le.\n";
                continue;
            }
            quanLy.sapXepSinhVien(sapXep);
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Lua chon khong hop le.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
