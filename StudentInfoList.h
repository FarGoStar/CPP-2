#pragma once
#include <deque>
#include "Elem.h"
#include <iterator>

//Используемый контейнер — deque
class StudentInfoList {
public:
	deque<Elem> deq;
	deque<Elem> helpDeq;

	StudentInfoList() : deq(), helpDeq() {}

	void AddStudentInfo() 
	{
		istream_iterator<Elem> is;
		bool adding = true;
		while (adding) {
			char tmp;
			cout << "1 — Добавить запись" << endl << "2 — Прекратить добавление записей" << endl;
			cout << "Ввод: ";
			cin >> tmp;
			cout << endl;
			cin.get();
			if (tmp == '2')
			{
				adding = false;
			}
			else
			{
				is = cin;
				deq.push_front(*is);
				cout << "Запись добавлена" << endl;
				cout << endl;
			}
		}
	}

	void PrintInfo(deque<Elem>::iterator x) 
	{
		cout << *x;
	}

	void PrintSomeInfo() 
	{
		copy(helpDeq.begin(), helpDeq.end(), ostream_iterator<Elem>(cout, ""));
	}

	void DeleteStudentInfo(deque<Elem>::iterator x) 
	{
		deq.erase(x);
		cout << "Запись удалена из журнала" << endl;
		cout << endl;
	}

	void ChangeStudentInfo(deque<Elem>::iterator x) 
	{
		istream_iterator<Elem> is(cin);
		*x = *is;
		cout << "Запись в журнале сессии изменена" << endl;
		cout << endl;
	}

	void LoadToFile(ofstream& file, deque<Elem>::iterator x) 
	{
		ostream_iterator<Elem> is(file);
		*is = *x;
		cout << "Данные загружены в файл" << endl;
		cout << endl;
	}

	void LoadFromFile(ifstream& file) 
	{
		istream_iterator<Elem> is(file);
		deq.push_front(*is);
		cout << "Запись загружена из файла" << endl;
		cout << endl;
	}

	void LoadSomeInfoFromFile(ifstream& file) 
	{
		istream_iterator<Elem> is(file);
		while (!file.eof()) {
			deq.push_front(*is);
		}
		cout << "Все записи из файла загружены" << endl;
		cout << endl;
	}

};
