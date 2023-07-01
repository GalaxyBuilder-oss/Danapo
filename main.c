#include <stdio.h>
#include <conio.h>
#include "libs_s.c"
#include "validation.c"

#define MAX_ARRAY 100

typedef struct {
    char nik[17];
    char name[50];
    char dateofbirth[50];
    char address[100];
    char phonenum[15];
    char email[35];
    char username[10];
    char password[7];612811
    int serialnum;
} Data;
typedef struct {
    char nik[17];
    char balance_loan[50];
    char long_loan[50];
    char remaining_loan[50];
    char username[10];
    char password[7];
} Debitur;

char pilih;
int menupilih;
int no;
int salah = 0;
int yyyy;
static char username[10] = {}, password[10] = {};
char admin_us[] = "admin123";
char admin_pw[] = "123456";

const char* USER_DATA_IN = "%s;%s;%s;%s;%s;%s;%s;%s\n";
const char* USER_DATA_OUT = "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n";
const char* USER_DEBITUR_IN = "%s;%s;%s;%s;%s;%s\n";
const char* USER_DEBITUR_OUT = "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n";

FILE *fw, *fw1, *fo, *fo1, *fa, *fa1, *fr, *fr1;

Data user, user1, user_login, user_list[50];
Debitur loan[50], loan_user, loan_user1, loan_list[50];
time_t waktu;

///                         Prototype                      ///
void delete_account(char username_field[]);
void AdminMenu();
void AccountList();
void Transaction(char username_field[]);
void userData();
void UserMenu(char name[]);
void Login();
void SignUp(int loan, int month);
void About();
void disp_main();
void confirm(int exit1);
void Disclaimer();
void TermOfService();
void Contacts();
void transfer(char username_field[]);
void transHist(char username_fields[]);

void file_check() {
    background_color(BLACK);
    cursor(false);
    bool check_file = true;
    fr = fopen("./data.txt", "r");
    fr1 = fopen("./list_debitur.txt", "r");
    do {
        fclose(fr);
        fclose(fr1);
        outerFrame(37, 131);
        bg_content(36, 128);
        position(52, 20);
        printf("Checking file");
        for(int i = 0; i < 3; i++) {
            Sleep(250);
            position(65 + i, 20);
            printf(".");
        }
        if(fr == NULL && fr1 == NULL) {
            fw = fopen("./data.txt", "w");
            fw1 = fopen("./list_debitur.txt", "w");
            // Langsung Diisi Pengguna Pertama Sebagai Contoh
            fputs("321234567891111;Salim Hidayat;2* Februari 2002;Ciamis, Jawa barat;081224717930;Hidayatsalim004@gmail.com;salimwae;111111\n", fw);
            fputs("321234567891111;20000000;20;12;salimwae;111111\n", fw1);
            position(52, 13);
            printf("File Tidak Ada, Sedang Membuat File Baru...");
            Sleep(350);
            check_file = false;
            fclose(fw1);
            fclose(fw);
        }
        else {
            check_file = false;
        }
    } while (check_file);
    disp_main();
}
void Login_Val(char username_field[], char password_field[]) {
    int read = 0;
    int current_line = 0;
    fr = fopen("./data.txt", "r");
    int a = 0;
    while(!feof(fr)) {
        if (strcmp(username_field, admin_us) == 0 && strcmp(password_field, admin_pw) == 0) {
            read = 1;
            break;
        }
        fscanf(fr, USER_DATA_OUT, &user_login.nik, &user_login.name, &user_login.dateofbirth, &user_login.address, &user_login.phonenum, &user_login.email, &user_login.username, &user_login.password);
        if (strcmp(username_field, user_login.username) == 0 && strcmp(password_field, user_login.password) == 0) {
            read = 2;
            strcpy(user1.nik, user_login.nik);
            strcpy(user1.name, user_login.name);
            strcpy(user1.dateofbirth, user_login.dateofbirth);
            strcpy(user1.address, user_login.address);
            strcpy(user1.phonenum, user_login.phonenum);
            strcpy(user1.email, user_login.email);
            strcpy(user1.username, user_login.username);
            strcpy(user1.password, user_login.password);
            position(61, 22);
            printf("Login Sebagai %s", user_login.username);
            Sleep(650);
            fclose(fr);
            break;
        }
        else if (strcmp(username_field, user_login.username) == 0 && strcmp(password_field, user_login.password) == 1) {
            read = 3;
            break;
        }
        else read = 0;
    }
    if (read == 1) {
        fclose(fr);
        position(61, 22);
        printf("Login Sebagai Admin Sukses");
        Sleep(250);
        salah=0;
        AdminMenu();
    }
    else if (read == 2) {
        UserMenu(user_login.username);
    }
    else {
        if (read == 3) {
            position(61, 24);
            printf("Password Salah");
            Sleep(350);
            Login();
        }
        else if (read == 0) {
            if (salah == 2) {
                cursor(false);
                position(58, 24);
                printf("Apakah Anda Ingin Mendaftar?");
                position(82, 27);
                text_color(DARK_YELLOW);
                printf("YA");
                position(61, 27);
                text_color(YELLOW);
                printf("TIDAK");
                menupilih = 1;
                while ((pilih = getch()) != 13)
                {
                    if (pilih == 77) {
                        if(menupilih == 1) {
                            position(82, 27);
                            text_color(YELLOW);
                            printf("YA");
                            position(61, 27);
                            text_color(DARK_YELLOW);
                            printf("TIDAK");
                            menupilih = 0;
                        }
                        else {
                            position(82, 27);
                            text_color(DARK_YELLOW);
                            printf("YA");
                            position(61, 27);
                            text_color(YELLOW);
                            printf("TIDAK");
                            menupilih = 1;
                        }
                    }
                    else if(pilih == 75) {
                        if(menupilih == 0) {
                            position(82, 27);
                            text_color(DARK_YELLOW);
                            printf("YA");
                            position(61, 27);
                            text_color(YELLOW);
                            printf("TIDAK");
                            menupilih = 1;
                        }
                        else {
                            position(82, 27);
                            text_color(YELLOW);
                            printf("YA");
                            position(61, 27);
                            text_color(DARK_YELLOW);
                            printf("TIDAK");
                            menupilih = 0;
                        }
                    }
                }
                if (menupilih == 0) {
                    confirm(0);
                }
                else if (menupilih == 1) {
                    salah = 0;
                    disp_main();
                }

            }
            else {
                position(61, 24);
                printf("Username Salah / Tidak Ditemukan");
                Sleep(350);
                salah++;
                Login();
            }
        }
    }
}
void Login()
{
    cursor(true);
    bg_content(37, 130);
    outerFrame(37, 131);
    text_color(YELLOW);
    Logo(1);
    position(12, 3);
    printf("L  O  G  I  N");
    position(36, 13);
    printf("  MASUKKAN USERNAME  %c ", 175);
    position(36, 19);
    printf("  MASUKKAN PASSWORD  %c ", 175);
    background_color(DARK_WHITE);
    text_color(BLACK);
    position(61, 12);
    printf("                       ");
    position(61, 13);
    printf("                       ");
    position(61, 14);
    printf("                       ");
    position(61, 18);
    printf("                       ");
    position(61, 19);
    printf("                       ");
    position(61, 20);
    printf("                       ");
    username_valid(username, 62, 13);
    password_valid(password, 62, 19);
    background_color(GRAY);
    text_color(YELLOW);
    Login_Val(username, password);

}
void SignUp(int loan, int month)
{
    cursor(false);
    bg_content(36, 128);
    outerFrame(37, 131);
    HLine(128, DARK_YELLOW, 1, 7);
    text_color(YELLOW);
    Logo(2);
    position(12, 3);
    printf(" S I G N U P");
    userData(loan, month);
}
void userData(int loan, int month)
{
    int read = 0;
    cursor(true);

    position(5, 9);
    printf("NIK           : ");
    nik_valid(user.nik, 21, 9);
    position(5, 11);
    printf("Nama Lengkap  : ");
    name_valid(user.name, 21, 11);
    position(5, 13);
    printf("Tanggal Lahir : 00 / 00 / 0000");
    date_valid(user.dateofbirth, 21, 13);
    month_valid(user.dateofbirth, 26, 13);
    year_valid(user.dateofbirth, 31, 13);
    position(5, 15);
    printf("Alamat        : ");
    address_valid(user.address, 21, 15);
    position(5, 17);
    printf("No. HP        : ");
    phoneno_valid(user.phonenum, 21, 17);
    position(5, 19);
    printf("E-Mail        : ");
    email_valid(user.email, 21, 19);
    position(5, 21);
    printf("Username      : ");
    username_valid(user.username, 21, 21);
    position(5, 23);
    printf("Masukkan PIN  : ");
    password_valid(user.password, 21, 23);
    fr = fopen("./data.txt", "r");
    while(!feof(fr)) {
        fscanf(fr, USER_DATA_OUT, &user1.nik, &user1.name, &user1.dateofbirth, &user1.address, &user1.phonenum, &user1.email, &user1.username, &user1.password);
        if (strcmp(user1.nik, user.nik) == 0) {
            read = 1;
            break;
        }
        else read = 0;
    }
    fclose(fr);
    if(read == 0) {
        fa = fopen("./data.txt", "a");
        fprintf(fa, USER_DATA_IN, user.nik, user.name, user.dateofbirth, user.address, user.phonenum, user.email, user.username, user.password);
        fclose(fa);
        strcpy(loan_user.nik, user.nik);
        printf(" ", itoa(loan, loan_user.balance_loan, 10));
        printf(" ", itoa(month, loan_user.long_loan, 10));
        printf(" ", itoa(month, loan_user.remaining_loan, 10));
        fa = fopen("./list_debitur.txt", "a");
        fprintf(fa, USER_DEBITUR_IN, loan_user.nik, loan_user.balance_loan, loan_user.long_loan, loan_user.remaining_loan, user.username, user.password);
        fclose(fa);
        position(5, 25);
        printf("Berhasil Menyimpan");
        Sleep(550);
        Login();
    }
    else {
        position(5, 25);
        printf("NIK Telah Terdaftar, Ulangi Pendaftaran");
        Sleep(750);
        disp_main();
    }
}
void Payment(char username_field[])
{
    int uang = 0;
    int bulan = 0;
    int monthly = 0;
    int i = 0;
    int tamp = 0;
    waktu = time(NULL);
    struct tm t = *localtime(&waktu);
    fr = fopen("list_debitur.txt", "r");
    while(!feof(fr)) {
        fscanf(fr, USER_DEBITUR_OUT, &loan_user1.nik, &loan_user1.balance_loan, &loan_user1.long_loan, &loan_user1.remaining_loan, &loan_user1.username, &loan_user1.password);
        strcpy(loan[i].nik, loan_user1.nik);
        strcpy(loan[i].balance_loan, loan_user1.balance_loan);
        strcpy(loan[i].long_loan, loan_user1.long_loan);
        strcpy(loan[i].remaining_loan, loan_user1.remaining_loan);
        strcpy(loan[i].username, loan_user1.username);
        strcpy(loan[i].password, loan_user1.password);
        i++;
    }
    fclose(fr);
    bg_content(37, 130);
    outerFrame(37, 131);
    text_color(YELLOW);
    Logo(8);
    position(12, 3);
    printf("P A Y M E N T");
    position(4, 34);
    printf("< < Tekan Esc (Escape) Untuk Kembali");
    position(20, 7);
    printf("Masukan Jumlah Uang: ");
    scanf("%d", &uang);
    position(20, 8);
    for (int i = 0; i < 10; i++ ) {
        if(strcmp(username_field, loan[i].username) == 0) {
            tamp = atoi(loan[i].balance_loan);
            monthly = atoi(loan[i].remaining_loan);
            break;
        }
    }
    if (tamp >= uang) {
        tamp -= uang;
    }
    else {
        Payment(username_field);
    }
    for (int i = 0; i < 10; i++ ) {
        if(strcmp(username_field, loan[i].username) == 0) {
            itoa(tamp, loan[i].balance_loan, 10);
            break;
        }
    }
    int read = 0;
    for (int i = 0; i < 10; i++ ) {
        if (strcmp(loan[i].username, username_field) == 0 && strcmp(loan[i].balance_loan, "0") == 0) {
            strcpy(loan[i].balance_loan, "\0");
            read = 1;
            break;
        }
        else read = 0;
    }
    if (read == 1) {
        position(37, 18);
        printf("Pembayaran Selesai");
        position(37, 19);
        printf("Pinjaman Lunas");
        fw = fopen("list_debitur.txt", "w");
        for (int i = 0; i < 10; i++ ) {
            if(strcmp(loan[i].balance_loan, "\n") == 0) {
                // fprintf(fw, USER_DEBITUR_IN, loan[i].nik, loan[i].balance_loan, loan[i].long_loan, loan[i].remaining_loan, loan[i].username, loan[i].password);
            }
            else {
                fprintf(fw, USER_DEBITUR_IN, loan[i].nik, loan[i].balance_loan, loan[i].long_loan, loan[i].remaining_loan, loan[i].username, loan[i].password);

            }
        }
        fclose(fw);
        for (int i = 0; i < 10; i++) {
            strcpy(loan[i].nik, "\0");
            strcpy(loan[i].balance_loan, "\0");
            strcpy(loan[i].long_loan, "\0");
            strcpy(loan[i].remaining_loan, "\0");
            strcpy(loan[i].username, "\0");
            strcpy(loan[i].password, "\0");
            strcpy(loan_user.nik, "\0");
            strcpy(loan_user.balance_loan, "\0");
            strcpy(loan_user.long_loan, "\0");
            strcpy(loan_user.remaining_loan, "\0");
            strcpy(loan_user.username, "\0");
            strcpy(loan_user.password, "\0");
            strcpy(loan_user1.nik, "\0");
            strcpy(loan_user1.balance_loan, "\0");
            strcpy(loan_user1.long_loan, "\0");
            strcpy(loan_user1.remaining_loan, "\0");
            strcpy(loan_user1.username, "\0");
            strcpy(loan_user1.password, "\0");
        }
    }
    else {
        position(37, 18);
        printf("Pembayaran Selesai");
        fw = fopen("list_debitur.txt", "w");
        for (int i = 0; i < 10; i++ ) {
            if(strcmp(username_field, loan[i].username) == 0) {
                fprintf(fw, USER_DEBITUR_IN, loan[i].nik, loan[i].balance_loan, loan[i].long_loan, loan[i].remaining_loan, loan[i].username, loan[i].password);
                break;
            }
        }
        fclose(fw);
    }
    while ((pilih = getch()) != 27) {
        menupilih = 0;
    }
    Transaction(username_field);
}
void About()
{
    cursor(false);
    bg_content(37, 130);
    outerFrame(37, 131);
    background_color(GRAY);
    text_color(YELLOW);
    Logo(3);
    position(12, 3);
    printf("  A  B  O  U  T");
    background_color(YELLOW);
    text_color(DARK_YELLOW);
    position(99, 23);
    printf("                         ");
    position(98, 24);
    printf("   D I S C L A I M E R   ");
    position(97, 25);
    printf("                         ");
    background_color(DARK_YELLOW);
    text_color(YELLOW);
    position(97, 27);
    printf("                         ");
    position(98, 28);
    printf("    KETENTUAN LAYANAN    ");
    position(99, 29);
    printf("                         ");
    position(99, 31);
    printf("                         ");
    position(98, 32);
    printf("     K  O  N  T  A  K    ");
    position(97, 33);
    printf("                         ");
    menupilih = 1;
    Disclaimer();
    background_color(GRAY);
    while ((pilih = getch()) != 13) {
        if (pilih == 80) {
            if (menupilih == 1) {
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(99, 23);
                printf("                         ");
                position(98, 24);
                printf("   D I S C L A I M E R   ");
                position(97, 25);
                printf("                         ");
                background_color(YELLOW);
                text_color(DARK_YELLOW);
                position(97, 27);
                printf("                         ");
                position(98, 28);
                printf("    KETENTUAN LAYANAN    ");
                position(99, 29);
                printf("                         ");
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(99, 31);
                printf("                         ");
                position(98, 32);
                printf("     K  O  N  T  A  K    ");
                position(97, 33);
                printf("                         ");
                TermOfService();
                menupilih = 2;
            }
            else if (menupilih == 2) {
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(99, 23);
                printf("                         ");
                position(98, 24);
                printf("   D I S C L A I M E R   ");
                position(97, 25);
                printf("                         ");
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(97, 27);
                printf("                         ");
                position(98, 28);
                printf("    KETENTUAN LAYANAN    ");
                position(99, 29);
                printf("                         ");
                background_color(YELLOW);
                text_color(DARK_YELLOW);
                position(99, 31);
                printf("                         ");
                position(98, 32);
                printf("     K  O  N  T  A  K    ");
                position(97, 33);
                printf("                         ");
                Contacts();
                menupilih = 3;
            }
            else {
                background_color(YELLOW);
                text_color(DARK_YELLOW);
                position(99, 23);
                printf("                         ");
                position(98, 24);
                printf("   D I S C L A I M E R   ");
                position(97, 25);
                printf("                         ");
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(97, 27);
                printf("                         ");
                position(98, 28);
                printf("    KETENTUAN LAYANAN    ");
                position(99, 29);
                printf("                         ");
                position(99, 31);
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                printf("                         ");
                position(98, 32);
                printf("     K  O  N  T  A  K    ");
                position(97, 33);
                printf("                         ");
                Disclaimer();
                menupilih = 1;
            }
        }
        else if (pilih == 72) {
            if (menupilih == 3) {
                position(99, 23);
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                printf("                         ");
                position(98, 24);
                printf("   D I S C L A I M E R   ");
                position(97, 25);
                printf("                         ");
                background_color(YELLOW);
                text_color(DARK_YELLOW);
                position(97, 27);
                printf("                         ");
                position(98, 28);
                printf("    KETENTUAN LAYANAN    ");
                position(99, 29);
                printf("                         ");
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(99, 31);
                printf("                         ");
                position(98, 32);
                printf("     K  O  N  T  A  K    ");
                position(97, 33);
                printf("                         ");
                TermOfService();
                menupilih = 2;
            }
            else if (menupilih == 2) {
                position(99, 23);
                background_color(YELLOW);
                text_color(DARK_YELLOW);
                printf("                         ");
                position(98, 24);
                printf("   D I S C L A I M E R   ");
                position(97, 25);
                printf("                         ");
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(97, 27);
                printf("                         ");
                position(98, 28);
                printf("    KETENTUAN LAYANAN    ");
                position(99, 29);
                printf("                         ");
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(99, 31);
                printf("                         ");
                position(98, 32);
                printf("     K  O  N  T  A  K    ");
                position(97, 33);
                printf("                         ");
                Disclaimer();
                menupilih = 1;
            }
            else {
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(99, 23);
                printf("                         ");
                position(98, 24);
                printf("   D I S C L A I M E R   ");
                position(97, 25);
                printf("                         ");
                background_color(DARK_YELLOW);
                text_color(YELLOW);
                position(97, 27);
                printf("                         ");
                position(98, 28);
                printf("    KETENTUAN LAYANAN    ");
                position(99, 29);
                printf("                         ");
                background_color(YELLOW);
                text_color(DARK_YELLOW);
                position(99, 31);
                printf("                         ");
                position(98, 32);
                printf("     K  O  N  T  A  K    ");
                position(97, 33);
                printf("                         ");
                Contacts();
                menupilih = 3;
            }
        }
        else if (pilih == 27) {
            menupilih = 0;
            break;
        }
    }
    disp_main();
}
void AccountList()
{
    cursor(true);
    bool menu = true;
    Logo(7);
    position(12, 3);
    printf("A C C .   L I S T");
    text_color(YELLOW);
    position(38, 4);
    printf("> > >  List Pengguna Yang Mendaftar ");
    fr = fopen("./data.txt", "r");
    int a = 0, b = 0, c = 0, index = 0;
    while(!feof(fr)) {
        fscanf(fr, USER_DATA_OUT, &user.nik, &user.name, &user.dateofbirth, &user.address, &user.phonenum, &user.email, &user.username, &user.password);
        strcpy(user_list[index].nik, user.nik);
        strcpy(user_list[index].name, user.name);
        strcpy(user_list[index].dateofbirth, user.dateofbirth);
        strcpy(user_list[index].address, user.address);
        strcpy(user_list[index].phonenum, user.phonenum);
        strcpy(user_list[index].email, user.email);
        strcpy(user_list[index].username, user.username);
        strcpy(user_list[index].password, user.password);
        user_list[index].serialnum = index;
        if (index < 10) {
            position(44, 6 + a);
            printf("%d. %s", index + 1, user.name);
            a += 2;
        }
        index++;
        Sleep(50);
    }
    fclose(fr);
    fr = fopen("./list_debitur.txt", "r");
    a = 0;
    b = 0;
    c = 0;
    index = 0;
    while(!feof(fr)) {
        fscanf(fr, USER_DEBITUR_OUT, &loan_user.nik, &loan_user.balance_loan, &loan_user.long_loan, &loan_user.remaining_loan, &loan_user.username, &loan_user.password);
        strcpy(loan_list[index].nik, loan_user.nik);
        strcpy(loan_list[index].balance_loan, loan_user.balance_loan);
        strcpy(loan_list[index].long_loan, loan_user.long_loan);
        strcpy(loan_list[index].remaining_loan, loan_user.remaining_loan);
        strcpy(loan_list[index].username, loan_user.username);
        strcpy(loan_list[index].password, loan_user.password);
        index++;
    }
    fclose(fr);
    VLine(19, DARK_YELLOW, 80, 5);
    text_color(YELLOW);
    do {
        index = 0;
        position(82, 6);
        printf("Masukan Nama Pengguna: ");
        scanf("%d", &user.serialnum);
        for (int i = 0; i < 10; i++) {
            if (user_list[i].serialnum == user.serialnum - 1) {
                position(82, 8);
                printf("%s", user_list[i].name);
                strcpy(user1.username, user_list[i].username);
                menu = false;
                index = 1;
                break;
            }
            else index = 0;
        }
        if (index == 0) {
            position(82, 8);
            printf("Tidak Ada User");
            Sleep(350);
            position(82, 8);
            printf("              ");
            position(82, 6);
            printf("                        ");
        }
    } while(menu);
    cursor(false);
    position(84, 16);
    text_color(DARK_YELLOW);
    printf("E D I T");
    position(84, 18);
    text_color(YELLOW);
    printf("H A P U S");
    position(34, 26);
    printf("< < Tekan Esc (Escape) Untuk Kembali");
    no = 0;
    menupilih = 2;
    while((pilih = getch()) != 13) {
        if (pilih == 72) {
            if (menupilih == 2) {
                position(84, 16);
                text_color(YELLOW);
                printf("E D I T");
                position(84, 18);
                text_color(DARK_YELLOW);
                printf("H A P U S");
                menupilih = 3;
            }
            else {
                position(84, 16);
                text_color(DARK_YELLOW);
                printf("E D I T");
                position(84, 18);
                text_color(YELLOW);
                printf("H A P U S");
                menupilih = 2;
            }
        } else if (pilih == 80) {
            if (menupilih == 3) {
                position(84, 16);
                text_color(DARK_YELLOW);
                printf("E D I T");
                position(84, 18);
                text_color(YELLOW);
                printf("H A P U S");
                menupilih = 2;
            }
            else {
                position(84, 16);
                text_color(YELLOW);
                printf("E D I T");
                position(84, 18);
                text_color(DARK_YELLOW);
                printf("H A P U S");
                menupilih = 3;
            }
        }
        else if (pilih == 27) {
            position(84, 16);
            text_color(YELLOW);
            printf("E D I T");
            position(84, 18);
            text_color(YELLOW);
            printf("H A P U S");
            menupilih = 1;
            break;
        }
    }
    if (menupilih == 1) AdminMenu(); // Ke Menu Admin
    else if (menupilih == 2) AdminMenu();// Edit
    else if (menupilih == 3) delete_account(user.username);// Hapus
    else AccountList();
}
void edit_account(char username_field[]) {
    cursor(true);
    bg_content(37, 130);
    outerFrame(37, 131);
    position(34, 26);
    printf("< < Tekan Esc (Escape) Untuk Kembali");
    for (int i = 0; i < 10; i++) {
        if (user_list[i].serialnum == user.serialnum - 1) {
            position(3, 8);
            printf("%s", user_list[i].nik);
            position(3, 9);
            printf("%s", user_list[i].name);
            position(3, 10);
            printf("%s", user_list[i].dateofbirth);
            position(3, 11);
            printf("%s", user_list[i].address);
            position(3, 12);
            printf("%s", user_list[i].phonenum);
            position(3, 13);
            printf("%s", user_list[i].email);
            position(3, 14);
            printf("%s", user_list[i].username);
            position(3, 15);
            printf("%s", user_list[i].password);
            position(3, 16);
            break;
        }
    }
    while ((pilih = getch()) != 27) {
        menupilih = 0;
    }
    AccountList();
}
void delete_account(char username_field[]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(username_field, user_list[i].username) == 0) {
            strcpy(user_list[i].username, "\0");
            strcpy(loan_list[i].username, "\0");
            break;
        }
    }
    fw = fopen("data.txt", "w");
    for (int i = 0; i < 10; i++) {
        if (strcmp(user_list[i].username, "\0") == 0) {
            fputs("", fw);
        }
        else {
            fprintf(fw, USER_DATA_IN, user_list[i].nik, user_list[i].name, user_list[i].dateofbirth, user_list[i].address, user_list[i].phonenum, user_list[i].email, user_list[i].username, user_list[i].password);
        }
    }
    fclose(fw);
    fw = fopen("tamp.txt", "w");
    for (int i = 0; i < 10; i++) {
        if (strcmp(loan_list[i].username, "\0") == 0) {
            fputs("", fw);
        }
        else {
            fprintf(fa, USER_DEBITUR_IN, loan_user.nik, loan_user.balance_loan, loan_user.long_loan, loan_user.remaining_loan, user1.username, user1.password);
        }
    }
    fclose(fw);
    AdminMenu();
}
void Profile(char username_field[])
{
    cursor(false);
    int read = 0;
    background_color(GRAY);
    text_color(YELLOW);
    position(3, 28);
    printf("                    ");
    position(34, 26);
    printf("< < Tekan Esc (Escape) Untuk Kembali");
    fr = fopen("./data.txt", "r");
    while(!feof(fr)) {
        fscanf(fr, USER_DATA_OUT, &user.nik, &user.name, &user.dateofbirth, &user.address, &user.phonenum, &user.email, &user.username, &user.password);
        if (strcmp(username_field, user.username) == 0) {
            position(44, 6);
            printf(" NIK           : %s", user.nik);
            position(44, 8);
            printf(" NAMA LENGKAP  : %s", user.name);
            position(44, 10);
            printf(" TANGGAL LAHIR : %s", user.dateofbirth);
            position(44, 12);
            printf(" ALAMAT        : %s", user.address);
            position(44, 15);
            printf(" NOMOR HP      : %s", user.phonenum);
            position(44, 17);
            printf(" E-MAIL        : %s", user.email);
            break;
        }
    }
    fclose(fr);
    while ((pilih = getch()) != 27) {
        menupilih = 0;
    }
    UserMenu(user1.username);
}
void Transaction(char username_field[])
{
    if (strcmp(username_field, admin_us) == 0) {
        char username1[10];
        bg_content(37, 130);
        outerFrame(37, 131);
        HLine(128, DARK_YELLOW, 2, 6);
        VLine(6, DARK_YELLOW, 61, 5);
        text_color(YELLOW);
        Logo(4);
        position(12, 3);
        printf("A   D   M   I   N");
        position(64, 3);
        printf("Masukan Nama Pengguna : ");
        position(64, 6);
        printf("Hapus User");
        position(64, 7);
        printf("Edit User");
        position(3, 26);
        printf("< < Tekan Esc (Escape) Untuk Kembali");
        username_valid(username1, 87, 3);
        // gets(username1);
        for (int i = 0; i < sizeof(user_list); i++) {
            if (strcmp(user_list[i].username, username1) == 0)
            {
                position(64, 5);
                printf("%s\n", user_list[i].password);
                break;
            }
        }
        while ((pilih = getch()) != 27) {
            menupilih = 0;
        }
        AdminMenu();
    }
    else {
        int a;
        cursor(false);
        bg_content(37, 130);
        outerFrame(37, 131);
        HLine(128, DARK_YELLOW, 1, 6);
        text_color(YELLOW);
        Logo(4);
        position(12, 3);
        printf("%s", user1.username);
        position(25, 9);
        printf("D A T A   T R A N S A K S I");
        position(4, 34);
        printf("< < Tekan Esc (Escape) Untuk Kembali");
        int read = 0;
        fr = fopen("./list_debitur.txt", "r");
        while (!feof(fr)) {
            fscanf(fr, USER_DEBITUR_OUT, &loan_user.nik, &loan_user.balance_loan, &loan_user.long_loan, &loan_user.remaining_loan, &loan_user.username, &loan_user.password);
            if (strcmp(username_field, loan_user.username) == 0) {
                fclose(fr);
                read = 1;
                position(45, 11);
                printf("N I K Peminjam      : %s", loan_user.nik);
                position(45, 13);
                printf("Jumlah Pinjaman     : Rp.%s", loan_user.balance_loan);
                position(45, 15);
                printf("Lama Pinjaman       : %s Bulan", loan_user.long_loan);
                position(45, 17);
                printf("Sisa Pinjaman       : %s Bulan", loan_user.remaining_loan);
                position(45, 19);
                printf("Sisa Waktu Pinjaman : %s Bulan", loan_user.remaining_loan);
                break;
            }
            else read = 0;
        }
        if (read == 1 && strcmp(username_field, loan_user.username) == 0) {
            background_color(YELLOW);
            text_color(DARK_YELLOW);
            position(99, 23);
            printf("                         ");
            position(98, 24);
            printf("   P E M B A Y A R A N   ");
            position(97, 25);
            printf("                         ");
            background_color(DARK_YELLOW);
            text_color(YELLOW);
            position(97, 27);
            printf("                         ");
            position(98, 28);
            printf("    TRANSFER KE  BANK    ");
            position(99, 29);
            printf("                         ");
            position(99, 31);
            printf("                         ");
            position(98, 32);
            printf("   RIWAYAT PEMBAYARAN    ");
            position(97, 33);
            printf("                         ");
            menupilih = 1;
            background_color(GRAY);
            while ((pilih = getch()) != 13) {
                if (pilih == 80) {
                    if (menupilih == 1) {
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(99, 23);
                        printf("                         ");
                        position(98, 24);
                        printf("   P E M B A Y A R A N   ");
                        position(97, 25);
                        printf("                         ");
                        background_color(YELLOW);
                        text_color(DARK_YELLOW);
                        position(97, 27);
                        printf("                         ");
                        position(98, 28);
                        printf("    TRANSFER KE  BANK    ");
                        position(99, 29);
                        printf("                         ");
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(99, 31);
                        printf("                         ");
                        position(98, 32);
                        printf("   RIWAYAT PEMBAYARAN    ");
                        position(97, 33);
                        printf("                         ");
                        menupilih = 2;
                    }
                    else if (menupilih == 2) {
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(99, 23);
                        printf("                         ");
                        position(98, 24);
                        printf("   P E M B A Y A R A N   ");
                        position(97, 25);
                        printf("                         ");
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(97, 27);
                        printf("                         ");
                        position(98, 28);
                        printf("    TRANSFER KE  BANK    ");
                        position(99, 29);
                        printf("                         ");
                        background_color(YELLOW);
                        text_color(DARK_YELLOW);
                        position(99, 31);
                        printf("                         ");
                        position(98, 32);
                        printf("   RIWAYAT PEMBAYARAN    ");
                        position(97, 33);
                        printf("                         ");
                        menupilih = 3;
                    }
                    else {
                        background_color(YELLOW);
                        text_color(DARK_YELLOW);
                        position(99, 23);
                        printf("                         ");
                        position(98, 24);
                        printf("   P E M B A Y A R A N   ");
                        position(97, 25);
                        printf("                         ");
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(97, 27);
                        printf("                         ");
                        position(98, 28);
                        printf("    TRANSFER KE  BANK    ");
                        position(99, 29);
                        printf("                         ");
                        position(99, 31);
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        printf("                         ");
                        position(98, 32);
                        printf("   RIWAYAT PEMBAYARAN    ");
                        position(97, 33);
                        printf("                         ");
                        menupilih = 1;
                    }
                }
                else if (pilih == 72) {
                    if (menupilih == 3) {
                        position(99, 23);
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        printf("                         ");
                        position(98, 24);
                        printf("   P E M B A Y A R A N   ");
                        position(97, 25);
                        printf("                         ");
                        background_color(YELLOW);
                        text_color(DARK_YELLOW);
                        position(97, 27);
                        printf("                         ");
                        position(98, 28);
                        printf("    TRANSFER KE  BANK    ");
                        position(99, 29);
                        printf("                         ");
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(99, 31);
                        printf("                         ");
                        position(98, 32);
                        printf("   RIWAYAT PEMBAYARAN    ");
                        position(97, 33);
                        printf("                         ");
                        menupilih = 2;
                    }
                    else if (menupilih == 2) {
                        position(99, 23);
                        background_color(YELLOW);
                        text_color(DARK_YELLOW);
                        printf("                         ");
                        position(98, 24);
                        printf("   P E M B A Y A R A N   ");
                        position(97, 25);
                        printf("                         ");
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(97, 27);
                        printf("                         ");
                        position(98, 28);
                        printf("    TRANSFER KE  BANK    ");
                        position(99, 29);
                        printf("                         ");
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(99, 31);
                        printf("                         ");
                        position(98, 32);
                        printf("   RIWAYAT PEMBAYARAN    ");
                        position(97, 33);
                        printf("                         ");
                        menupilih = 1;
                    }
                    else {
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(99, 23);
                        printf("                         ");
                        position(98, 24);
                        printf("   P E M B A Y A R A N   ");
                        position(97, 25);
                        printf("                         ");
                        background_color(DARK_YELLOW);
                        text_color(YELLOW);
                        position(97, 27);
                        printf("                         ");
                        position(98, 28);
                        printf("    TRANSFER KE  BANK    ");
                        position(99, 29);
                        printf("                         ");
                        background_color(YELLOW);
                        text_color(DARK_YELLOW);
                        position(99, 31);
                        printf("                         ");
                        position(98, 32);
                        printf("   RIWAYAT PEMBAYARAN    ");
                        position(97, 33);
                        printf("                         ");
                        menupilih = 3;
                    }
                }
                else if (pilih == 27) {
                    menupilih = 0;
                    break;
                }
            }
            if (menupilih == 0) {
                UserMenu(username_field);
            }
            else if (menupilih == 1) {
                Payment(username_field);
            } else if (menupilih == 2) {
                transfer(username_field);
            } else if (menupilih == 3) {
                transHist(username_field);
            }
        }
        else {
            position(27, 23);
            printf("Data Tidak Ada.");
            while ((pilih = getch()) != 27) {
                menupilih = 0;
            }
            UserMenu(username_field);
        }
    }
}
void transHist(char username_field[]) {
    cursor(false);
    bg_content(37, 130);
    outerFrame(37, 131);
    text_color(YELLOW);
    position(4, 34);
    printf("< < Tekan Esc (Escape) Untuk Kembali");
    for (int i = 0; i < 10; i++) {
        position(4, 7 + i + 1);
        printf("%d. %s", i + 1, loan[i].balance_loan);
    }
    while ((pilih = getch()) != 27) {
        menupilih = 0;
    }
    Transaction(username_field);
}
void transfer(char username_field[]) {
    cursor(false);
    bg_content(37, 130);
    outerFrame(37, 131);
    text_color(YELLOW);
    position(4, 34);
    printf("< < Tekan Esc (Escape) Untuk Kembali");
    while ((pilih = getch()) != 27) {
        menupilih = 0;
    }
    Transaction(username_field);
}
void ApplyForLoan(char as[])
{
    int a = 0, b = 0, pinjaman = 2000000, pinjaman1 = 1000000, bulan = 6, bulan1 = 1;

    cursor(false);
    bg_content(37, 130);
    outerFrame(37, 131);
    text_color(YELLOW);
    Logo(5);
    position(12, 3);
    printf("  L  O  A  N");
    position(18, 11);
    printf("Jumlah Pinjaman");
    position(22, 12);
    printf("2 Juta                                                              20 Juta");
    position(18, 14);
    printf("Lama Pinjaman");
    position(21, 15);
    printf("6 Bulan                                                              20 Bulan");
    position(42, 18);
    printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman);
    background_color(DARK_WHITE);
    HLine(60, DARK_WHITE, 28, 12);
    HLine(60, DARK_WHITE, 28, 15);
    position(31, 12);
    text_color(DARK_YELLOW);
    printf("%c", 219);
    position(32, 15);
    text_color(DARK_YELLOW);
    printf("%c", 219);
    background_color(GRAY);
    position(42, 18);
    text_color(YELLOW);
    printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman);
    position(45, 13);
    printf("Total Pinjaman = Rp.%10d", pinjaman);
    position(46, 16);
    printf("Lama  Pinjaman = %5d Bulan", bulan);
    while((pilih = getch()) != 13)
    {
        if (pilih == 77 && a <= 51 && pinjaman < 20000000) {
            a += 3;
            if (a > 3) {
                b = a - 3;
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman += pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
            else {
                if (a <= 3) {
                    a = 3;
                    b = a - 3;
                }
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman += pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
        }
        else if (pilih == 75 && a >= 0 && pinjaman > 2000000) {
            a -= 3;
            if (a >= 0) {
                b = a + 3;
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman -= pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
            else {
                if (a >= 0) {
                    a = 3;
                }
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman -= pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
        }
        position(45, 13);
        printf("Total Pinjaman = Rp.%10d", pinjaman);
    }
    pilih = 0;
    a = b = 0;
    while((pilih = getch()) != 13)
    {
        if (pilih == 77 && a <= 52) {
            a += 4;
            if (a > 4) {
                b = a - 4;
                background_color(DARK_WHITE);
                position(32 + b, 15);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(32 + a, 15);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                bulan += bulan1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
            else {
                if (a <= 4) {
                    a = 4;
                    b = a - 4;
                }
                background_color(DARK_WHITE);
                position(32 + b, 15);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(32 + a, 15);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                bulan += bulan1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
        }
        else if (pilih == 75 && a > 0) {
            a -= 4;
            if (a >= 0) {
                b = a + 4;
                background_color(DARK_WHITE);
                position(32 + b, 15);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(32 + a, 15);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                bulan -= bulan1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
                position(42, 19);
            }
            else {
                if (a >= 0) {
                    a = 4;
                    b = a + 4;
                    background_color(DARK_WHITE);
                    position(32 + b, 15);
                    text_color(DARK_WHITE);
                    printf("%c", 219);
                    position(32 + a, 15);
                    text_color(DARK_YELLOW);
                    printf("%c", 219);
                    background_color(GRAY);
                    bulan -= bulan1;
                    position(42, 18);
                    text_color(YELLOW);
                    printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
                    position(42, 19);
                }
            }
        }
        position(45, 13);
        printf("Total Pinjaman = Rp.%10d", pinjaman);
        position(46, 16);
        printf("Lama  Pinjaman = %5d Bulan", bulan);
    }
    printf("", itoa(pinjaman, loan_user.balance_loan, 10));
    printf("", itoa(bulan, loan_user.long_loan, 10));
    printf("", itoa(bulan, loan_user.remaining_loan, 10));
    fa = fopen("./list_debitur.txt", "a");
    fprintf(fa, USER_DEBITUR_IN, user1.nik, loan_user.balance_loan, loan_user.long_loan, loan_user.remaining_loan, user1.username, user1.password);
    fclose(fa);
    UserMenu(user1.username);
}
void disp_main()
{
    int a = 0, b = 0, pinjaman = 2000000, pinjaman1 = 1000000, bulan = 6, bulan1 = 1;
    cursor(false);
    bg_content(37, 130);
    outerFrame(37, 131);
    background_color(GRAY);
    text_color(YELLOW);
    Logo(0);
    position(48, 8);
    printf("Ajukan Pinjaman Online Tanpa Jaminan");
    position(22, 9);
    printf("Hanya Dengan Nomor NIK dan Nomor Hp, Dapatkan Kredit Hingga Rp. 20.000.000 Tanpa Angunan.");
    position(56, 22);
    printf("Ajukan Pinjaman");
    position(61, 25);
    printf("Masuk");
    position(110, 3);
    printf("i. Tentang Aplikasi");
    position(18, 11);
    printf("Jumlah Pinjaman");
    position(22, 12);
    printf("2 Juta                                                              20 Juta");
    position(18, 14);
    printf("Lama Pinjaman");
    position(21, 15);
    printf("6 Bulan                                                              20 Bulan");
    position(42, 18);
    printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman);
    background_color(DARK_WHITE);
    HLine(60, DARK_WHITE, 28, 12);
    HLine(60, DARK_WHITE, 28, 15);
    position(31, 12);
    text_color(DARK_YELLOW);
    printf("%c", 219);
    position(32, 15);
    text_color(DARK_YELLOW);
    printf("%c", 219);
    background_color(GRAY);
    position(42, 18);
    text_color(YELLOW);
    printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman);
    position(45, 13);
    printf("Total Pinjaman = Rp.%10d", pinjaman);
    position(46, 16);
    printf("Lama  Pinjaman = %5d Bulan", bulan);
    position(10, 36);
    printf("Gunakan Panah Kiri Geser Slider Ke Kiri, Gunakan Panah Kanan Untuk Geser Slider Ke Kanan, Enter Untuk Confirm");
    while((pilih = getch()) != 13)
    {
        cursor(false);
        if (pilih == 77 && a <= 51 && pinjaman < 20000000) {
            a += 3;
            if (a > 3) {
                b = a - 3;
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman += pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
            else {
                if (a <= 3) {
                    a = 3;
                    b = a - 3;
                }
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman += pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
        }
        else if (pilih == 75 && a >= 0 && pinjaman > 2000000) {
            a -= 3;
            if (a >= 0) {
                b = a + 3;
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman -= pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
            else {
                if (a >= 0) {
                    a = 3;
                }
                background_color(DARK_WHITE);
                position(31 + b, 12);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(31 + a, 12);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                pinjaman -= pinjaman1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
        }
        position(45, 13);
        printf("Total Pinjaman = Rp.%10d", pinjaman);
    }
    pilih = 0;
    a = b = 0;
    position(10, 36);
    printf("Gunakan Panah Kiri Geser Slider Ke Kiri, Gunakan Panah Kanan Untuk Geser Slider Ke Kanan, Enter Untuk Confirm");
    while((pilih = getch()) != 13)
    {
        if (pilih == 77 && a <= 52) {
            a += 4;
            if (a > 4) {
                b = a - 4;
                background_color(DARK_WHITE);
                position(32 + b, 15);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(32 + a, 15);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                bulan += bulan1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
            else {
                if (a <= 4) {
                    a = 4;
                    b = a - 4;
                }
                background_color(DARK_WHITE);
                position(32 + b, 15);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(32 + a, 15);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                bulan += bulan1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
            }
        }
        else if (pilih == 75 && a > 0) {
            a -= 4;
            if (a >= 0) {
                b = a + 4;
                background_color(DARK_WHITE);
                position(32 + b, 15);
                text_color(DARK_WHITE);
                printf("%c", 219);
                position(32 + a, 15);
                text_color(DARK_YELLOW);
                printf("%c", 219);
                background_color(GRAY);
                bulan -= bulan1;
                position(42, 18);
                text_color(YELLOW);
                printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
                position(42, 19);
            }
            else {
                if (a >= 0) {
                    a = 4;
                    b = a + 4;
                    background_color(DARK_WHITE);
                    position(32 + b, 15);
                    text_color(DARK_WHITE);
                    printf("%c", 219);
                    position(32 + a, 15);
                    text_color(DARK_YELLOW);
                    printf("%c", 219);
                    background_color(GRAY);
                    bulan -= bulan1;
                    position(42, 18);
                    text_color(YELLOW);
                    printf("Cicilan Perbulan: Rp. %10d/bulan", pinjaman / bulan);
                    position(42, 19);
                }
            }
        }
        position(45, 13);
        printf("Total Pinjaman = Rp.%10d", pinjaman);
        position(46, 16);
        printf("Lama  Pinjaman = %5d Bulan", bulan);
    }
    /*
    72 - Atas
    77 - Kanan
    80 - Bawah
    75 - Kiri
     */
    no = 0;
    position(10, 36);
    printf("                                                                                                             ");
    position(10, 36);
    printf("%c Untuk Geser Menu Ke Bawah, %c Untuk Geser Menu Ke Atas, Enter Untuk Confirm Dan Tab 2x Untuk Keluar", 24, 25);
    position(56, 22);
    text_color(DARK_YELLOW);
    printf("Ajukan Pinjaman\n");
    menupilih = 1;
    background_color(GRAY);
    while ((pilih = getch()) != 13) {
        if (pilih == 80) {
            if (menupilih == 1 || menupilih == 3) {
                position(56, 22);
                text_color(YELLOW);
                printf("Ajukan Pinjaman\n");
                position(61, 25);
                text_color(DARK_YELLOW);
                printf("Masuk\n");
                position(110, 3);
                text_color(YELLOW);
                printf("i. Tentang Aplikasi");
                menupilih = 2;
            }
            else {
                position(56, 22);
                text_color(DARK_YELLOW);
                printf("Ajukan Pinjaman\n");
                position(61, 25);
                text_color(YELLOW);
                printf("Masuk\n");
                menupilih = 1;
            }
        }
        else if (pilih == 72) {
            if (menupilih == 2 || menupilih == 3) {
                position(56, 22);
                text_color(DARK_YELLOW);
                printf("Ajukan Pinjaman\n");
                position(61, 25);
                text_color(YELLOW);
                printf("Masuk\n");
                position(110, 3);
                text_color(YELLOW);
                printf("i. Tentang Aplikasi");
                menupilih = 1;
            }
            else {
                position(56, 22);
                text_color(YELLOW);
                printf("Ajukan Pinjaman\n");
                position(61, 25);
                text_color(DARK_YELLOW);
                printf("Masuk\n");
                menupilih = 2;
            }
        }
        else if (pilih == 73 || pilih == 105) {
            if (menupilih == 3) {
                position(56, 22);
                text_color(DARK_YELLOW);
                printf("Ajukan Pinjaman\n");
                position(61, 25);
                text_color(YELLOW);
                printf("Masuk\n");
                position(110, 3);
                text_color(YELLOW);
                printf("i. Tentang Aplikasi");
                menupilih = 1;
            }
            else {
                position(56, 22);
                text_color(YELLOW);
                printf("Ajukan Pinjaman\n");
                position(61, 25);
                text_color(YELLOW);
                printf("Masuk\n");
                position(110, 3);
                text_color(DARK_YELLOW);
                printf("i. Tentang Aplikasi");
                menupilih = 3;
            }
        }
        else if (pilih == 9) {
            if(no == 1) {
                menupilih = 0;
                break;
            }
            no = 1;
        }
    }
    if (menupilih == 0) {
        confirm(0);
    }
    else if (menupilih == 1) {
        SignUp(pinjaman, bulan);
    } else if (menupilih == 2) {
        Login();
    } else if (menupilih == 3) {
        About();
    }
}
void AdminMenu()
{
    cursor(false);
    bg_content(37, 130);
    outerFrame(37, 131);
    VLine(36, DARK_YELLOW, 31, 0);
    text_color(YELLOW);
    Logo(7);
    position(12, 3);
    printf("  A  D  M  I  N");
    background_color(DARK_YELLOW);
    position(5, 15);
    printf("                       ");
    position(5, 16);
    printf("    Daftar Pengguna    ");
    position(5, 17);
    printf("                       ");
    position(5, 19);
    printf("                       ");
    position(5, 20);
    printf("      Daftar Hitam     ");
    position(5, 21);
    printf("                       ");
    position(5, 23);
    printf("                       ");
    position(5, 24);
    printf("   RIWAYAT Transaksi   ");
    position(5, 25);
    printf("                       ");
    position(5, 15);
    text_color(YELLOW);
    printf("%c%c ", 219, 219);
    position(5, 16);
    text_color(YELLOW);
    printf("%c%c ", 219, 219);
    position(5, 17);
    text_color(YELLOW);
    printf("%c%c ", 219, 219);
    menupilih = 1;
    no = 0;
    while((pilih = getch()) != 13) {
        if (pilih == 72) {
            if (menupilih == 1) {
                position(5, 23);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 15);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 3;
            }
            else if (menupilih == 3) {
                position(5, 19);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 23);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 2;
            }
            else {
                position(5, 15);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 19);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 1;
            }
        }
        else if (pilih == 80) {
            if (menupilih == 3) {
                position(5, 15);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 23);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 1;
            }
            else if (menupilih == 1) {
                position(5, 19);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 15);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 2;
            }
            else {
                position(5, 23);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 19);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 3;
            }
        }
        else if (pilih == 9) {
            if (no == 1) {
                menupilih = 0;
                break;
            }
            no = 1;
        }
    }
    if (menupilih == 1) {
        background_color(GRAY);
        AccountList();
    }
    else if (menupilih == 2) {
        background_color(GRAY);
        About();
    }
    else if (menupilih == 3) {
        background_color(GRAY);
        Transaction(admin_us);
    }
    else if (menupilih == 0) {
        confirm(1);
    }

}
void UserMenu(char name[])
{
    int i = 0;
    fr = fopen("list_debitur.txt", "r");
    while (!feof(fr)) {
        fscanf(fr, USER_DEBITUR_OUT, &loan_user1.nik, &loan_user1.balance_loan, &loan_user1.long_loan, &loan_user1.remaining_loan, &loan_user1.username, &loan_user1.password);
        if (strcmp(loan_user1.username, "\0") == 0) {
        }
        else {
            strcpy(loan[i].nik, loan_user1.nik);
            strcpy(loan[i].balance_loan, loan_user1.balance_loan);
            strcpy(loan[i].long_loan, loan_user1.long_loan);
            strcpy(loan[i].remaining_loan, loan_user1.remaining_loan);
            strcpy(loan[i].username, loan_user1.username);
            strcpy(loan[i].password, loan_user1.password);
            i++;
        }
    }
    fclose(fr);
    cursor(false);
    bg_content(37, 130);
    outerFrame(37, 131);
    VLine(37, DARK_YELLOW, 31, 0);
    text_color(YELLOW);
    Logo(7);
    position(12, 3);
    printf("  U  S  E  R");
    position(12, 13);
    printf("%s", name);
    position(3, 30);
    printf("Tab 2x Untuk Logout");
    background_color(DARK_YELLOW);
    position(5, 15);
    printf("                       ");
    position(5, 16);
    printf("         Profil        ");
    position(5, 17);
    printf("                       ");
    position(5, 19);
    printf("                       ");
    position(5, 20);
    printf("       Transaksi       ");
    position(5, 21);
    printf("                       ");
    position(5, 23);
    printf("                       ");
    position(5, 24);
    printf("    Ajukan Pinjaman    ");
    position(5, 25);
    printf("                       ");
    position(5, 15);
    text_color(YELLOW);
    printf("%c%c ", 219, 219);
    position(5, 16);
    text_color(YELLOW);
    printf("%c%c ", 219, 219);
    position(5, 17);
    text_color(YELLOW);
    printf("%c%c ", 219, 219);
    menupilih = 1;
    no = 0;
    while((pilih = getch()) != 13) {
        if (pilih == 72) {
            if (menupilih == 1) {
                position(5, 23);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 15);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 3;
            }
            else if (menupilih == 3) {
                position(5, 19);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 23);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 2;
            }
            else {
                position(5, 15);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 19);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 1;
            }
        }
        else if (pilih == 80) {
            if (menupilih == 3) {
                position(5, 15);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 23);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 1;
            }
            else if (menupilih == 1) {
                position(5, 19);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 15);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 16);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 17);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 2;
            }
            else {
                position(5, 23);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 24);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 25);
                text_color(YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 19);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 20);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                position(5, 21);
                text_color(DARK_YELLOW);
                printf("%c%c ", 219, 219);
                menupilih = 3;
            }
        }
        else if (pilih == 9) {
            if (no == 1) {
                menupilih = 0;
                break;
            }
            no = 1;
        }
    }
    if (menupilih == 1) {
        Profile(name);
    }
    else if (menupilih == 2) {
        Transaction(name);
    }
    else if(menupilih == 3) {
        int read = 0;
        for (int a = 0; a < 10; a++) {
            if(strcmp(loan[a].username, name) == 0) {
                read = 1;
                break;
            }
            else {
                read = 0;
            }
        }
        if (read == 0) {
            ApplyForLoan(name);
        }
        else {
            background_color(GRAY);
            position(3, 28);
            text_color(YELLOW);
            printf("Masih Ada Pinjaman");
            Sleep(550);
            UserMenu(name);
        }
    }
    else if(menupilih == 0) {
        confirm(1);
    }

}
void Disclaimer()
{
    cursor(false);
    bg_content1(92, 28, GRAY, 1, 8);
    position(3, 7);
    printf("Disclaimer");
    position(3, 8);
    printf("1. Layanan Pinjam Meminjam Berbasis Teknologi Informasi merupakan kesepakatan perdata antara Pemberi Pinjaman dengan Penerima");
    position(3, 9);
    printf("   Pinjaman. sehingga segala risiko yang timbul dari kesepakatan tersebut ditanggung sepenuhnya oleh masing-masing pihak.");
    position(3, 10);
    printf("2. Risiko kredit atau gagal bayar ditanggung sepenuhnya oleh Pemberi Pinjaman. Tidak ada lembaga atau otoritas negara yang");
    position(3, 11);
    printf("   bertanggung jawab atas risiko gagal bayar ini.");
    position(3, 12);
    printf("3. Pemberi Pinjaman yang belum memiliki pengetahuan dan pengalaman pinjam meminjam, disarankan tidak menggunakan layanan ini.");
    position(3, 13);
    printf("4. Penerima Pinjaman harus mempertimbangkan biaya cicilan pinjaman dan biaya lainnya sesuai dengan kemampuan dalam melunasi");
    position(3, 14);
    printf("   pinjaman.");
    position(3, 15);
    printf("6. Setiap kecurangan tercatat secara digital di dunia maya dan dapat diketahui masyarakat luas di media sosial.");
    position(3, 16);
    printf("9. Setiap transaksi dan kegiatan pinjam meminjam atau pelaksanaan kesepakatan");
    position(3, 18);
    printf("   mengenai pinjam meminjam antara atau yang melibatkan Penyelenggara,");
    position(3, 19);
    printf("   Pemberi Pinjaman dan/atau Penerima Pinjaman wajib dilakukan");
    position(3, 20);
    printf("   melalui escrow account dan virtual account sebagaimana yang");
    position(3, 21);
    printf("   diwajibkan berdasarkan Peraturan Otoritas Jasa Keuangan Republik Indonesia");
    position(3, 22);
    printf("   Nomor 10/POJK.05/2022 tentang Layanan Pendanaan");
    position(3, 23);
    printf("   Bersama Berbasis Teknologi Informasi dan pelanggaran atau ketidakpatuhan");
    position(3, 24);
    printf("   terhadap ketentuan tersebut merupakan bukti telah");
    position(3, 25);
    printf("   terjadinya pelanggaran hukum oleh Penyelenggara sehingga Penyelenggara wajib");
    position(3, 26);
    printf("   menanggung ganti rugi yang diderita oleh masing-masing Pengguna sebagai akibat");
    position(3, 27);
    printf("   langsung dari pelanggaran hukum tersebut di atas tanpa mengurangi hak Pengguna yang");
    position(3, 28);
    printf("   menderita kerugian menurut Kitab Undang-Undang Hukum Perdata.");
    getch();
}
void TermOfService()
{
    cursor(false);
    bg_content1(126, 15, GRAY, 2, 6);
    bg_content1(92, 26, GRAY, 1, 8);
    position(3, 11);
    printf("Syarat Dan Ketentuan");
    position(3, 15);
    printf("1. Merupakan Warga Negara Indonesia (WNI) dengan KTP yang sah");
    position(3, 17);
    printf("2. Berusia 20-65 tahun");
    position(3, 19);
    printf("3. Memiliki penghasilan minimal Rp 3.000.000 per bulan");
    position(3, 21);
    printf("4. Informasi yang diberikan harus benar, akurat dan lengkap");
    position(3, 23);
    printf("5. Membayar cicilan tepat waktu setiap 30 hari pada tanggal 1");
    position(3, 25);
    printf("6. Maksimum suku bunga tahunan 56% (APR), sudah termasuk biaya");
    position(3, 27);
    printf("   provisi Area Layanan Danapo");
    position(3, 29);
    printf("   Danapo berizin dan diawasi oleh Otoritas Jasa Keuangan (OJK)");
}
void Contacts()
{
    cursor(false);
    bg_content1(126, 15, GRAY, 2, 6);
    bg_content1(92, 26, GRAY, 1, 8);
    text_color(YELLOW);
    position(3, 11);
    printf("K  O  N  T  A  K     K  A  M  I");
    position(3, 15);
    printf("D A N A P O PROJECT PUB UAS Pelatihan Logika Dan Algoritma (Bahasa C)");
    position(3, 17);
    printf("         ");
    position(3, 19);
    printf("NAMA: SALIM HIDAYAT");
    position(3, 21);
    printf("         ");
    position(3, 23);
    printf("KELOMPOK 7 URANUSS");
    position(3, 25);
    printf("");
    position(3, 27);
    printf("A'21 GETCH (GENERATION OF TECHNOLOGY)");
    position(3, 29);
    printf("");
}
void confirm(int exit1) {
    cursor(false);
    bg_content1(62, 5, GRAY, 30, 15);
    Frame(62, 6, DARK_YELLOW, 30, 15);
    text_color(YELLOW);
    position(47, 17);
    if (exit1 == 0) {
        printf("Apakah Anda Yakin Ingin Keluar?");
        position(76, 19);
        printf("Y/y");
        position(86, 19);
        printf("T/t");
        while((pilih = getch()) != 32) {
            if (pilih == 84 || pilih == 116) {
                menupilih = 0;
                break;
            }
            else if (pilih == 89 || pilih == 121) {
                menupilih = 1;
                break;
            }
        }
        if (menupilih == 1) {
            Sleep(550);
            exit(0);
        }
        else if (menupilih == 0) {
            disp_main();
        }
    }
    else {
        printf("Apakah Anda Yakin Ingin Logout?");
        position(76, 19);
        printf("Y/y");
        position(86, 19);
        printf("T/t");
        while((pilih = getch()) != 32) {
            if (pilih == 84 || pilih == 116) {
                menupilih = 0;
                break;
            }
            else if (pilih == 89 || pilih == 121) {
                menupilih = 1;
                break;
            }
        }
        if (menupilih == 1) {
            Sleep(150);
            Login();
        }
        else if (menupilih == 0) {
            if (strcmp(username, admin_us) == 0 && strcmp(password, admin_pw) == 0) {
                AdminMenu();
            }
            else {
                UserMenu(user1.username);
            }
        }
    }
}
void main()
{
    win_control();
    file_check();
}
