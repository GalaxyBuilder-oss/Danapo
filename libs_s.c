#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*
    Start
*/
#define HandleO GetStdHandle(STD_OUTPUT_HANDLE)

#define BLACK 0x0
#define DARK_BLUE 0x1
#define DARK_GREEN 0x2
#define DARK_CYAN 0x3
#define DARK_RED 0x4
#define DARK_PURPLE 0x5
#define DARK_YELLOW 0x6
#define DARK_WHITE 0x7
#define GRAY 0x8
#define BLUE 0x9
#define GREEN 0xa
#define CYAN 0xb
#define RED 0xc
#define PURPLE 0xd
#define YELLOW 0xe
#define WHITE 0xf
int txt_color = FOREGROUND_INTENSITY;
int bg_color = 0;

void position(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(HandleO, pos);
}
void text_color(short color)
{
    SetConsoleTextAttribute(HandleO, color | (bg_color << 4));
    txt_color = color;
}
void background_color(short color)
{
    SetConsoleTextAttribute(HandleO, txt_color | (color << 4));
    bg_color = color;
}
/*
    End        Source : Conui.h(PUB Code)
*/
void VLine(short y, char color, int xx, int yy)
{
    text_color(color);
    for (int a = 1; a <= 2; a++)
    {
        for (int b = 1; b <= y; b++)
        {
            position(xx, yy + b);
            printf("%c",219);
        }
    }
}
void HLine(short x, char color, int xx, int yy)
{
    text_color(color);
    for (int a = 1; a <= x; a++)
    {
        for (int b = 1; b <= 1; b++)
        {
            position(xx + a, yy);
            printf("%c",220);
        }
    }
}
void bg_content(int x, int y) {
    background_color(GRAY);
    for(int a = 1; a <= x; a++)
    {
        for(int b = 1; b <= y; b++)
        {
            position(1+b,0+a);printf(" ");
        }
        printf("\n");
    }

}
void bg_content1(int x, int y, char color, int xx, int yy) {
    background_color(color);
    for(int a = 1; a <= y; a++)
    {
        for(int b = 1; b <= x; b++)
        {
            position(xx+b,yy+a);printf(" ");
        }
    }

}
void Frame(int x, int y, char color, int xx, int yy)
{
    text_color(color);
    for(int a = 0; a <= x; a++)
    {
        for(int b = 0; b <= y; b++)
        {
            position(xx + a, yy);
            printf("%c", 205);
            position(xx + a, yy + y);
            printf("%c", 205);
            position(xx, yy + b);
            printf("%c", 219);
            position(xx + x + 1, yy + b);
            printf("%c", 219);
        }
    }
}
void outerFrame(int x, int y)
{
    text_color(DARK_YELLOW);
    for(int a = 0; a <= x; a++)
    {
        for(int b = 0; b <= y; b++)
        {
            if (a==0 || a==x || b==0 || b==1 || b==y || b==y-1){
                position(0+b,0+a);printf("%c",219);
            }
        }
    }
}
void Logo(int logo) {
    if (logo == 0) {
        position(45, 3);printf("  _ \\                                ");
        position(45, 4);printf("  |  |  _` |    \\    _` |  _ \\   _ \\ ");
        position(45, 5);printf(" ___/ \\__,_| _| _| \\__,_| .__/ \\___/ ");
        position(45, 6); printf("                         _|          ");
    }
    else if (logo == 1) {
        position(3, 3);
        printf("  |                 _)       ");
        position(3, 4);
        printf("  |      _ \\   _` |  |    \\  ");
        position(3, 5);
        printf(" ____| \\___/ \\__, | _| _| _| ");
        position(3, 6);
        printf("             ____/           ");
    }
    else if(logo == 2) {
        position(3, 3);
        printf("  __| _)               |  |     ");
        position(3, 4);
        printf("\\__ \\  |   _` |    \\   |  | _ \\ ");
        position(3, 5);
        printf("____/ _| \\__, | _| _| \\__/ .__/ ");
        position(3, 6);
        printf("         ____/            _|    ");
    }
    else if(logo == 3) {
        position(3, 3);
        printf("   \\    |                 |   ");
        position(3, 4);
        printf("  _ \\    _ \\   _ \\  |  |   _| ");
        position(3, 5);
        printf("_/  _\\ _.__/ \\___/ \\_,_| \\__| ");
    }
    else if(logo == 4) {
        position(3, 3);
        printf("__ __|                                 |   _)             ");
        position(3, 4);
        printf("   |   _| _` |    \\  (_-<   _` |   _|   _|  |   _ \\    \\  ");
        position(3, 5);
        printf("  _| _| \\__,_| _| _| ___/ \\__,_| \\__| \\__| _| \\___/ _| _| ");
    }
    else if (logo == 5) {
        position(3, 3);
        printf(" |                       ");
        position(3, 4);
        printf(" |      _ \\   _` |    \\  ");
        position(3, 5);
        printf("____| \\___/ \\__,_| _| _| ");
    }
    else if (logo == 6) {
        position(3, 3);
        printf("  _ \\          _| _)  |       ");
        position(3, 4);
        printf("  __/ _| _ \\   _|  |  |   -_) ");
        position(3, 5);
        printf(" _| _| \\___/ _|   _| _| \\___| ");
    }
    else if (logo == 7) {
        position(3, 3);
        printf("   \\  |                   ");
        position(3, 4);
        printf("  |\\/ |   -_)    \\   |  | ");
        position(3, 5);
        printf(" _|  _| \\___| _| _| \\_,_| ");
    }
    else if (logo == 8){
        position(3, 3);
        printf("  _ \\                                |   ");
        position(3, 4);
        printf("  __/ _` |  |  |   ` \\    -_)    \\    _| ");
        position(3, 5);
        printf(" _| \\__,_| \\_, | _|_|_| \\___| _| _| \\__| ");
        position(3, 6);
        printf("           ___/                          ");
    }
}
void cursor(bool truefalse){
    // Set The Cursor Invisible
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = truefalse;
    SetConsoleCursorInfo(HandleO, &info);
}
void win_control()
{
    //Set The Title Of Window
    SetConsoleTitle("Danapo | Projek UAS Algoritma Dan Bahasa Pemrograman");

    //Get the window console handle(isn't the right code but works for these sample)
    HWND ConsoleWindow;
    ConsoleWindow = GetForegroundWindow();

    //Getting the desktop hadle and rectangule
    HWND hwndScreen;
    RECT rectScreen;
    hwndScreen = GetDesktopWindow();
    GetWindowRect(hwndScreen, &rectScreen);

    int h=800;
    int w=1000;
    // Set windows size
    SetWindowPos(ConsoleWindow, NULL, 0, 0, w, h, SWP_SHOWWINDOW);

    //caculate the window console to center of the screen
    int PosX;
    int PosY;
    PosX = 150;
    PosY = 0;
    SetWindowPos(ConsoleWindow, NULL, PosX, PosY, w, h, SWP_SHOWWINDOW || SWP_NOSIZE);
}

/* https://www.techiedelight.com/implement-itoa-function-in-c/ */

void swap(char *x, char *y);
char* reverse(char *buffer, int i, int j);
char* itoa(int value, char* buffer, int base);

//Function to swap two numbers
void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}
// Function to reverse `buffer[i…j]`
char* reverse(char *buffer, int i, int j)
{
	while (i < j) {
		swap(&buffer[i++], &buffer[j--]);
	}
	return buffer;
}
// Iterative function to implement `itoa()` function in C
char* itoa(int value, char* buffer, int base)
{
	// invalid input
	if (base < 2 || base > 32) {
		return buffer;
	}
	// consider the absolute value of the number
	int n = abs(value);
	int i = 0;
	while (n)
	{
		int r = n % base;
		if (r >= 10) {
			buffer[i++] = 65 + (r - 10);
		}
		else {
			buffer[i++] = 48 + r;
		}
		n = n / base;
	}
	// if the number is 0
	if (i == 0) {
		buffer[i++] = '0';
	}
	// If the base is 10 and the value is negative, the resulting string
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10) {
		buffer[i++] = '-';
	}
	buffer[i] = '\0'; // null terminate string
	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}
