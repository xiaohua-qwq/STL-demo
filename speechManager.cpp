#include"speechManager.h"
#include<algorithm>

//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������������
	this->initSpeech();
	
	//����12��ѡ��
	this->createSpeaker();

	//���������¼
	this->loadRecord();
}

//�˵�����
void SpeechManager::show_Menu()
{
	cout << "****************************************" << endl;
	cout << "**********  ��ӭ�μ��ݽ�����  ***********" << endl;
	cout << "**********  1.��ʼ�ݽ�����  *************" << endl;
	cout << "**********  2.�鿴�����¼  *************" << endl;
	cout << "**********  3.��ձ�������  *************" << endl;
	cout << "**********  0.�˳���������  *************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ������������
void SpeechManager::initSpeech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;

	//����¼���������
	this->m_Record.clear();
}

//����ʮ����ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		SpeaKer sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�� ���ҷ��뵽v1������
		this->v1.push_back(i + 10001);

		//ѡ�ֵı���Լ���Ӧ��ѡ�� ���뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ���� �����������̿��ƺ���
void SpeechManager::startSpeech()
{
	//��һ�ֿ�ʼ����

	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ�������
	this->showScore();
	//�ڶ��ֿ�ʼ����
	this->m_Index++;
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���ս��
	this->showScore();
	//4.����������ļ���
	this->saveRecord();

	//���ñ��� ��ȡ��¼
	//��ʼ������������
	this->initSpeech();
	//����12��ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "�� <<" << this->m_Index << ">> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ���ݽ�˳������: " << endl;
	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------" << endl;
	system("pause");
	cout << endl;
}

//����
void SpeechManager::speechContest()
{
	cout << "-------��" << this->m_Index << "�ֱ�����ʽ��ʼ-------" << endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>>groupScore;

	int num = 0; //��¼��Ա���� 6��һ��

	vector<int>v_Src; //����ѡ������
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600-1000 10.f������һ��С��
			//cout << score << " ";
			d.push_back(score);
		}
		
		sort(d.begin(), d.end(), greater<double>()); //����
		d.pop_front(); //ȥ����߷�
		d.pop_back(); //ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f); //�ܷ�
		double avg = sum / (double)d.size(); //ƽ����

		//��ƽ���ַ��뵽map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��������� ������ʱС��������
		groupScore.insert(make_pair(avg, *it)); //key�ǵ÷� value�Ǿ���ѡ�ֱ��
		//һ��С���й�6�� ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��ı�������: " << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << "����: " << this->m_Speaker[it->second].m_Name
					 << "�ɼ�: " << this->m_Speaker[it->second].m_Score[this->m_Index - 1]
					 << endl;
			}

			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear(); //С���������
			cout << endl;
		}
	}
	cout << "--------��" << this->m_Index << "�ֵı������--------" << endl;
	system("pause");
}

//��ʾ�÷�
void SpeechManager::showScore()
{
	cout << "--------��" << this->m_Index << "�ֽ�����ѡ����Ϣ����--------" << endl;

	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else { v = vVictory; }

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ��: " << *it << " ����: " << this->m_Speaker[*it].m_Name
			 << " �÷�: " << this->m_Speaker[*it].m_Score[this->m_Index - 1]
			 << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

//�����¼
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //��׷�ӵķ�ʽд�ļ�

	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��ÿ��ѡ�ֵ����� д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","
			<< this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	cout << "��¼�ѱ���" << endl;

	//�����ļ�״̬Ϊ ��Ϊ��
	this->fileIsEmpty = false;
}

//��ȡ��¼
void SpeechManager::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in); //���ļ�
	
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch); //�������ȡ�ĵ����ַ��Ż�

	string data;
	int index = 0; //��������

	while (ifs >> data)
	{
		vector<string>v; //���6��string�ַ���

		int pos = -1; //�鵽","λ�õı���
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1) //û���ҵ����
			{
				break;
			}
			//�������ַ��� ��start��ʼ ���Ƴ���Ϊposλ�ü�ȥstartλ��
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

//��ʾ�����¼
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������� ���¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "�������¼ " << endl
				<< "�ھ����: " << this->m_Record[i][0] << " �÷�: " << this->m_Record[i][1] << " "
				<< endl
				<< "�Ǿ����: " << this->m_Record[i][2] << " �÷�: " << this->m_Record[i][3] << " "
				<< endl
				<< "�������: " << this->m_Record[i][4] << " �÷�: " << this->m_Record[i][5] << " "
				<< endl;
		}
	}
	system("pause");
	system("cls");
}

//��������
SpeechManager::~SpeechManager()
{

} 