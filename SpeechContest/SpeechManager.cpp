#include<iostream>
#include"SpeechManager.h"
using namespace std;

SpeechManager::SpeechManager()
{
	this->InitSpeech();//��ʼ����Ա���ԡ�
	this->CreateSpeech();//����ѡ��
	//this->ReadSpeech();//��ȡ�����¼
}
SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()//�˵�
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exit_System()//�˳�
{
	cout << "��л����ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::InitSpeech()//��ʼ��
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_LoadSpeech.clear();//��ȡ�ļ�������Ҳ��Ҫ���
	//�������
	this->m_Index = 1;
	//��ʼ����������
}

void SpeechManager::CreateSpeech()//����ѡ��
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;//��ʼ������
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;//��ʼ�����ֱ����ĳɼ���Ϊ0
		}

		//��ű�źͶ�Ӧ��ѡ��
		this->m_Speaker.insert(make_pair(i + 10001, sp));
		
		//��ѡ�ֱ��Ҳ���� v1 ��
		this->v1.push_back(i + 10001);
	}
}

void SpeechManager::DrawSpeech()//��ǩ
{
	cout << "��" << this->m_Index << "�ֳ�ǩ��ʼ" << endl;
	cout << "-------------------------------------" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
	}
	else if (this->m_Index == 2)
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl;
	system("pause");
}
//*****�ص�����******
void SpeechManager::ContestSpeech()//������ʼ
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;

	multimap<double,   int,   greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ��
	       //first   second   ����ʽ
		   //����    ���     ����

	vector<int>temp;//����һ����ʱ�ı�������
	int num = 0;//���ڷ�������ı���num
	if (this->m_Index == 1)
	{
		temp = v1;
	}
	else
	{
		temp = v2;
	}
	//��������
	for (vector<int>::iterator it = temp.begin(); it!=temp.end(); it++)
	{
		num++;
		deque<double>d;//ʹ��deque������¼����
		//����ȥ���ߵͷ�
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//��������

		d.pop_front();
		d.pop_back();//ȥ���ߵͷ�

		double sum = accumulate(d.begin(), d.end(),0.0f);//��ȡ�ܷ�	
		double avg = sum /((double)d.size());//��ȡƽ����	

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;//�����ݼ�¼��m_Speaker������
		                             //this->m_Index-1��ֵ��Ϊ��n�ֵķ���

		//ʹ����ʱ�������������Ľ��
		//6����һ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));//��ŵڱ��Ϊ*it��ѡ�ֵķ���
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int> >::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << "  ������" << this->m_Speaker[it->second].m_Name
					<< "  �ɼ�:" << this->m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
			}

			//ȡǰ����
			int count = 0;
			for (multimap<double, int, greater<int> >::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++,count++)
												//��Ϊ�Ѿ�����������ˣ�ǰ��������ǰ���������ԣ�ȡ�� count<3 ��Ԫ�ؼ���
			{
				if (this->m_Index == 1)//����ǵ�һ�ֱ������򽫸�ѡ�ֵı�Ŵ���v2��
				{
					v2.push_back((*it).second);
				}
				else//����ǵڶ��ֱ������򽫸�ѡ�ֵı�Ŵ���vVictory��
				{
					vVictory.push_back((*it).second);
				}
			}
			//ÿ�β����꣬��Ҫ����ʱ������Ԫ����գ�������һ��ʹ��
			groupScore.clear();
			cout << endl;
		}

	}
	cout << "------------- ��" << this->m_Index << "����ʽ����������------------- " << endl;
	cout << endl;
	system("pause");
}




void SpeechManager::DisplaySpeech()//��ʾ����ѡ��
{
	cout << "---------- ��" << this->m_Index << "�ֽ���ѡ����Ϣ����-----------" << endl;
	vector<int>v;//����һ����ʱ�ı�������
	if (this->m_Index == 1)
	{
		v  = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << "  ����" << this->m_Speaker[*it].m_Name
			<< "  �ɼ���" << this->m_Speaker[*it].m_Score[this->m_Index-1]<< endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::SaveSpeech()//�����¼
{
	ofstream ofs;
	ofs.open("Speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","<<this->m_Speaker[*it].m_Name<<"," << this->m_Speaker[*it].m_Score[this->m_Index - 1] << ",";
	}
	ofs << endl;
	ofs.close();
	this->FileEmpty = false;
	cout << "���μ�¼�Ѿ����棡" << endl;
}

void SpeechManager::ReadSpeech()
{
	ifstream ifs;
	ifs.open("Speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->FileEmpty = true;//�ļ�Ϊ��
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
		ifs.close();//�ر�
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//�����ȡ��������Ϊ��������
	{
		cout << "�ļ�Ϊ�ջ򲻴���!" << endl;
		this->FileEmpty = true;
		ifs.close();
		return;
	}

	//��������״���������������ļ�һ����Ϊ��
	this->FileEmpty = false;
	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ,�����ļ��л���һ���ַ�
	string data;
	int index = 0;
	while (ifs>>data)
	{
		vector<string>v;
		int pos = -1;//����Ƿ��ҵ��ַ��ı���
		int start = 0;
		while (1)
		{
			pos = data.find(",",start);//��startλ�ô�����" , "
			if (pos == -1)
			{
				break;//û�ҵ�������
			}
			string temp;//���ڴ洢�ָ����ַ���
			temp=data.substr(start,pos-start );//��ȡ [start,pos-start] �����ڵ��ַ���
			v.push_back(temp);
			start = pos + 1;//ÿһ�ν�ȡ֮����ʼλ��Ϊ���ź���ַ�
		}
		this->m_LoadSpeech.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void SpeechManager::ShowRead()
{
	this->ReadSpeech();
	for (int i = 0; i < m_LoadSpeech.size(); i++)
	{
		cout << "��" << i + 1 << "���������� " << endl;
		cout << "�ھ���ţ�" << this->m_LoadSpeech[i][0] << "  ������" << this->m_LoadSpeech[i][1] << "  �ɼ���" << this->m_LoadSpeech[i][2] << endl;
		cout<< "�Ǿ���ţ�"  << this->m_LoadSpeech[i][3] << "  ������" << this->m_LoadSpeech[i][4] << "  �ɼ���" << this->m_LoadSpeech[i][5] << endl;
		cout<< "������ţ�"  << this->m_LoadSpeech[i][6] << "  ������" << this->m_LoadSpeech[i][7] << "  �ɼ���" << this->m_LoadSpeech[i][8] << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::ClearSpeech()
{
	int select;
	cout << "���Ƿ����Ҫ��գ�" << endl;
	cout << "����1ȷ�ϡ�" << endl;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("Speech.csv", ios::trunc);
		ofs.close();
		cout << "��ճɹ���" << endl;
	}
	this->m_LoadSpeech.clear();
	system("pause");
	system("cls");

}


void SpeechManager::StartSpeech()//�ݽ���ʼ
{
	
	//��һ�ֱ���
	//Ĭ��  this->m_Index=1
	//1����ǩ
	this->DrawSpeech();
	//2������
	this->ContestSpeech();
	//3����ʾ�������
	this->DisplaySpeech();

	//�ڶ��ֱ���
	this->m_Index++;
	//1����ǩ
	this->DrawSpeech();
	////2������
	this->ContestSpeech();
	////3����ʾ���ս��
	this->DisplaySpeech();
	////4���������
	this->SaveSpeech();
	cout << "���������������" << endl;
	//������������Ҫ���ü�¼
	this->InitSpeech();//�������
	this->CreateSpeech();//����ʮ����ѡ��

}
