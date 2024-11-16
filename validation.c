/* File Ini Berisi Validasi */

char *nik_valid(char *nik, int x, int y)
{
    static int i, b, c;
    char input;
    static char nik1[20] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0)
    {
        if ((i == 0 && input == 51) || (i == 1 && input == 50))
        {
            position(x + i, y);
            printf("%c", input);
            nik1[i] = input;
            i++;
        }
        else if (i >= 2 && (input >= 49 && input <= 57) && i <= 15)
        {
            position(x + i, y);
            printf("%c", input);
            nik1[i] = input;
            i++;
        }
        else if (i >= 3 && (input >= 48 && input <= 57) && i <= 15)
        {
            position(x + i, y);
            printf("%c", input);
            nik1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            nik1[i] = '\0';
        }
    }
    strcpy(nik, nik1);
    return nik;
}
char *name_valid(char *name, int x, int y)
{
    int i = 0;
    char input;
    static char name1[50] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0)
    {
        if ((i < 50 && input >= 65 && input <= 90))
        {
            position(x + i, y);
            printf("%c", input);
            name1[i] = input;
            i++;
        }
        else if (input == 32 && i != 0 && name1[i - 1] != 32 && i != 50)
        {
            position(x + i, y);
            printf("%c", input);
            name1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            name1[i] = '\0';
        }
    }
    strcpy(name, name1);
    return name;
}
char *date_valid(char *date, int x, int y)
{
    int i = 0;
    char input;
    static char date1[10] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0)
    {
        if (i < 2 && input >= 48 && input <= 57)
        {
            position(x + i, y);
            printf("%c", input);
            date1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            date1[i] = '\0';
        }
    }
    i = 0;
    strcpy(date, date1);
    return date;
}
char *month_valid(char *month, int x, int y)
{
    int i = 0;
    char input;
    static char month1[10] = {};
    position(x, y);

    while ((input = getch()) != 13 || i == 0)
    {
        if (input >= 48 && input <= 57 && i < 2)
        {
            position(x + i, y);
            printf("%c", input);
            month1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            month1[i] = '\0';
        }
    }
    i = 0;
    strcat(month, "/");
    strcat(month, month1);
    return month;
}
char *year_valid(char *year, int x, int y)
{
    int i = 0;
    char input;
    static char year1[10] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0)
    {
        if (input >= 48 && input <= 57 && i < 4)
        {
            position(x + i, y);
            printf("%c", input);
            year1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            year1[i] = '\0';
        }
    }
    i = 0;
    strcat(year, "/");
    strcat(year, year1);
    return year;
}
char *username_valid(char *user1, int x, int y)
{
    int i = 0;
    char input;
    static char username[10] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0)
    {
        if (i < 20 && (input >= 97 && input <= 122) || i < 20 && (input >= 48 && input <= 57 && i != 0))
        {
            position(x + i, y);
            printf("%c", input);
            username[i] = input;
            i++;
        }
        else if (i <= 20 && (input == 95 && i != 0 && username[i - 1] != 95 && i <= 9) || (input == 46 && i != 0 && username[i - 1] != 46))
        {
            position(x + i, y);
            printf("%c", input);
            username[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            username[i] = '\0';
        }
    }
    i = 0;
    strcpy(user1, username);
    return user1;
}
char *password_valid(char password[], int x, int y)
{
    int i = 0;
    char input;
    static char password1[10] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0 || i < 6)
    {
        if (i < 8 && (input >= 48 && input <= 57) || i < 8 && (input >= 97 && input <= 122))
        {
            position(x + i, y);
            printf("%c", input);
            Sleep(50);
            position(x + i, y);
            printf("*");
            password1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            password1[i] = '\0';
        }
    }
    i = 0;
    strcpy(password, password1);
    return password;
}
char *address_valid(char address[], int x, int y)
{
    int i = 0;
    char input;
    static char address1[50] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0)
    {
        if (i <= 50 && input >= 65 && input <= 90 || i != 0 && input >= 48 && input <= 57)
        {
            position(x + i, y);
            printf("%c", input);
            address1[i] = input;
            i++;
        }
        else if ((input == 32 && i != 0 && address1[i - 1] != 32 && address1[i - 1] != 45 && address1[i - 1] != 46) || (input == 44 && i != 0 && address1[i - 1] != 44 && address1[i - 1] != 32 && address1[i - 1] != 45 && address1[i - 1] != 46) || (input == 45 && i != 0 && address1[i - 1] != 45 && address1[i - 1] != 32 && address1[i - 1] != 44 && address1[i - 1] != 46) || (input == 46 && i != 0 && address1[i - 1] != 46 && address1[i - 1] != 32 && address1[i - 1] != 44 && address1[i - 1] != 45))
        {
            position(x + i, y);
            printf("%c", input);
            address1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            address1[i] = '\0';
        }
    }
    strcpy(address, address1);
    return address;
}
char *email_valid(char *email, int x, int y)
{
    int i = 0;
    char input;
    static char email1[25] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0)
    {
        if (i < 25 && (input >= 65 && input <= 90))
        {
            position(x + i, y);
            printf("%c", input);
            email1[i] = input;
            i++;
        }
        else if ((i != 0 && input == 45 && email[i - 1] != 45 && email[i - 1] != 64 && email[i - 1] != 46) || (i != 0 && input == 46 && email[i - 1] != 46 && email[i - 1] != 64 && email[i - 1] != 44 && email[i - 1] != 45) || (i != 0 && input == 64 && email[i - 1] != 64 && email[i - 1] != 46 && email[i - 1] != 44 && email[i - 1] != 45) || (i != 0 && input >= 48 && input <= 57))
        {
            position(x + i, y);
            printf("%c", input);
            email1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            email1[i] = '\0';
        }
    }
    strcpy(email, email1);
    return email;
}
char *phoneno_valid(char phoneno[], int x, int y)
{
    int i = 0;
    char input;
    static char phoneno1[10] = {};
    position(x, y);
    while ((input = getch()) != 13 || i == 0 || i < 12)
    {
        if ((i == 1 && input == 56) || (i == 2 && phoneno1[i - 1] == 56 && input != 54) || (i == 2 && phoneno1[i - 1] == 8 && input != 52) || (i == 2 && input == 49) || (i == 2 && input == 50) || (i == 2 && input == 51) || (i == 2 && input == 53) || (i == 2 && input == 53) || (i == 2 && input == 55) || (i == 2 && input == 57) || (i == 2 && input == 56) && (i > 2 && input >= 48 && input <= 57))
        {
            position(x + i, y);
            printf("%c", input);
            phoneno1[i] = input;
            i++;
        }
        else if (i <= 12 || (i == 0 && input == 48))
        {
            position(x + i, y);
            printf("%c", input);
            phoneno1[i] = input;
            i++;
        }
        else if (input == 8 && i != 0)
        {
            i--;
            position(x + i, y);
            printf(" ");
            position(x + i, y);
            phoneno1[i] = '\0';
        }
    }
    i = 0;
    strcpy(phoneno, phoneno1);
    return phoneno;
}
