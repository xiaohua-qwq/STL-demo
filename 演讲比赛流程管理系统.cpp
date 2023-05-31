#include<iostream>
#include<string>
#include<ctime>
#include"speechManager.h"
using namespace std;

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建管理类对象
	SpeechManager sm;

	int choice = 0; //存储用户的输入
	
	while (true)
	{
		sm.show_Menu();
		cout << "请输入您的选择: " << endl;
		cout << "> ";
		cin >> choice;
		switch (choice)
		{
		case 1: //开始比赛
			sm.startSpeech();
			break;
		case 2: //查看往届记录
			sm.showRecord();
			break;
		case 3: //清空比赛记录
			break;
		case 0: //退出系统
			sm.exitSystem();
			break;
		default: 
			cout << "输入有误 请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}