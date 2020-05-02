
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
/*��������*/
 
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
��������void SetPos(int x,int y)
��������:�������
������x��yλ������
����ֵ����
*/
void SetPos(int x, int y)                            ///��������
{
    COORD tempCrd;                                  ///��������--�������
    HANDLE Houtput;                                 ///��������--���
    tempCrd.X = x;                                    ///coord position
    tempCrd.Y = y;                                    ///coord position
    Houtput = GetStdHandle(STD_OUTPUT_HANDLE);        ///ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
    SetConsoleCursorPosition(Houtput, tempCrd);     ///���ù��λ��
}
/*
��������void createmap()
��������:������ͼ
��������
����ֵ����
*/
void createmap()
{
    int i, j;
    for (i = 8; i<18; i += 3) //x ��
    {
        SetPos(i, 9);
        printf("==");
    }
    for (j = 0; j < 10; j++)  // y ��
    {
        SetPos(5, j);
        printf("||");
        SetPos(20, j);
        printf("||");
    }
}
 
/*
��������Piece *createpiece()
��������:�������ٿ�
��������
����ֵ����
*/
Piece *createpiece(Piece *head) //��ʱ��������ɵ�piece����Ϊ����[8:17]
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
    printf("��");
    return head;
}
/*
��������void piecemove()
��������:�������ٿ�
��������
����ֵ����
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
    printf("��");
    return head;
}
/*
��������void getkey()
��������:�������ٿ�
��������
����ֵ����
*/
 
void getkey()
{
 
    if (GetAsyncKeyState(VK_SPACE) && (head->x == 8) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("��������                ");
    }
    else if (GetAsyncKeyState(VK_LEFT) && (head->x == 11) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("��������                   ");
    }
    else if (GetAsyncKeyState(VK_DOWN) && (head->x == 14) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("����ǰ��            ");
    }
    else if (GetAsyncKeyState(VK_RIGHT) && (head->x == 17) && (head->y == 9))
    {
        Score += 1;
        SetPos(7, 15);
        printf("û�д���������          ");
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
    printf("�ո�  --- 1");
    SetPos(30, 11);
    printf("�㹲�����ʧ�����");
    SetPos(30, 4);
    printf("���  --- 2");
    SetPos(30, 5);
    printf("�¼�  --- 3");
    SetPos(30, 6);
    printf("�Ҽ�  --- 4");
    SetPos(30, 7);
    printf("F1��  --- ��ͣ");
    SetPos(30, 9);
    printf("�������ҵȺ����ζ�Ӧ1 2 3 4 ");
}
int main()
{
    int i;
    SetPos(30, 1);
    printf("����:%d", Score);
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
        printf("����:%d", Score);
        SetPos(40, 1);
        printf("ʧ��:%d", cnt);
        for (i = 8; i<18; i += 3) //x ��
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
    printf("��Ϸ����");
    Sleep(5000);
    return 0;
}
