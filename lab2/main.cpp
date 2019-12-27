#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <windows.h>
#include <math.h>

using namespace std;
struct Discipline
{
    char code_discipl[50]; //��� ����������
    char name_discipl[50];  // �������� ����������
    char teacher_surname[50]; // ������� �������������
    char code_group[50]; //��� ������
    char number_group_s[50]; //���������� ��������� � ������
    int  lecture_hour[50]; // ���������� ����� ������
    int numb_hour_exe[50]; //���������� ����������������� �������
    char test_or_exam[50]; //��� ��������� �������� (����� ��� �������)
    int clas_start_date[50]; //���� ������ �������
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 1;

    Discipline *ds = new Discipline[n];
    for (int i = 0; i < n; i++)
    {
        cout << "������ ����� ���������: ";
        cin >> ds[i].name_discipl;
        cout << "������ ������� ���������: ";
        cin >> ds[i].teacher_surname;
        cout << "������ ��� �����: ";
        cin >> ds[i].code_group;
        cout << "������ ������� �������� � ����: ";
        cin >> ds[i].number_group_s;
        cout << "������ ������� ����� ������: ";
        cin >> ds[i].lecture_hour[i];
        cout << "������ ������� ����� ���������� ������: ";
        cin >> ds[i].numb_hour_exe[i];
        cout << "������ ���� ��� �����: ";
        cin >> ds[i].test_or_exam;
        cout << "������ ���� ������� ������: ";
        cin >> ds[i].clas_start_date[i];
        cout << endl << endl;
    }
    cout << "-----------------------------------------\n";
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << " | Code: " << ds[i].code_discipl << " | Name discipline: " << ds[i].name_discipl
            << " | Teacher surname: " << ds[i].teacher_surname << " | Code group: " << ds[i].code_group << " | Number group of students: " << ds[i].number_group_s
            << " | Lecture hours: " << ds[i].lecture_hour[i] << " | Number of hours practical exercises: " << ds[i].numb_hour_exe[i] << " | Test or Exam: " << ds[i].test_or_exam << " | Class start date: " << ds[i].clas_start_date[i] << endl;
        cout << endl << endl;
    }
    cout << "-----------------------------------------\n";

    char teacherSurname[30];
    cout << "Search in list" << endl;
    cout << "������ ������� ���������: "  << endl;
    cin >> teacherSurname;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(teacherSurname,ds[i].teacher_surname)==0)
        {
            cout << "����� ���������: "<< ds[i].name_discipl<<endl;
            cout << "��� �����: "<< ds[i].code_group<<endl;
            cout << "ʳ������ �������� � ����: "<< ds[i].number_group_s<<endl;
            cout << "ʳ������ ����� (������): "<< ds[i].lecture_hour[i]<<endl;
            cout << "ʳ������ ����� ���������� ������: "<< ds[i].numb_hour_exe[i]<<endl;
            cout << "���� ��� �����: "<< ds[i].test_or_exam<<endl;
            cout << "���� ������� ������: "<< ds[i].clas_start_date[i]<<endl;

        }
        else
        {
            cout << "No Result" << endl;
        }
    }
    int start_date = 0;
    cout << "Sorting" << endl;
    cout << "Enter date"<<endl;
    cin >> start_date;
    Discipline *help = NULL;;
    for (int i = 0; i < n-1; i++)
    {
        if (start_date == ds[i].clas_start_date[i])
        {
            help[i] = ds[i];
            ds[i] = ds[i + 1];
            ds[i + 1] = help[i];
        }
        else
        {
            cout << "No Result" << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "����� ���������: " << ds[i].name_discipl << endl;
        cout << "��� �����: " << ds[i].code_group << endl;
        cout << "ʳ������ �������� � ����: " << ds[i].number_group_s << endl;
        cout << "ʳ������ ����� (������): " << ds[i].lecture_hour[i] << endl;
        cout << "ʳ������ ����� ���������� ������: " << ds[i].numb_hour_exe[i] << endl;
        cout << "���� ��� �����: " << ds[i].test_or_exam << endl;
        cout << "���� ������� ������: " << ds[i].clas_start_date[i] << endl;
    }
    system("pause");
    return 0;
}
