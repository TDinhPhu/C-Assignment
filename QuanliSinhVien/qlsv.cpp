#include "QuanLySinhVien.h"
#include <iostream>

void QuanLySinhVien::themSinhVien(SinhVien sv)
{
    danhSachSinhVien.push_back(sv);
}

void QuanLySinhVien::suaSinhVien(std::string mssv, float diem, std::string monHoc)
{
    for (SinhVien &sv : danhSachSinhVien)
    {
        if (sv.getMSSV() == mssv)
        {
            if (monHoc == "Toan")
            {
                sv.setDiemMonToan(diem);
            }
            else if (monHoc == "Ly")
            {
                sv.setDiemMonLy(diem);
            }
            else if (monHoc == "Hoa")
            {
                sv.setDiemMonHoa(diem);
            }
            else
            {
                std::cout << "Mon hoc khong hop le. Hay nhap lai" << std::endl;
                return;
            }
            std::cout << "Da sua thong tin sinh vien co MSSV: " << mssv << std::endl;
            return;
        }
    }
    std::cout << "Khong tim thay sinh vien co MSSV: " << mssv << std::endl;
}

void QuanLySinhVien::xoaSinhVien(std::string mssv)
{
    auto it = danhSachSinhVien.begin();
    while (it != danhSachSinhVien.end())
    {
        if (it->getMSSV() == mssv)
        {
            it = danhSachSinhVien.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void QuanLySinhVien::hienThiDanhSachSinhVien()
{
    if (danhSachSinhVien.empty())
    {
        std::cout << "Danh sach sinh vien trong." << std::endl;
    }
    else
    {
        std::cout << "Danh sach sinh vien:\n";
        for (const SinhVien &sv : danhSachSinhVien)
        {
            std::cout << "MSSV: " << sv.getMSSV() << ", Ten: " << sv.getTenSinhVien() << ", Diem Trung Binh: " << sv.getDiemTrungBinh()
                      << ", Gioi Tinh: " << (sv.getGioiTinh() == NAM ? "Nam" : "Nu") << ", Diem Toan: " << sv.getMonToan()
                      << ", Diem Ly: " << sv.getMonLy() << ", Diem Hoa: " << sv.getMonHoa() << ", Hoc Luc: ";
            switch (sv.getHocLuc())
            {
            case GIOI:
                std::cout << "GIOI";
                break;
            case KHA:
                std::cout << "KHA";
                break;
            case TRUNG_BINH:
                std::cout << "TRUNG BINH";
                break;
            case YEU:
                std::cout << "YEU";
                break;
            }
            std::cout << std::endl;
        }
    }
}

void QuanLySinhVien::sapXepSinhVien(TypeSapXep sapXep)
{
    danhSachSinhVien.sort([sapXep](const SinhVien &sv1, const SinhVien &sv2)
                          {
                              switch (sapXep)
                              {
                              case THEO_TEN:
                                  return sv1.getTenSinhVien() < sv2.getTenSinhVien();
                              case THEO_MSSV:
                                  return sv1.getMSSV() < sv2.getMSSV();
                              case THEO_DIEM_TRUNG_BINH:
                                  return sv1.getDiemTrungBinh() > sv2.getDiemTrungBinh();
                              }
                              return false;
                          });
}
