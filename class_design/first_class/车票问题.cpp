#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int cal(int begin, int over); //����Ʊ�۵ĺ���
void cal_money_num(int money , int* ticket);
int main()
{
    srand(time(0));
    int loop = rand() % 10 + 5; //������ɳ˿͸���
    int ticket[7] = {0}; //1-6ԪƱ��
    int begin , over;   //�˿����³�վ
    int ans = 0;            //�õ�Ʊ�۽��
    cout << "����" << loop << "λ�˿͡�" << endl;
    for (int i = 1 ; i <= loop ; i++)
    {
        /* 26����վ */
        begin = rand() % 26 + 1;
        over = begin + rand() % ((26-begin)+1);
        cout << "��" << i << "λ�˿���:" << begin << "�ϳ���" << endl;
        cout << "��" << i << "�˿���:" << over << "�³���" << endl;
        cout << "��" << i << "�˿�Ӧ��֧��:" << cal(begin,over) << "Ԫ" << endl;
        cal_money_num(cal(begin,over),ticket);  //ͳ������������
        ans += cal(begin,over); //��õ���Ʊ��
        cout << endl;
    }
    cout << endl;
    for (int j = 1 ; j <= 6 ; j++)
    {
        cout << j << "Ԫ�۳�������Ϊ:" << ticket[j] << endl;
    }
    cout << "�����۳�����Ʊ��Ϊ:" << ans << endl;
    system("pause");
    return 0;
}
int cal(int begin , int over)
{
    int ans = 0;
    if (over - begin <= 6)
    {
        ans = 1;
    }
    else
    {
        int temp = (over-begin) - 6;    //��ö����վ��
        if (temp % 4 == 0)
        {
            ans = temp / 4;
        }
        else
        {
            ans = temp / 4 + 1;
        }
        ans += 1;
    }
    return ans;
}
void cal_money_num(int money , int* ticket)
{
    ticket[money] += 1;
}