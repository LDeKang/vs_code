#include <stdio.h>
#include <string.h>
#define WIDTH 128
#define PAGES 8
#define _OLED_Reverse 1
void OLED_DrawPixel(char x, char y);
char _buf[WIDTH * PAGES]; //全屏缓存,横向WIDTH个像素，纵向PAGES页，页内每8个像素作为一个字节，共WIDTH * PAGES个字节

 int main(void)
{
 OLED_DrawPixel(0,1);

}

void OLED_DrawPixel(char x, char y)
{
    char mask;
    char *pBuf;

    pBuf = &_buf[(y >> 3) * WIDTH + x];
    mask = 1 << (y & 7);
    if (_OLED_Reverse)
    {
        *pBuf++ &= ~mask;
    }
    else
    {
        *pBuf++ |= mask;
    }
}