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
		T data;				//Значение
		node *next;			//Указатель на следующий элемент
	};
	node *head;				//Указатель на фиктивный элемент
	node *tile;				//Указатель на конечный элемент
	int size;					//Размер вектора
	int sum_oper;				//Число операций
public:
	list();					//Конструктор
	list(list<T> &a);				//Конструктор копирования
	~list();					//Деструктор
	void Add(T &new_data);			//Добавление элемента
	void Print();				//Вывод
	void RandList(int, int);			//Заполнить случайно
	bool Insert(T &ins_data, int num);		//Вставка
	bool Delete(int num);				//Удаление
	bool DelVal(T &val);			//Удаление по значению
	T&	 Get(int);			//Чтение элемента по индексу
	bool Change(T &ch_data, int num);		//Запись элемента по индексу
	void Clear();				//Очистка списка
	int  Search(T &val);			//Поиск элемента по значению
	int  SumCount()    	//Опрос количества операций
	{
		return sum_oper;
	};
	int  Size()       //Опрос размера списка
	{
		return size;
	};
	class iterator
	{
		node *itcur, *beg;
		bool status;
	public:
		iterator()			//Конструктор итератора
		{
			itcur = NULL;
			status = false;
		}
		bool Status()
		{
			return status;
		}
		bool Iter(node *cur)		//Установить головной элемент списка
		{
			beg = cur;
			itcur = cur;
			status = false;
			return true;
		}
		bool Next()			//Следующий элемент
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
		bool Begin()			//Начало списка
		{
			if (beg->next != beg)
			{
				status = true;
				itcur = beg->next;
				return true;
			}
			return false;
		}
		T& GetData()			//Считать данные
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
//Конструктор
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
//Конструктора копирования
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
//Деструктор
template<class T>
list<T>::~list()
{
	Clear();
	delete head;
}
//-------------------------------------------------------------------------------------------------
// Добавление элемента в список
template<class T>
void list<T>::Add(T &new_data)
{
	node *cur = tile;
	if(cur == NULL) cur = head; //добавление текущего элемента в голову списка
	node *new_node = new node; //выделение памяти
	new_node->data = new_data;
	cur->next = new_node;
	new_node->next = head;
	tile = new_node;
	size++;
}
//-------------------------------------------------------------------------------------------------
//Вывод списка на экран
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
//Случайные значения
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
//Вставка нового элемента в позицию
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
//Удаление элемента из позиции
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
//Удаление по значению
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
//Очистить список
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
//Поиск элемента по индексу
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
//Поиск элемента по значению
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
//Изменение элемента с заданным значением
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
	int i; //кнопка выбора
	cout << endl << "------       Меню:    ------" << endl
		<< "1. Добавить элемент в список." << endl
		<< "2. Заполнить список случайно. " << endl
		<< "3. Показать список." << endl
		<< "4. Вывести размер списка." << endl
		<< "5. Вставка элемента." << endl
		<< "6. Удаление элемента." << endl
		<< "7. Поиск элемента по индексу." << endl
		<< "8. Поиск элемента по значению." << endl
		<< "9. Очистить список." << endl
		<< "10. Изменить значение элемента." << endl
		<< "11. Тест." << endl
		<< "12. Итератор." << endl
		<< "13. Считать значение." << endl
		<< "14. Записать значение." << endl
		<< "15. Переход к следующему элементу." << endl
		<< "16. Переход в начало списка." << endl
		<< "0. Выход." << endl;
	cout << "Выберите нужное действие: ";
	cin >> i;
	return i;
}
//-------------------------------------------------------------------------------------------------
//выбор из меню
void selMenu()
{
	do
	{
		switch(Menu())
		{
		case 1:            //Добавить элемент
			{
				system("cls");
				cout << "Введите значение: ";
			    cin >> data;
				l.Add(data);
				cout << "Значение добавлено." << endl;
				break;
			}
		case 2:            //Ввод размера списка
			{
				int rand_list_size;
				system("cls");
				cout << "Введите размер списка: ";
				cin >> rand_list_size;
				system("cls");
				l.RandList(rand_list_size, 100);
				cout << "Список заполнен случайными числами!" << endl;
				getch();
				break;
			}
		case 3:
			{   // вывод списка
				system("cls");
				if(l.Size() == 0) cout << "Список пуст!";
				else
					l.Print();
				getch();
				break;
			}
		case 4:         //вывод размера
			{
				system("cls");
				if(l.Size() == 0) cout << "Список пуст!";
				else
					cout << "Размер списка: " << l.Size();
				getch();
				break;
			}
		case 5:       //Вставка нового элемента в список в заданную позицию
			{
				int num;
				system("cls");
				cout << "Введите значение: ";
				cin >> data;
				cout << endl << "Введите индекс: ";
				cin >> num;
				if(l.Insert(data, num)) cout << endl << "Новый элемент вставлен." << endl;

				else
				{
					cout << "Элемент вставить не удалось!" << endl;
				}
				getch();
				break;
			}
		case 6:        //Удаление элемента из списка из заданной позиции
			{
				system("cls");
				int num;
				cout << "Введите индекс удаляемого элемента ";
				cin >> num; //Задаем индекс удаляемого элемента
				//Если индекс введен правильно
				if(l.Delete(num)) cout << "Элемент " << num << " удален!" << endl; //то элемент с текущим индексов удаляется
				else //иначе выводим сообщение об ошибке
				{
					cout << "Ошибка! Неверный индекс." << endl;
				}
				getch();
				break;
			}
		case 7:      //Поиск элемента по заданному индексу
			{
				system("cls");
				int num;
				cout << "Введите индекс: ";
				cin >> num;
				try          //Если индекс задан неверно, (находится вне текущего размера)
				{
					cout << endl << endl << "Значение: " << l.Get(num) << endl;
				}
				catch(int) // то обрабатываем ошибку
				{
					cout << "Ошибка! Неверный индекс!" << endl;
				}
				getch();
				break;
			}
		case 8: //Поиск элемента по заданному значению
			{
				system("cls");
				int val;
				cout << "Введите искомое значение: ";
				cin >> val;
				//Если такого значения в списке нет
				if(l.Search(val) == 0)	cout << "Не найдено!"; //то выводится вот это сообщение
				else cout << "Индекс искомого значения: " << l.Search(val); //иначе выводится результат
				getch();
				break;
			}
		case 9: //Очистка списка
			{
				system("cls");
				l.Clear();
				cout << "Список очищен!" << endl;
				getch();
				break;
			}
		case 10:   //Изменение значения из списка с заданным индексом
			{
				int num = 0;
				system("cls");
				cout << "Введите индекс: ";
				cin >> num;
				cout << "Введите значение: ";
				cin >> data;
				//Если ввели значение и индекс вверно
				if(l.Change(data, num)) cout << "Значение изменено." << endl; // то выводится вот это сообщение
				else //Если индекс находится вне текущего рзмера
				{
					cout << "Значение изменить не удалось!" << endl; // то выводится вот это сообщение
				}
				getch();
				break;
			}
			//тестирования трудоёмкости операций поиска, вставки и удаления.
			//Размер списка от 10 до 100000
		case 11:
			{
				l.Clear(); //Очистка списка
				int sum_search=0, sum_del=0, sum_ins=0;
				int test_size=0, rnd=0, oper=0, rnd_s=0, rnd_e;
				system("cls");
				cout << "Введите размер списка: ";
				cin >> test_size; //Задаем размер списка
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
				cout << "Размер списка: " << test_size << endl << endl;
				cout << "Cредняя трудоёмкость операций: " << endl;
				//среднее число просмотренных элементов списка
				cout << endl << "Поиск: " << (double)sum_search / oper << endl;
				cout << "Удаление: " << (double)sum_del / oper << endl;
				cout << "Вставка: " << (double)sum_ins / oper << endl;
				getch();
				break;
			}
		case 12:
			{
				if(l.it.Status()) cout << endl << "В списке ";
				else cout << endl << "Вне списка ";
				getch();
				break;
			}
		case 13:
			{
				try
				{
					cout << endl << endl << "Значение: " << l.it.GetData();
				}
				catch(int)
				{
					cout << endl << "Ошибка!";
				}
				getch();
				break;
			}
		case 14:
			{
				try
				{
					cout << endl << endl << "Введите значение ";
					cin >> l.it.GetData();
				}
				catch(int)
				{
					cout << "Ошибка";
				}
				getch();
				break;
			}
		case 15:
			{
				if(l.it.Next());
				else cout << "Ошибка";
				getch();
				break;
			}
		case 16:
			{
				if(l.it.Begin());
				else cout << "Ошибка";
				getch();
				break;
			}
		case 17: //Удаление элемента по индексу
			{
				system("cls");
				int val;
				cout << "Введите значение: ";
				cin >> val;
				if(l.DelVal(val));
				else
				{
					cout << "Ошибка! Неверный индекс.";
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

