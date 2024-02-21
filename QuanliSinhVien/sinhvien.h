#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>

typedef enum
{
    THEO_TEN,
    THEO_MSSV,
    THEO_DIEM_TRUNG_BINH
} TypeSapXep;

typedef enum
{
    NAM,
    NU
} TypeGioiTinh;

typedef enum
{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
} TypeHocLuc;

class SinhVien
{
private:
    std::string mssv;
    std::string tenSinhVien;
    float diemTrungBinh;
    TypeGioiTinh gioiTinh;
    float monToan;
    float monLy;
    float monHoa;

public:
    SinhVien(std::string mssv, std::string ten, float diem, TypeGioiTinh gioiTinh, float toan, float ly, float hoa);
    std::string getMSSV() const;
    std::string getTenSinhVien() const;
    float getDiemTrungBinh() const;
    TypeGioiTinh getGioiTinh() const;
    TypeHocLuc getHocLuc() const;
    float getMonToan() const;
    float getMonLy() const;
    float getMonHoa() const;
    void setDiemMonToan(float toan);
    void setDiemMonLy(float ly);
    void setDiemMonHoa(float hoa);
};

#endif // SINHVIEN_H
