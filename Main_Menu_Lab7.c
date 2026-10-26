#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ================================================
// KHAI BÁO NGUYÊN MẪU HÀM (FUNCTION PROTOTYPES)
// ================================================
void hienThiMenu();
void demNguyenAmPhuAm();
void dangNhap();
void sapXepChuoi();
void doiThapPhanSangThapLucPhan();
void xoaBoDem();
void xoaXuongDong(char str[]);

// ================================================
// HÀM CHÍNH (MAIN)
// ================================================
int main() {
    int chon;

    do {
        hienThiMenu();
        scanf("%d", &chon);
        xoaBoDem(); // Xóa ký tự '\n' còn sót sau scanf

        switch (chon) {
            case 1:
                demNguyenAmPhuAm();
                break;
            case 2:
                dangNhap();
                break;
            case 3:
                sapXepChuoi();
                break;
            case 4:
                doiThapPhanSangThapLucPhan();
                break;
            case 5:
                printf("\nDa thoat chuong trinh. Tam biet!\n");
                break;
            case 6:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 5.\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 5.\n");
                break;
        }

        if (chon != 5) {
            printf("\nNhan bat ky nut de tiep tuc...");
            getchar();
        }

    } while (chon != 5);

    return 0;
}

// ================================================
// ĐỊNH NGHĨA CÁC HÀM XỬ LÝ
// ================================================

// Hàm hiển thị giao diện Menu đúng mẫu đề bài
void hienThiMenu() {
    printf("+------------------------------------------------+\n");
    printf("|          MENU CHUONG TRINH LAB 7               |\n");
    printf("+------------------------------------------------+\n");
    printf("| 1. Dem nguyen am va phu am cua chuoi           |\n");
    printf("| 2. Dang nhap bang Username va Password         |\n");
    printf("| 3. Sap xep chuoi theo chu cai                  |\n");
    printf("| 4. Doi so thap phan sang thap luc phan         |\n");
    printf("| 5. Thoat chuong trinh                          |\n");
    printf("+------------------------------------------------+\n");
    printf(">> Xin moi chon chuc nang (1-5): ");
}

// Hàm hỗ trợ xóa ký tự '\n' còn sót trong bộ đệm nhập (stdin)
void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void xoaXuongDong(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

// Chức năng 1:
void demNguyenAmPhuAm() {
    char s[100];
    int nguyenAm = 0, phuAm = 0;

    printf("\n--- 1. DEM NGUYEN AM VA PHU AM ---\n");
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    xoaXuongDong(s);

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = tolower(s[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }

    printf("Chuoi vua nhap: %s\n", s);
    printf("So nguyen am: %d\n", nguyenAm);
    printf("So phu am: %d\n", phuAm);
}

// Chức năng 2:
void dangNhap() {
    char user[50], pass[50];
    // Tài khoản mẫu
    const char userChuandian[] = "admin";
    const char passChuandian[] = "123456";

    printf("\n--- 2. DANG NHAP ---\n");
    printf("Username: ");
    fgets(user, sizeof(user), stdin);
    xoaXuongDong(user);

    printf("Password: ");
    fgets(pass, sizeof(pass), stdin);
    xoaXuongDong(pass);

    if (strcmp(user, userChuandian) == 0 && strcmp(pass, passChuandian) == 0) {
        printf(">> Dang nhap thanh cong!\n");
    } else {
        printf(">> Dang nhap pride/that bai! Sai Username hoac Password.\n");
    }
}

// Chức năng 3:
void sapXepChuoi() {
    char s[100];

    printf("\n--- 3. SAP XEP CHUOI THEO CHU CAI ---\n");
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    xoaXuongDong(s);

    int n = strlen(s);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("Chuoi sau khi sap xep: %s\n", s);
}

// Chức năng 4:
void doiThapPhanSangThapLucPhan() {
    int n;
    printf("\n--- 4. DOI THAP PHAN SANG THAP LUC PHAN ---\n");
    printf("Nhap so thap phan (nguyen duong): ");
    if (scanf("%d", &n) == 1 && n >= 0) {
        xoaBoDem(); // Xóa '\n' sau khi nhập số
        printf("Gia tri Thap luc phan (HEX): %X\n", n);
    } else {
        xoaBoDem();
        printf("Gia tri nhap vao khong hop le!\n");
    }
}