//#include  "workerManager.h"
//#include<iostream>//���������ͷ�ļ�
//using namespace std;//ʹ�ñ�׼�����ռ�
//
//WorkerManager::WorkerManager()//���캯��ʵ��
//{
//	//---1   �ļ�������
//	ifstream ifs;
//	ifs.open(filename, ios::in);
//	if (ifs.is_open() == 0)//�ж��ļ��Ƿ�򿪳ɹ����ɹ��򷵻�true
//	{
//		cout << "�ļ�������" << endl;
//		//��ʼ������
//		this->m_EmpNum = 0;//��ʼ�ļ��е�����Ϊ0
//		this->m_EmpArray = NULL;//��ʼ����ָ��ָ���
//		this->filehave = true;//����־��Ϊtrue
//		ifs.close();//�ر��ļ�
//		return;//����
//	}
//
//	//---2   �ļ����� ����Ϊ��
//	char ch;
//	ifs >> ch;//ʹ��>>��ȡһ���ַ�
//	if (ifs.eof() == 1)//�ж϶�ȡ�����ַ��Ƿ�Ϊ������־
//	{
//		cout << "�ļ�Ϊ��" << endl;
//		this->m_EmpNum = 0;//��ʼ�ļ��е�����Ϊ0
//		this->m_EmpArray = NULL;//��ʼ����ָ��ָ���
//		this->filehave = true;//����־��Ϊtrue
//		ifs.close();//�ر��ļ�
//		return;//����
//	}
//
//	//---3   �ļ����� ���Ѽ�¼����
//	int num = this->getm_EmpNum();
//	cout << "ְ������Ϊ:" << num << endl;
//	this->m_EmpNum = num;
//	this->m_EmpArray = new Worker *[this->m_EmpNum];
//	this->initEmp();
//	//���Դ���
//	for (int i = 0; i < this->m_EmpNum; i++)
//	{
//		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id << endl;
//		cout << "ְ��������" << this->m_EmpArray[i]->m_Name << endl;
//		cout << "ְ�����ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
//	}
//
//}
//
//WorkerManager::~WorkerManager()//��������ʵ��
//{
//	if (this->m_EmpArray != NULL)
//	{
//		for (int i = 0; i < this->m_EmpNum; i++)
//		{
//			if (this->m_EmpArray[i] != NULL)
//			{
//				delete[] this->m_EmpArray[i];
//				this->m_EmpArray[i] = NULL;
//			}
//		}
//		delete[] this->m_EmpArray;
//		this->m_EmpArray = NULL;
//	}
//}
//
//void WorkerManager::add_Emp()//���ְ������
//{
//	cout << "��������Ҫ��ӵ���ְ��������" << endl;
//	int addnum;
//	cin >> addnum;
//	if (addnum > 0)
//	{
//		//������Ҫ��ӵ����ݿռ��С
//		int newsize = this->m_EmpNum + addnum;
//		//�����ռ�=ԭ��¼����+��������
//		Worker **newspace;
//		newspace = new Worker*[newsize];//new����ֵ��ָ��ĵ�ַ
//
//		//ע�⣺new���������Ķ���������Ҫ��һ��ָ��������
//		//������ĳ�Ա����ָ�룬�����Ҫ��һ������ָ��ȥ����
//
//		//����ԭ���Ŀռ����������ݣ�����Ҫ��ԭ��������
//		//�������¿ռ���
//
//		if (this->m_EmpArray != NULL)//����ԭ������
//		{
//			for (int i = 0; i < this->m_EmpNum; i++)
//			{
//				newspace[i] = this->m_EmpArray[i];//��������
//			}
//		}
//		for (int i = 0; i < addnum; i++)//�������
//		{
//			int id;
//			string name;
//			int did;
//			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
//			cin >> id;
//			cout << "�������" << i + 1 << "��ְ����������" << endl;
//			cin >> name;
//			cout << "��ѡ���ְ���ĸ�λ:" << endl;
//			cout << "1.��ͨԱ��" << endl;
//			cout << "2.����" << endl;
//			cout << "3.�ϰ�" << endl;
//			cin >> did;
//			//ʹ�ö�̬����ͬ��Ա������
//			Worker *worker = NULL;
//			switch (did)
//			{
//			case 1:
//				worker = new Employee(id, name, 1);
//				break;
//			case 2:
//				worker = new Manager(id, name, 2);
//				break;
//			case 3:
//				worker = new BOSS(id, name, 3);
//				break;
//			default:
//				break;
//			}
//			//��������ְ��ָ�룬��Ҫ���浽ָ��������
//			newspace[this->m_EmpNum + i] = worker;
//		}
//		//������֮����Ҫɾ��ԭ�е��ڴ�ռ�		
//		delete[] this->m_EmpArray;//�ͷ�����ռ���Ҫ+[]
//
//		//�����¿ռ��ָ��
//		this->m_EmpArray = newspace;
//
//		//�����µ�ְ������
//		this->m_EmpNum = newsize;
//
//		this->save();//����save����
//		this->filehave = false;//���ļ����ڱ�־λ��Ϊfalse(��Ϊ��)
//
//		cout << "�ɹ����" << addnum << "����ְ����" << endl;
//
//
//	}
//	else
//	{
//		cout << "������������" << endl;
//	}
//	system("pause");
//	system("cls");
//}
//
//int WorkerManager::getm_EmpNum()//��ȡְ����������
//{
//	ifstream ifs;
//	ifs.open(filename, ios::in);
//	int id;
//	string name;
//	int did;
//	int num = 0;
//	while (ifs >> id && ifs >> name && ifs >> did)
//	{
//		num++;
//	}
//	ifs.close();
//	return num;
//}
//
//
//
//void WorkerManager::initEmp()//��ʼ��ְ������
//{
//	ifstream ifs;
//	ifs.open(filename, ios::in);
//	int id;
//	string name;
//	int did;
//	int index = 0;//���ڼ����ı���index
//	while (ifs >> id, ifs >> name, ifs >> did)
//	{
//		Worker *worker = NULL;
//		//���ö�̬���ݲ�ͬ�Ĳ���Idָ��ͬ�Ķ���
//		if (did == 1)//��ͨԱ��
//		{
//			worker = new Employee(id, name, did);
//		}
//		else if (did == 2)//����
//		{
//			worker = new Manager(id, name, did);
//		}
//		else if (did == 3)//�ϰ�
//		{
//			worker = new BOSS(id, name, did);
//		}
//		this->m_EmpArray[index] = worker;//����ȡ�������ݵݽ���m_EmpArray����
//		index++;
//	}
//	ifs.close();
//}
//
//void WorkerManager::save()//���ݱ��浽�ļ�����
//{
//	ofstream ofs;//�������������
//	ofs.open(filename, ios::app);//ʹ��׷�ӵķ�ʽ���ļ�
//	for (int i = 0; i < this->m_EmpNum; i++)//д���ļ�
//	{
//		ofs << this->m_EmpArray[i]->m_Id << " "
//			<< this->m_EmpArray[i]->m_Name << " "
//			<< this->m_EmpArray[i]->m_DeptId << endl;
//	}
//	ofs.close();//�ر��ļ�
//
//}
//void WorkerManager::show_Menu()//�˵�����
//{
//	cout << "********************************************" << endl;
//	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
//	cout << "*************  0.�˳��������  *************" << endl;
//	cout << "*************  1.����ְ����Ϣ  *************" << endl;
//	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
//	cout << "*************  3.ɾ����ְְ��  *************" << endl;
//	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
//	cout << "*************  5.����ְ����Ϣ  *************" << endl;
//	cout << "*************  6.���ձ������  *************" << endl;
//	cout << "*************  7.��������ĵ�  *************" << endl;
//	cout << "********************************************" << endl;
//	cout << endl;
//}
//
//void WorkerManager::ExirSystem()//ϵͳ�˳�����
//void WorkerManager::ExirSystem()//ϵͳ�˳�����
//{
//	cout << "��ӭ�´�ʹ��" << endl;
//	system("pause");
//	exit(0);
//}
