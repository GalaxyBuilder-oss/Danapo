#include <stdio.h>

void main()
{
    for (int i = 0; i < 256; i++)
    {
        printf("%d = %c, ", i, i);
        if (i % 7 == 0)
        {
            printf("\n");
        }
    }
}