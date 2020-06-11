

/* Задача №9
Запись в журнале экзаменационной сессии содержит следующую информацию:
курс, код группы, фамилия студента, номер зачетной книжки, дисциплина, оценка
по дисциплине. Вычисляются средние баллы по дисциплине, по группе, по курсу.
Поиск по группе, по курсу, по номеру зачетной книжки, по фамилии, по оценкам.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include "IsGroup.h"
#include "IsCourse.h"
#include "IsCreditNum.h"
#include "IsFindStudentInfo.h"
#include "StudentInfoList.h"
#include "IsSurname.h"
#include "IsMark.h"
#include "IsFindForAvg.h"

using namespace std;


void menu()
{
	cout << "1 — Добавить запись в журнал" << endl;
	cout << "2 — Изменить запись в журнале" << endl;
	cout << "3 — Удалить запись из журнала" << endl;
	cout << "4 — Найти запись по введенным данным" << endl;
	cout << "5 — Найти все записи по определенному критерию" << endl;
	cout << "6 — Вычислить средний балл по дисциплине, курсу и номеру группы" << endl;
	cout << "Если хотите выйти из программы - нажмите 0" << endl;
	cout << "Ввод: ";
}

void submenu()
{
	cout << "1 — Выборка записей по курсу" << endl;
	cout << "2 — Выборка записей по номеру группы" << endl;
	cout << "3 — Выборка записей по фамилии студентов" << endl;
	cout << "4 — Выборка записей по номеру зачетной книжки" << endl;
	cout << "5 — Выборка записей по оценке" << endl;
	cout << "Ввод: ";
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool control = true, control2 = true;
	StudentInfoList list;
	int _course;
	int _group;
	string _surname;
	int _creditNum;
	int _mark;
	string _disc;
	double sum;
	int count;
	double avg;
	deque<Elem>::iterator x;
	char tmp;
	string tmp2;
	char tmp3;
	while (control) {
		menu();
		cin >> tmp;
		cin.get();
		cout << endl;

		switch (tmp) {
		case '1':
			cout << "1 — Ввод данных с клавиатуры" << endl;
			cout << "2 — Загрузка данных из файла" << endl;
			cout << "Ввод :";
			cin >> tmp;
			cin.get();
			cout << endl;
			if (tmp == '1')
				list.AddStudentInfo();
			if (tmp == '2')
			{
				cout << "Введите имя файла: ";
				cin >> tmp2;
				cout << endl;
				tmp2 += ".txt";
				ifstream _file(tmp2, ios_base::in);
				cout << "1 — Загрузка всех записей из файла" << endl;
				cout << "2 — Загрузка одной записи из файла" << endl;
				cout << "Ввод :";
				cout << endl;
				cin >> tmp;
				cin.get();
				if (tmp == '1')
					list.LoadSomeInfoFromFile(_file);
				if (tmp == '2')
					list.LoadFromFile(_file);
				cout << "Данные успешно добавлены." << endl;
				cout << endl;
			}
			break;

		case '2':

			cout << "Введите номер курса: ";  cin >> _course; cout << endl;
			cout << "Введите номер группы: ";  cin >> _group; cout << endl;
			cout << "Введите фамилию: ";  cin >> _surname; cout << endl;
			cout << "Введите номер зачетной книжки: ";  cin >> _creditNum; cout << endl;
			cout << "Введите оценку: ";  cin >> _mark; cout << endl;
			x = find_if(list.deq.begin(), list.deq.end(), IsFindStudentInfo(_course, _group, _surname, _creditNum, _mark));
			list.PrintInfo(x);
			cout << endl;
			cout << "Если хотите перед изменением сохранить данные в файл - нажмите 1, если нет - нажмите 0" << endl;
			cout << "Ввод: ";
			cout << endl;
			cin >> tmp;
			if (tmp == '1')
			{
				string _tmp2;
				cout << "Введите имя файла: ";
				cin >> _tmp2;
				_tmp2 += ".txt";
				ofstream _file(_tmp2, ios_base::app);
				list.LoadToFile(_file, x);
			}
			list.ChangeStudentInfo(x);
			break;

		case '3':
			cout << "Введите номер курса: ";  cin >> _course; cout << endl;
			cout << "Введите номер группы: ";  cin >> _group; cout << endl;
			cout << "Введите фамилию: ";  cin >> _surname; cout << endl;
			cout << "Введите номер зачетной книжки: ";  cin >> _creditNum; cout << endl;
			cout << "Введите оценку: ";  cin >> _mark; cout << endl;
			x = find_if(list.deq.begin(), list.deq.end(), IsFindStudentInfo(_course, _group, _surname, _creditNum, _mark));
			list.PrintInfo(x);
			list.DeleteStudentInfo(x);
			cout << "Удалено." << endl;
			break;

		case '4':
			cout << "Введите номер курса: ";  cin >> _course; cout << endl;
			cout << "Введите номер группы: ";  cin >> _group; cout << endl;
			cout << "Введите фамилию: ";  cin >> _surname; cout << endl;
			cout << "Введите номер зачетной книжки: ";  cin >> _creditNum; cout << endl;
			cout << "Введите оценку: ";  cin >> _mark; cout << endl;
			x = find_if(list.deq.begin(), list.deq.end(), IsFindStudentInfo(_course, _group, _surname, _creditNum, _mark));;
			list.PrintInfo(x);
			cout << endl;
			break;
		case '5':
			while (control2)
			{
				submenu();
				cin >> tmp;
				cin.get();
				switch (tmp)
				{
				case '1':
					cout << "Курс: "; cin >> _course;
					copy_if(list.deq.begin(), list.deq.end(), list.helpDeq.begin(), IsCourse(_course));
					list.PrintSomeInfo();
					break;

				case '2':
					cout << "Номер группы: "; cin >> _group;
					copy_if(list.deq.begin(), list.deq.end(), list.helpDeq.begin(), IsGroup(_group));
					list.PrintSomeInfo();
					break;
				case '3':
					cout << "Фамилия: "; cin >> _surname;
					copy_if(list.deq.begin(), list.deq.end(), list.helpDeq.begin(), IsSurname(_surname));
					list.PrintSomeInfo();
					break;
				case '4':
					cout << "Номер зачетной книжки: "; cin >> _creditNum;
					copy_if(list.deq.begin(), list.deq.end(), list.helpDeq.begin(), IsCreditNum(_creditNum));
					list.PrintSomeInfo();
					break;
				case '5':
					cout << "Оценка: "; cin >> _mark;
					copy_if(list.deq.begin(), list.deq.end(), list.helpDeq.begin(), IsMark(_mark));
					list.PrintSomeInfo();
					break;
				case '0':
					control2 = false;
					break;
				}
			}
			break;
		case '6':
			avg = 0;
			sum = 0;
			count = 0;
			cout << "Введите номер курса: ";  cin >> _course; cout << endl;
			cout << "Введите номер группы: ";  cin >> _group; cout << endl;
			cout << "Введите дисциплину: "; cin >> _disc; cout << endl;			
			for_each(list.deq.begin(), list.deq.end(), [&](const Elem& e) {IsFindForAvg avgPred = IsFindForAvg(_course, _group, _disc);  if (avgPred.Find(e)) { sum += e.mark; count++; }	});
			avg = sum / count;
			cout << "Средний балл по заданным параметрам = " << avg << endl;
			break;
		case '0':
			control = false;
			break;

		}
	}

}
