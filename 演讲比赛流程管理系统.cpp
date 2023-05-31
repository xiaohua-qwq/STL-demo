#include<iostream>
#include<string>
#include<ctime>
#include"speechManager.h"
using namespace std;

int main()
{
	//���������
	srand((unsigned int)time(NULL));

	//�������������
	SpeechManager sm;

	int choice = 0; //�洢�û�������
	
	while (true)
	{
		sm.show_Menu();
		cout << "����������ѡ��: " << endl;
		cout << "> ";
		cin >> choice;
		switch (choice)
		{
		case 1: //��ʼ����
			sm.startSpeech();
			break;
		case 2: //�鿴�����¼
			sm.showRecord();
			break;
		case 3: //��ձ�����¼
			break;
		case 0: //�˳�ϵͳ
			sm.exitSystem();
			break;
		default: 
			cout << "�������� ����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}