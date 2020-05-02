
#include<stdio.h>
#include<windows.h>
#include<time.h>
 
typedef struct PIECE
{
    int x;
    int y;
    struct PIECE *next;
}    Piece;
 
char key;
int Score;
int cnt = 0;
/*函数声明*/
 
Piece *head;
Piece *head2;
Piece *createpiece();
void SetPos(int x, int y);
void createmap();
int main();
Piece *piecemove(Piece *head);
void getkey();
 
/*------*/
/*
函数名：void SetPos(int x,int y)
函数功能:光标设置
参数：x，y位置坐标
返回值：无
*/
void SetPos(int x, int y)                            ///设置坐标
{
    COORD tempCrd;                                  ///声明变量--坐标变量
    HANDLE Houtput;                                 ///声明变量--句柄
    tempCrd.X = x;                                    ///coord position
    tempCrd.Y = y;                                    ///coord position
    Houtput = GetStdHandle(STD_OUTPUT_HANDLE);        ///使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
    SetConsoleCursorPosition(Houtput, tempCrd);     ///设置光标位置
}
/*
函数名：void createmap()
函数功能:创建地图
参数：无
返回值：无
*/
void createmap()
{
    int i, j;
    for (i = 8; i<18; i += 3) //x 轴
    {
        SetPos(i, 9);
        printf("==");
    }
    for (j = 0; j < 10; j++)  // y 轴
    {
        SetPos(5, j);
        printf("||");
        SetPos(20, j);
        printf("||");
    }
}
 
/*
函数名：Piece *createpiece()
函数功能:创建钢琴块
参数：无
返回值：无
*/
Piece *createpiece(Piece *head) //暂时将随机生成的piece定义为区间[8:17]
{
    int  x;
    head = (Piece *)malloc(sizeof(Piece));
    head->next = NULL;
    srand((unsigned)time(NULL));
    x = rand() % 4 + 1;
    if (x == 1)
    {
        head->x = 8;
    }
    else if (x == 2)
    {
        head->x = 11;
    }
    else if (x == 3)
    {
        head->x = 14;
    }
    else if (x == 4)
    {
        head->x = 17;
    }
    head->y = 0;
    SetPos(head->x, head->y);
    printf("■");
    return head;
}
/*
函数名：void piecemove()
函数功能:创建钢琴块
参数：无
返回值：无
*/
Piece *piecemove(Piece *head)
{
    Sleep(170);
    Piece *node, *temp;
    node = (Piece *)malloc(sizeof(Piece));
    node->x = head->x;
    node->y = head->y + 1;
    node->next = head;
    temp = head;
    SetPos(temp->x, temp->y);
    printf(" ");
    free(temp);
    head = node;
    SetPos(head->x, head->y);
    printf("■");
    return head;
}
/*
函数名：void getkey()
函数功能:创建钢琴块
参数：无
返回值：无
*/
 
void getkey()
{
 
    if (GetAsyncKeyState(VK_SPACE) && (head->x == 8) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("你做到了                ");
    }
    else if (GetAsyncKeyState(VK_LEFT) && (head->x == 11) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("分数上涨                   ");
    }
    else if (GetAsyncKeyState(VK_DOWN) && (head->x == 14) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("继续前进            ");
    }
    else if (GetAsyncKeyState(VK_RIGHT) && (head->x == 17) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("没有错，就是这样          ");
    }
    else if (GetAsyncKeyState(VK_F1))
    {
        SetPos(15, 15);
        system("pause");
    }
    else
        cnt++;
}
void help()
{
    SetPos(30, 3);
    printf("空格  --- 1");
    SetPos(30, 11);
    printf("你共有五次失误机会");
    SetPos(30, 4);
    printf("左键  --- 2");
    SetPos(30, 5);
    printf("下键  --- 3");
    SetPos(30, 6);
    printf("右键  --- 4");
    SetPos(30, 7);
    printf("F1键  --- 暂停");
    SetPos(30, 9);
    printf("从左往右等号依次对应1 2 3 4 ");
}
int main()
{
    int i;
    SetPos(30, 1);
    printf("分数:%d", Score);
    createmap();
    help();
    while (1)
    {
        head = createpiece(head);
        for (i = 0; i<9; i++)
        {
            head = piecemove(head);
        }
        getkey();
        SetPos(30, 1);
        printf("分数:%d", Score);
        SetPos(40, 1);
        printf("失误:%d", cnt);
        for (i = 8; i<18; i += 3) //x 轴
        {
            SetPos(i, 9);
            printf("==");
        }
        if (cnt == 5)
        {
            break;
        }
    }
    SetPos(30, 1);
    printf("游戏结束");
    Sleep(5000);
    return 0;
}
