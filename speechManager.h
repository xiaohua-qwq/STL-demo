#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<map>
#include<fstream>
using namespace std;

//����ݽ�������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~SpeechManager();

	//��ʼ������������
	void initSpeech();

	//����ʮ����ѡ��
	void createSpeaker();

	//��ʼ���� �����������̿��ƺ���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ�����¼
	void showRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;

    //�����һ������ѡ�ֱ������
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;

	//ʤ����ǰ����
	vector<int>vVictory;

	//��ű���Լ���Ӧ�ľ���ѡ������
	map<int, SpeaKer>m_Speaker;

	//��ű�������
	int m_Index;
};