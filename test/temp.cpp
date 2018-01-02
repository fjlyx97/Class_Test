#include <Windows.h>
#include <stdio.h>
 
/************************************************************************/
/* 函数 DrawCircle
/* 参数 HDC hdc 绘图的句柄
/*      int x
/*      int y   圆心的x，y坐标
/*      int r   圆的半径
/*      COLORREF color      圆的填充颜色
/* 功能 在(x, y)处画一个半径为r的圆，用color的颜色填充
/************************************************************************/
void DrawCircle(HDC hdc, int x, int y, int r, COLORREF color)
{
    HBRUSH brush = (HBRUSH)CreateSolidBrush (color);        //新建一个画刷
    SelectObject(hdc, (HGDIOBJ)brush);                      //选择画刷
    Ellipse(hdc, x-r, y-r, x+r, y+r);                       //画一个圆
    DeleteObject(brush);                                    //删除画刷
}
 
int main()
{
    HWND console = GetConsoleWindow();                      //获取控制台窗口句柄
    HDC  console_hdc = GetDC(console);                      //获取绘图dc
    RECT rect;                                              //保存绘图区域大小的结构体
    int x,
        y,                          //小球的xy坐标
        dx = 3,                     //x的增量
        dy = 3;                     //y的增量
    int r = 0, g = 0, b = 0;        //小球颜色
    int speed;                      //小球速度
    COORD pos={0,4};                //光标位置
 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
 
    GetClientRect(console, &rect);                          //首先获取绘图区域的大小
 
    x = 10 + rand() % (rect.right);
    y = 10 + rand() % (rect.bottom);
 
    printf("当前窗口宽度 %d\n当前窗口高度 %d\n请输入小球颜色(r g b):", rect.right, rect.bottom);
    scanf("%d %d %d", &r, &g, &b);
    printf("请输入小球运动速度（1~10）");
    scanf("%d", &speed);
    //rgb 的范围分别是0~255
    //255 255 255为白色
 
    if (speed <1 || speed > 10 || r >255 || r < 0 || g >255 || g < 0 || b >255 || g <0)
    {
        printf("无效的输入");
        return 0;
    }
 
    while (1)
    {
        SetConsoleCursorPosition(hOut,pos);                     //设置光标位置
        printf("当前小球位置 x= %d  \ty=%d  ", x, y);
        DrawCircle(console_hdc, x, y, 10, RGB(r, g, b));        //画一个白色的圆
        Sleep(200/speed);
        DrawCircle(console_hdc, x, y, 10, RGB(0, 0, 0));        //画一个黑色的圆（擦除）
 
        if (x > rect.right - 10 || x < 10)
            dx = -dx;
 
        if (y > rect.bottom - 10 || y < 10)
            dy = -dy;
 
        x += dx;
        y += dy;
    }
 
    ReleaseDC(console, console_hdc);
    return 0;
}