#ifndef QUANLYSINHVIEN_H
#define QUANLYSINHVIEN_H

#include <list>
#include "SinhVien.h"

class QuanLySinhVien
{
private:
    std::list<SinhVien> danhSachSinhVien;

public:
    void themSinhVien(SinhVien sv);
    void suaSinhVien(std::string mssv, float diem, std::string monHoc);
    void xoaSinhVien(std::string mssv);
    void hienThiDanhSachSinhVien();
    void sapXepSinhVien(TypeSapXep sapXep);
};

#endif // QUANLYSINHVIEN_H
