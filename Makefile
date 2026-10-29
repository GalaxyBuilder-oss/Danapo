CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = danapo

# Deteksi OS secara otomatis
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    RM = del /Q
else
    RM = rm -f
endif

all: $(TARGET)

$(TARGET): main.c libs_s.c validation.c compatibility.h
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	$(RM) $(TARGET)
	$(RM) main
	$(RM) *.exe
