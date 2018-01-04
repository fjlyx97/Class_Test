#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

/** 
 * ���ߣ�������
 * ���ڣ�2018.1.1
 * Ŀ�ģ�̰����С��Ϸ
 * �汾�ţ� Beta 0.1
 */

using namespace std;

void gotoxy(HANDLE hOut, int x, int y); //�ƶ����
void hello();   //��ʼ����
void over();    //��������
void printMap(HANDLE hOut); //���Ƶ�ͼ

class snake
{
private:
    int snake_x;  //�ߺ�����
    int snake_y;  //��������
    int snake_len;      //�ߵĳ���
public:
    snake* next;  //��һ���ߵ�����

public:
    /*�ߵĹ��캯��*/
    snake(int x , int y , int len)
    { 
        this->snake_x = x; 
        this->snake_y = y; 
        this->snake_len = len;
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
    int return_len();//���س���
    void add_len();//���ӳ���
    friend void printsnake(HANDLE hOut,snake* snake_head); //����
    friend void Dprintsnake(HANDLE hOut,snake* snake_head); //����
    friend void movesnake(snake* snake_head , char dir);//�ƶ���
    friend snake* new_snake(snake* snake_end);//�����µ���
    friend void delete_snake(snake* snake_head);//ɾ����
    friend bool snake_cash(snake* snake_head);        //���Ƿ�ײ���Լ�
};
void printsnake(HANDLE hOut,snake* snake_head); //����
void Dprintsnake(HANDLE hOut,snake* snake_head); //����
void movesnake(snake* snake_head , char dir);   //�ߵ��ƶ�
snake* new_snake(snake* snake_end);//�����µ���
void delete_snake(snake* snake_head);//ɾ����
bool snake_cash(snake* snake_head);        //���Ƿ�ײ���Լ�
void printScore(HANDLE hOut,snake* snake_head); //�����߷���

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
    char temp_dir;
    char status;
    int difficult;    //�Ѷ�����
    /* ��ʼ������ */
    while (true)
    {
        /*��ʼ����ͷ*/
        snake* mysnake = new snake(rand()%54+1,rand()%26+1,1);
        snake* snake_head = mysnake;
        snake* snake_end = mysnake;
        printsnake(hOut,mysnake);
        dir = '\0';
        temp_dir = '\0';
        status = '\0';
        difficult = 150;

        /*��ʼ��ʳ��*/
        food* myfood = new food;
        myfood->show_food();

        system("cls");
        while(true)
        {
            /*����*/
            Dprintsnake(hOut,snake_head);

            /*��ȡ��������*/
            if (kbhit())
            {
                temp_dir = dir;
                dir = getch();
                if (temp_dir == 'w' && dir == 's')
                {
                    dir = 'w';
                }
                if (temp_dir == 's' && dir == 'w')
                {
                    dir = 's';
                }
                if (temp_dir == 'a' && dir == 'd')
                {
                    dir = 'a';
                }
                if (temp_dir == 'd' && dir == 'a')
                {
                    dir = 'd';
                }
            }
            snake_head = mysnake;
            
            /*�ж�״̬*/
            //�߳�ʳ��
            if (snake_head->return_x() == myfood->return_food_x() && snake_head->return_y() == myfood->return_food_y() )
            {
                myfood->show_food();//��������ʳ��
                snake_head->add_len();
                snake_end = new_snake(snake_end);
            }
            //���Ƿ�ײ���Լ�
            
            //��ײǽ
            if ((snake_head->return_x() == 0) || (snake_head->return_x() == 55) || (snake_head->return_y() == 0) || (snake_head->return_y() == 27) || snake_cash(snake_head))
            {
                system("cls");
                over();
                status = getche();
                if (status == '\r')
                {
                    break;
                }
                else
                {
                    return 0;
                }
            }

            /*��������*/
            movesnake(snake_head,dir);
            printMap(hOut);
            printsnake(hOut,snake_head);
            printScore(hOut,snake_head);
            myfood->print_food(hOut);

            printMap(hOut); //����˸
            /*�Ѷ�����*/
            Sleep(difficult);
        }
        /* ����ڴ� */
        delete_snake(snake_head);
        delete myfood;
        snake_head = NULL;
        snake_end = NULL;
        mysnake = NULL;
        myfood = NULL;

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
void over()
{   printf("                         **********************\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *                    *\n");
    printf("                         *       ̰����       *\n");
    printf("                         *                    *\n");
    printf("                         *      ��Ϸ����      *\n");
    printf("                         *                    *\n");
    printf("                         *   ���س����¿�ʼ   *\n");
    printf("                         *   �������˳���Ϸ   *\n");
    printf("                         *                    *\n");
    printf("                         **********************\n");

}
void printMap(HANDLE hOut)
{
    // ��ͼ��С ��56 ��28
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
void printScore(HANDLE hOut,snake* snake_head) //���Ʒ���
{
    gotoxy(hOut,60,14);
    printf("��ǰ�÷�Ϊ��%d",(snake_head->return_len()-1)*100);
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
void Dprintsnake(HANDLE hOut,snake* snake_head) //ɾ����
{
    snake* snake_temp = snake_head;
    while (snake_temp != NULL)
    {
        gotoxy(hOut,snake_temp->snake_x,snake_temp->snake_y);
        printf(" ");
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
    int tempx = snake_head->return_x();
    int tempy = snake_head->return_y();
    int tempx_1;
    int tempy_1;
    snake* snake_temp = snake_head;
    while (snake_temp->next != NULL)
    {
        tempx_1 = snake_temp->next->snake_x;
        tempy_1 = snake_temp->next->snake_y;
        snake_temp->next->snake_x = tempx;
        snake_temp->next->snake_y = tempy;
        tempx = tempx_1;
        tempy = tempy_1;
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
int snake::return_len()//���س���
{
    return this->snake_len;
}
void snake::add_len()
{
    this->snake_len++;
    return;
}
snake* new_snake(snake* snake_end)  //������
{
    int x = snake_end->return_x();
    int y = snake_end->return_y();
    snake* new_snake = new snake(x,y,1);
    snake_end->next = new_snake;
    snake_end = snake_end->next;
    return snake_end;
}
void delete_snake(snake* snake_head)//ɾ����
{
    snake* snake_temp;
    while (snake_head != NULL)
    {
        snake_temp = snake_head;
        snake_head = snake_head->next;
        delete snake_temp;
    }
}
bool snake_cash(snake* snake_head)        //���Ƿ�ײ���Լ�
{
    if (snake_head->snake_len > 2)
    {
        snake* snake_temp = snake_head->next->next;
        while(snake_temp != NULL)
        {
            if (snake_head->snake_x == snake_temp->snake_x && snake_head->snake_y == snake_temp->snake_y)
            {
                return true;
            }
            snake_temp = snake_temp->next;
        }
        return false;
    }
    return false;
}
/*�ߵĶ���*/

/*ʳ��Ķ���*/

void food::show_food()  //����ʳ��
{
    this->food_x = rand() % 54+1;
    this->food_y = rand() % 26+1;
    return;
}
void food::print_food(HANDLE hOut)  //����ʳ��
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