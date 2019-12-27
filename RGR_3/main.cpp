#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

template<class T> class list
{
	struct node
	{
		T data;				//��������
		node *next;			//��������� �� ��������� �������
	};
	node *head;				//��������� �� ��������� �������
	node *tile;				//��������� �� �������� �������
	int size;					//������ �������
	int sum_oper;				//����� ��������
public:
	list();					//�����������
	list(list<T> &a);				//����������� �����������
	~list();					//����������
	void Add(T &new_data);			//���������� ��������
	void Print();				//�����
	void RandList(int, int);			//��������� ��������
	bool Insert(T &ins_data, int num);		//�������
	bool Delete(int num);				//��������
	bool DelVal(T &val);			//�������� �� ��������
	T&	 Get(int);			//������ �������� �� �������
	bool Change(T &ch_data, int num);		//������ �������� �� �������
	void Clear();				//������� ������
	int  Search(T &val);			//����� �������� �� ��������
	int  SumCount()    	//����� ���������� ��������
	{
		return sum_oper;
	};
	int  Size()       //����� ������� ������
	{
		return size;
	};
	class iterator
	{
		node *itcur, *beg;
		bool status;
	public:
		iterator()			//����������� ���������
		{
			itcur = NULL;
			status = false;
		}
		bool Status()
		{
			return status;
		}
		bool Iter(node *cur)		//���������� �������� ������� ������
		{
			beg = cur;
			itcur = cur;
			status = false;
			return true;
		}
		bool Next()			//��������� �������
		{
			if(status)
			{
				itcur = itcur->next;
				if(itcur == beg) status = false;
			}
			else
				return false;
			return true;
		}
		bool Begin()			//������ ������
		{
			if (beg->next != beg)
			{
				status = true;
				itcur = beg->next;
				return true;
			}
			return false;
		}
		T& GetData()			//������� ������
		{
			if((itcur != beg) && (itcur != NULL))
			return itcur->data;
			else throw -1;
		}
	};
	iterator it;
};
list<int> l;
int data;
//-------------------------------------------------------------------------------------------------
//�����������
template<class T>
list<T>::list()
{
	head = new node;
	head->next = head;
	tile = NULL;
	it.Iter(head);
	size = 0;
	sum_oper = 0;
}
//-------------------------------------------------------------------------------------------------
//������������ �����������
template<class T>
list<T>::list(list<T> &a)
{
	node *pcur, *new_node;
	head = new node;
	pcur = head;
	for(node *cur=a->head->next; cur!=a->head; cur=cur->next)
	{
		new_node = new node;
		new_node->data = cur->data;
		pcur->next = new_node;
		pcur = new_node;
	}
	pcur->next = head;
	tile = pcur;
	if(tile == head) tile = NULL;
	it.Iter(head);
	size = 0;
	sum_oper = 0;
}
//-------------------------------------------------------------------------------------------------
//����������
template<class T>
list<T>::~list()
{
	Clear();
	delete head;
}
//-------------------------------------------------------------------------------------------------
// ���������� �������� � ������
template<class T>
void list<T>::Add(T &new_data)
{
	node *cur = tile;
	if(cur == NULL) cur = head; //���������� �������� �������� � ������ ������
	node *new_node = new node; //��������� ������
	new_node->data = new_data;
	cur->next = new_node;
	new_node->next = head;
	tile = new_node;
	size++;
}
//-------------------------------------------------------------------------------------------------
//����� ������ �� �����
template<class T>
void list<T>::Print()
{
	for(node *cur=head->next; cur!=head; cur=cur->next)
	{
		cout << setw(5) << cur->data;
	}
	cout << endl;
}
//-------------------------------------------------------------------------------------------------
//��������� ��������
template<class T>
void list<T>::RandList(int rand_list_size, int rand_list_interval)
{
	Clear();
	srand((unsigned)time( NULL ));
	for(int i=0; i<rand_list_size; i++)
	{
		int r = rand()*rand()%rand_list_interval;
		Add(r);
	}
}
//-------------------------------------------------------------------------------------------------
//������� ������ �������� � �������
template<class T>
bool list<T>::Insert(T &ins_data,int num)
{
	sum_oper = 0;
	int i = 0;
	node *new_node = new node;
	if(num > size+1 || num <= 0)
	{
		return false;
	}
	node *cur = head;
	for(; i!=num-1; cur=cur->next)
	{
		i++;
		sum_oper++;
	}
	new_node->data = ins_data;
	new_node->next = cur->next;
	cur->next = new_node;
	size++;
	if(num == size) tile = new_node;
	return true;
}
//-------------------------------------------------------------------------------------------------
//�������� �������� �� �������
template<class T>
bool list<T>::Delete(int num)
{
	sum_oper = 0;
	int i = 0;
	if(num > size || num<=0)
	{
		return false;
	}
	node *cur = head;
	for(; i!=num-1; cur=cur->next)
	{
		i++;
		sum_oper++;
	}
	node *dcur = cur->next;
	cur->next = dcur->next;
	delete dcur;
	size--;
	return true;
}
//-------------------------------------------------------------------------------------------------
//�������� �� ��������
template<class T>
bool list<T>::DelVal(T &val)
{
	node *cur;
	int i = 1;
	if(val < 0 || head->next == head)
	{
		return false;
	}
	cur = head->next;

	node *pcur = head;
	for(; ((cur->data!=val)&&(cur!=head)); pcur=pcur->next)
	{
		i++;
		cur = cur->next;
	}
	if (cur == head)
	{
		return false;
	}
	pcur->next = cur->next;
	delete cur;
	size--;
	return true;
}
//-------------------------------------------------------------------------------------------------
//�������� ������
template<class T>
void list<T>::Clear()
{
	node *cur = head->next;
	node *temp;
	while(cur != head)
	{
		temp = cur->next;
		delete cur;
		cur = temp;
	}
	head->next = head;
	tile = NULL;
	sum_oper = 0;
	size = 0;
}
//-------------------------------------------------------------------------------------------------
//����� �������� �� �������
template<class T>
T& list<T>::Get(int num)
{
	int i = 0;
	if((num > 0) && (num <= size))
	{
		if(num == size) return tile->data;
		node *cur = head;
		for(; i!=num; cur=cur->next)
		{
			i++;
		}
		return cur->data;
	}
	else throw -1;
}
//-------------------------------------------------------------------------------------------------
//����� �������� �� ��������
template<class T>
int list<T>::Search(T &val)
{
	node *cur = head->next;
	sum_oper = 0;
	int i = 1;
	if(val < 0 || head->next==head)
	{
		return 0;
	}
	for(; ((cur->data!=val)&&(cur!=head)); cur=cur->next)
	{
		i++;
		sum_oper++;
	}
	if (cur == head)
	{
		i=0;
	}
	return i;
}
//-------------------------------------------------------------------------------------------------
//��������� �������� � �������� ���������
template<class T>
bool list<T>::Change(T &ch_data, int num)
{
	int i=0;
	if(num > size || num <= 0)
	{
		return false;
	}
	node *cur = head;
	for(; i!=num; cur=cur->next)
	{
		i++;
	}
	cur->data = ch_data;
	return true;
}
//-------------------------------------------------------------------------------------------------
int Menu()
{
	system("cls");
	int i; //������ ������
	cout << endl << "------       ����:    ------" << endl
		<< "1. �������� ������� � ������." << endl
		<< "2. ��������� ������ ��������. " << endl
		<< "3. �������� ������." << endl
		<< "4. ������� ������ ������." << endl
		<< "5. ������� ��������." << endl
		<< "6. �������� ��������." << endl
		<< "7. ����� �������� �� �������." << endl
		<< "8. ����� �������� �� ��������." << endl
		<< "9. �������� ������." << endl
		<< "10. �������� �������� ��������." << endl
		<< "11. ����." << endl
		<< "12. ��������." << endl
		<< "13. ������� ��������." << endl
		<< "14. �������� ��������." << endl
		<< "15. ������� � ���������� ��������." << endl
		<< "16. ������� � ������ ������." << endl
		<< "0. �����." << endl;
	cout << "�������� ������ ��������: ";
	cin >> i;
	return i;
}
//-------------------------------------------------------------------------------------------------
//����� �� ����
void selMenu()
{
	do
	{
		switch(Menu())
		{
		case 1:            //�������� �������
			{
				system("cls");
				cout << "������� ��������: ";
			    cin >> data;
				l.Add(data);
				cout << "�������� ���������." << endl;
				break;
			}
		case 2:            //���� ������� ������
			{
				int rand_list_size;
				system("cls");
				cout << "������� ������ ������: ";
				cin >> rand_list_size;
				system("cls");
				l.RandList(rand_list_size, 100);
				cout << "������ �������� ���������� �������!" << endl;
				getch();
				break;
			}
		case 3:
			{   // ����� ������
				system("cls");
				if(l.Size() == 0) cout << "������ ����!";
				else
					l.Print();
				getch();
				break;
			}
		case 4:         //����� �������
			{
				system("cls");
				if(l.Size() == 0) cout << "������ ����!";
				else
					cout << "������ ������: " << l.Size();
				getch();
				break;
			}
		case 5:       //������� ������ �������� � ������ � �������� �������
			{
				int num;
				system("cls");
				cout << "������� ��������: ";
				cin >> data;
				cout << endl << "������� ������: ";
				cin >> num;
				if(l.Insert(data, num)) cout << endl << "����� ������� ��������." << endl;

				else
				{
					cout << "������� �������� �� �������!" << endl;
				}
				getch();
				break;
			}
		case 6:        //�������� �������� �� ������ �� �������� �������
			{
				system("cls");
				int num;
				cout << "������� ������ ���������� �������� ";
				cin >> num; //������ ������ ���������� ��������
				//���� ������ ������ ���������
				if(l.Delete(num)) cout << "������� " << num << " ������!" << endl; //�� ������� � ������� �������� ���������
				else //����� ������� ��������� �� ������
				{
					cout << "������! �������� ������." << endl;
				}
				getch();
				break;
			}
		case 7:      //����� �������� �� ��������� �������
			{
				system("cls");
				int num;
				cout << "������� ������: ";
				cin >> num;
				try          //���� ������ ����� �������, (��������� ��� �������� �������)
				{
					cout << endl << endl << "��������: " << l.Get(num) << endl;
				}
				catch(int) // �� ������������ ������
				{
					cout << "������! �������� ������!" << endl;
				}
				getch();
				break;
			}
		case 8: //����� �������� �� ��������� ��������
			{
				system("cls");
				int val;
				cout << "������� ������� ��������: ";
				cin >> val;
				//���� ������ �������� � ������ ���
				if(l.Search(val) == 0)	cout << "�� �������!"; //�� ��������� ��� ��� ���������
				else cout << "������ �������� ��������: " << l.Search(val); //����� ��������� ���������
				getch();
				break;
			}
		case 9: //������� ������
			{
				system("cls");
				l.Clear();
				cout << "������ ������!" << endl;
				getch();
				break;
			}
		case 10:   //��������� �������� �� ������ � �������� ��������
			{
				int num = 0;
				system("cls");
				cout << "������� ������: ";
				cin >> num;
				cout << "������� ��������: ";
				cin >> data;
				//���� ����� �������� � ������ ������
				if(l.Change(data, num)) cout << "�������� ��������." << endl; // �� ��������� ��� ��� ���������
				else //���� ������ ��������� ��� �������� ������
				{
					cout << "�������� �������� �� �������!" << endl; // �� ��������� ��� ��� ���������
				}
				getch();
				break;
			}
			//������������ ����������� �������� ������, ������� � ��������.
			//������ ������ �� 10 �� 100000
		case 11:
			{
				l.Clear(); //������� ������
				int sum_search=0, sum_del=0, sum_ins=0;
				int test_size=0, rnd=0, oper=0, rnd_s=0, rnd_e;
				system("cls");
				cout << "������� ������ ������: ";
				cin >> test_size; //������ ������ ������
				system("cls");
				oper = test_size / 10;
				if (oper > 1000) oper = 100;
				if (oper > 10000) oper = 10;
				srand((unsigned)time(NULL));
				l.RandList(test_size, 2*test_size);
				for(int i=0; i<oper; i++)
				{
					rnd = rand()*rand()%100;
					rnd_e = rand()*rand()%test_size;
					l.Delete(rnd_e);
					sum_del += l.SumCount();
					rnd_e = rand()*rand()%test_size;
					l.Insert(rnd, rnd_e);
					sum_ins += l.SumCount();
					rnd_s = rand()*rand()%(2*test_size);
					l.Search(rnd_s);
					sum_search += l.SumCount();
				}
				cout << "������ ������: " << test_size << endl << endl;
				cout << "C������ ����������� ��������: " << endl;
				//������� ����� ������������� ��������� ������
				cout << endl << "�����: " << (double)sum_search / oper << endl;
				cout << "��������: " << (double)sum_del / oper << endl;
				cout << "�������: " << (double)sum_ins / oper << endl;
				getch();
				break;
			}
		case 12:
			{
				if(l.it.Status()) cout << endl << "� ������ ";
				else cout << endl << "��� ������ ";
				getch();
				break;
			}
		case 13:
			{
				try
				{
					cout << endl << endl << "��������: " << l.it.GetData();
				}
				catch(int)
				{
					cout << endl << "������!";
				}
				getch();
				break;
			}
		case 14:
			{
				try
				{
					cout << endl << endl << "������� �������� ";
					cin >> l.it.GetData();
				}
				catch(int)
				{
					cout << "������";
				}
				getch();
				break;
			}
		case 15:
			{
				if(l.it.Next());
				else cout << "������";
				getch();
				break;
			}
		case 16:
			{
				if(l.it.Begin());
				else cout << "������";
				getch();
				break;
			}
		case 17: //�������� �������� �� �������
			{
				system("cls");
				int val;
				cout << "������� ��������: ";
				cin >> val;
				if(l.DelVal(val));
				else
				{
					cout << "������! �������� ������.";
				}
				getch();
				break;
			}
		default: return;
		}
	}
	while (1);
}
//-------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	system("cls");
	selMenu();
}

