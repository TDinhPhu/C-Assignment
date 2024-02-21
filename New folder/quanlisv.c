#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef union Grade {
    int numeric;
    char letter;
} Grade;

typedef struct {
    char name[20];
    int studentID;
    Grade grade;
} Student;

void copyString(char target[], const char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        target[i] = string[i];
        i++;
    }
    target[i] = '\0';
}

void copyTarget(void *dest, const void *src, size_t n) {

    // Sao chép dữ liệu từ src đến dest theo từng byte
    for (size_t i = 0; i < n; i++) {
        ((char *)dest)[i] = ((char *)src)[i];
    }
}

bool compareString(const void* sv1, const void* sv2) {
    
    const char* name1 = ((Student*)sv1)->name;
    const char* name2 = ((Student*)sv2)->name;

    int i = 0;
    while (name1[i] != '\0' || name2[i] != '\0') {
        if (name1[i] > name2[i]) return false;
        else if (name1[i] < name2[i]) return true;
        i++;
    }
    return false;
}

bool compareID(const void* sv1, const void* sv2) {
    
    if (((Student*)sv1)->studentID > ((Student*)sv2)->studentID) return false;
    else if (((Student*)sv1)->studentID < ((Student*)sv2)->studentID) return true;
    else return false;
}

void sort(void *array, int size, int sizeType, bool (*compareFunc)(const void*, const void*)) {

    for(int i = 0; i < size - 1; i++) {
        int temp = i;
        for(int j = i + 1; j < size; j++) {
            // thuật toán: tìm giá trị bé nhất bên phải giá trị đang xét và lưu vị trí vào temp sau đó hoán đổi vị trí
            // if(array[j]  < array[temp]) temp = j;
            // chuyển đổi array từ void* thành char* để tránh báo lỗi
            if(compareFunc((const void*)((char*)array + j * sizeType), (const void*)((char*)array + temp * sizeType))) {
                temp = j;
            }
        }
        // hoán đổi giá trị cho nhau
        char tempTarget[sizeType];
        copyTarget(tempTarget, (char*)array + i * sizeType, sizeType);
        copyTarget((char*)array + i * sizeType, (char*)array + temp * sizeType, sizeType);
        copyTarget((char*)array + temp * sizeType, tempTarget, sizeType);

    }
}

int main() {

    Student students[] = {{.name = "hoang", .studentID = 6, .grade.letter = 'A'},
                          {.name = "anh", .studentID = 10, .grade.letter = 'B'},
                          {.name = "bao", .studentID = 3, .grade.letter = 'A'},
                          {.name = "yen", .studentID = 4, .grade.letter = 'B'},
                          {.name = "thong", .studentID = 5, .grade.letter = 'A'},
                          {.name = "tuan", .studentID = 8, .grade.letter = 'B'},
                          {.name = "dung", .studentID = 7, .grade.letter = 'A'}};

    int size = sizeof(students)/sizeof(students[0]);

    //sort(students, size, sizeof(Student), &compareID);
    sort(students, size, sizeof(Student), &compareString);

    for(int i = 0; i < size; i++) {
        printf("%s : %d\n", students[i].name, students[i].studentID);
    }

    return 0;
}





