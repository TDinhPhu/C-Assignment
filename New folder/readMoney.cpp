#include <stdio.h>
#include <stdint.h>

// Chuyển số từ 1 đến 999 thành văn bản
void readThreeDigits(uint64_t num) {
    const char *digits[] = {"không", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"};

    if (num >= 100) {
        printf("%s trăm ", digits[num / 100]);
        num %= 100;
    }

    if (num >= 10) {
        printf("%s mươi ", digits[num / 10]);
        num %= 10;
    }

    if (num > 0) {
        printf("%s ", digits[num]);
    }
}

// Chuyển số tiền thành văn bản
void numberToWords(uint64_t number) {
    const char *units[] = {"", "nghìn", "triệu", "tỷ"};
    int unitIndex = 0;

    while (number > 0) {
        uint64_t threeDigits = number % 1000;
        if (threeDigits > 0) {
            printf(" %s ", units[unitIndex]);
            readThreeDigits(threeDigits);
        }
        number /= 1000;
        unitIndex++;
    }
}

int main() {
    uint64_t money;

    printf("Nhập số tiền (tối đa 255 tỷ): ");
    scanf("%llu", &money);

    if (money == 0) {
        printf("Không đồng");
    } else {
        numberToWords(money);
        printf("đồng\n");
    }

    return 0;
}
