#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
bool judgePasswd(string passwd)
{			
	cout << "请输入你的密码:";
	string yourPasswd; //自己密码变量
	cin >> yourPasswd;
	if (yourPasswd == passwd)
		return true;
	else
		return false;
}
int main()
{
	ifstream passwd("passwd"); //打开文件
	if (!passwd)
	{
		cout << "请输入新密码：";
		ofstream new_passwd("passwd"); //文件不存在，创建密码文件
		string new_Passwd; //新密码变量
		cin >> new_Passwd; //输入新密码
		new_passwd << new_Passwd; //写入文件
		cout << "密码创建完成" << endl;
		new_passwd.close();
	}

	else
	{
		int number = 0;//设置判断次数
		char systemPasswd[100]; //文件密码变量
		passwd.getline(systemPasswd, sizeof(systemPasswd));//将密码写入systemPasswd.
		string new_systemPasswd = systemPasswd;
		while (number < 3)
		{
			if (judgePasswd(new_systemPasswd)) //调用判断函数.
			{
				cout << "密码输入正确。" << endl;
				break;
			}
			else
			{
				cout << "密码错误，请重新输入。" << endl;
			}
			number++;
		}
		passwd.close();
	}
    system("pause");
	return 0;
}
