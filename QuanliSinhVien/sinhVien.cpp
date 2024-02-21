#include "SinhVien.h"

SinhVien::SinhVien(std::string mssv, std::string ten, float diem, TypeGioiTinh gioiTinh, float toan, float ly, float hoa)
    : mssv(mssv), tenSinhVien(ten), diemTrungBinh(diem), gioiTinh(gioiTinh), monToan(toan), monLy(ly), monHoa(hoa)
{
}

std::string SinhVien::getMSSV() const
{
    return mssv;
}

std::string SinhVien::getTenSinhVien() const
{
    return tenSinhVien;
}

float SinhVien::getDiemTrungBinh() const
{
    return (monToan + monLy + monHoa) / 3;
}

TypeGioiTinh SinhVien::getGioiTinh() const
{
    return gioiTinh;
}

TypeHocLuc SinhVien::getHocLuc() const
{
    float diemTrungBinh = getDiemTrungBinh();
    if (diemTrungBinh >= 8.0)
    {
        return GIOI;
    }
    else if (diemTrungBinh >= 7.0)
    {
        return KHA;
    }
    else if (diemTrungBinh >= 5.0)
    {
        return TRUNG_BINH;
    }
    else
    {
        return YEU;
    }
}

float SinhVien::getMonToan() const
{
    return monToan;
}

float SinhVien::getMonLy() const
{
    return monLy;
}

float SinhVien::getMonHoa() const
{
    return monHoa;
}

void SinhVien::setDiemMonToan(float toan)
{
    monToan = toan;
}

void SinhVien::setDiemMonLy(float ly)
{
    monLy = ly;
}

void SinhVien::setDiemMonHoa(float hoa)
{
    monHoa = hoa;
}
