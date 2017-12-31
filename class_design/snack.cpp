#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(HANDLE hOut, int x, int y); //�ƶ����
void hello();   //��ʼ����
void printMap(HANDLE hOut);

class snake
{
private:
    int snake_x;  //�ߺ�����
    int snake_y;  //��������
public:
    snake* next;  //��һ���ߵ�����

public:
    /*�ߵĹ��캯��*/
    snake(int x , int y)
    { 
        this->snake_x = x; 
        this->snake_y = y; 
        this->next = NULL;
    }

    /*�ߵ��ƶ�*/
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    /*�ߵ���������*/
    int return_x();//���غ�����
    int return_y();//����������
    friend void printsnake(HANDLE hOut,snake* snake_head); //����
    friend void movesnake(snake* snake_head , char dir);//��Ԫ����
    friend snake* new_snake(snake* snake_end);//�����µ���
};
void printsnake(HANDLE hOut,snake* snake_head); //����
void movesnake(snake* snake_head , char dir);   //�ߵ��ƶ�
snake* new_snake(snake* snake_end);//�����µ���

class food
{
private:
    int food_x;
    int food_y;

public:
    void show_food();//����ʳ��
    void print_food(HANDLE hOut);//����ʳ��
    int return_food_x();//���غ�����
    int return_food_y();//����������
};

int main()
{
    /* ȡ����� */
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&cci);
    /* ȡ����� */
    
    /* ��ʼ������ */
    srand(time(0));
    hello();
    char dir;
    /* ��ʼ������ */
    while (true)
    {
        /*��ʼ����ͷ*/
        snake* mysnake = new snake(rand()%55+1,rand()%27+1);
        snake* snake_end = mysnake;
        printsnake(hOut,mysnake);

        /*��ʼ��ʳ��*/
        food* myfood = new food;
        myfood->show_food();

        while(true)
        {
            /*����*/
            system("cls");

            /*��ȡ��������*/
            if (kbhit())
            {
                dir = getch();
            }
            snake* snake_head = mysnake;
            
            /*�ж�״̬*/
            if (snake_head->return_x() == myfood->return_food_x() && snake_head->return_y() == myfood->return_food_y())
            {
                myfood->show_food();//��������ʳ��
                snake_end = new_snake(snake_end);
            }
            /*��������*/
            movesnake(snake_head,dir);
            printMap(hOut);
            printsnake(hOut,snake_head);
            myfood->print_food(hOut);

            //while (snake_head != NULL)
            //{
            //    snake_head->printsnake(hOut,snake_head);
            //    snake_head = snake_head->next;
            //}

            //printMap(hOut);
            Sleep(200);
        }
    }
    system("pause");
    return 0;
}
void hello() //��ʼ����
{
    printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       ̰����       *\n");
    printf("                         *                    *\n");
    printf("                         * �밴�������ʼ��Ϸ *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         **********************\n");
    getche();
    return;
}
void printMap(HANDLE hOut)
{
    // ��ͼ��С ��55 ��28
    gotoxy(hOut,0,0);
    printf("########################################################\n");   
    for ( int i = 1 ; i <= 26 ; i++)
    {
        gotoxy(hOut,0,i);
        printf("#");
        gotoxy(hOut,55,i);
        printf("#\n");
    }
    printf("########################################################\n");   
    return;
}
void gotoxy(HANDLE hOut, int x, int y)
{
      COORD pos;
      pos.X = x;             //������
      pos.Y = y;            //������
      SetConsoleCursorPosition(hOut, pos);
      return;
}
/*�ߵĶ���*/
void printsnake(HANDLE hOut,snake* snake_head)
{
    snake* snake_temp = snake_head;
    while (snake_temp != NULL)
    {
        gotoxy(hOut,snake_temp->snake_x,snake_temp->snake_y);
        printf("%c",1);
        snake_temp = snake_temp->next;
    }
    return;
}
void snake::moveUp()
{
    this->snake_y -= 1;
    return;
}
void snake::moveDown()
{
    this->snake_y += 1;
    return;
}
void snake::moveLeft()
{
    this->snake_x -= 1;
    return;
}
void snake::moveRight()
{
    this->snake_x += 1;
    return;
}
void movesnake(snake* snake_head , char dir)
{
    snake* snake_temp = snake_head;
    int temp_x;
    int temp_y;
    while(snake_temp->next != NULL)
    {
        temp_x = snake_temp->next->snake_x;
        temp_y = snake_temp->next->snake_y;
        snake_temp->next->snake_x = snake_temp->snake_x;               
        snake_temp->next->snake_y = snake_temp->snake_y;               
        snake_temp = snake_temp->next;
    }
    switch (dir)
    {
        case 'w':
            snake_head->moveUp();
            break;
        case 's':
            snake_head->moveDown();
            break;
        case 'a':
            snake_head->moveLeft();
            break;
        case 'd':
            snake_head->moveRight();
            break;
    }
    return;
}
int snake::return_x()
{
    return this->snake_x;
}
int snake::return_y()
{
    return this->snake_y;
}
snake* new_snake(snake* snake_end)
{
    int x = snake_end->return_x()-3;
    int y = snake_end->return_y()-3;
    snake* new_snake = new snake(x,y);
    snake_end->next = new_snake;
    snake_end = snake_end->next;
    return snake_end;
}
/*�ߵĶ���*/

/*ʳ��Ķ���*/
void food::show_food()
{
    this->food_x = rand() % 55+1;
    this->food_y = rand() % 27+1;
    return;
}
void food::print_food(HANDLE hOut)
{
    gotoxy(hOut,this->food_x,this->food_y);
    printf("%c",3);
    return;
}
int food::return_food_x()
{
    return this->food_x;
}
int food::return_food_y()
{
    return this->food_y;
}
/*ʳ��Ķ���*/
