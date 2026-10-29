#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#endif
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif
#ifndef _BSD_SOURCE
#define _BSD_SOURCE
#endif

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define CLEAR_SCREEN() system("cls")
#else
    #include <termios.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/time.h>
    #include <sys/select.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    
    #define CLEAR_SCREEN() system("clear")
    
    // ANSI Color Support for Linux/macOS
    #define BLACK 0
    #define DARK_BLUE 1
    #define DARK_GREEN 2
    #define DARK_CYAN 3
    #define DARK_RED 4
    #define DARK_PURPLE 5
    #define DARK_YELLOW 6
    #define DARK_WHITE 7
    #define GRAY 8
    #define BLUE 9
    #define GREEN 10
    #define CYAN 11
    #define RED 12
    #define PURPLE 13
    #define YELLOW 14
    #define WHITE 15

    // Helper for strlwr on POSIX
    static inline char* strlwr(char* s) {
        for(char* p = s; *p; p++) *p = tolower(*p);
        return s;
    }

    static inline void Sleep(unsigned int ms) {
        struct timeval tv;
        tv.tv_sec = ms / 1000;
        tv.tv_usec = (ms % 1000) * 1000;
        select(0, NULL, NULL, NULL, &tv);
    }
    
    static inline char getch(void) {
        char buf = 0;
        struct termios old = {0};
        fflush(stdout);
        if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSAFLUSH, &old) < 0) perror("tcsetattr() ICANON");
        if (read(0, &buf, 1) < 0) perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSAFLUSH, &old) < 0) perror("tcsetattr() ~ICANON");
        return buf;
    }

    static inline void position(int x, int y) {
        printf("\033[%d;%dH", y + 1, x + 1);
    }

    static inline void cursor(bool visible) {
        if (visible) {
            printf("\033[?25h");
        } else {
            printf("\033[?25l");
        }
        fflush(stdout);
    }

    static inline void text_color(short color) {
        int ansi_codes[] = {30, 34, 32, 36, 31, 35, 33, 37, 90, 94, 92, 96, 91, 95, 93, 97};
        if (color >= 0 && color < 16) {
            printf("\033[%dm", ansi_codes[color]);
        }
    }

    static inline void background_color(short color) {
        int ansi_bg_codes[] = {40, 44, 42, 46, 41, 45, 43, 47, 100, 104, 102, 106, 101, 105, 103, 107};
        if (color >= 0 && color < 16) {
            printf("\033[%dm", ansi_bg_codes[color]);
        }
    }

    static inline void win_control(void) {
        // No-op on Linux/macOS
    }
#endif

#endif // COMPATIBILITY_H
