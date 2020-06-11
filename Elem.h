#pragma once
#include <iostream>
#include <fstream>
using namespace std;

//Класс записи
class Elem {
public:
	int course;
	int group;
	string surname;
	int creditNum;
	string disc; 
	int mark;

	Elem(int _course, int _group, string _surname,
		int _creditNum,	string _disc, int _mark)
	{
		course	  = _course;
		group	  = _group;
		surname	  = _surname;
		creditNum = _creditNum;
		disc      = _disc;
		mark	  = _mark;

	}

	Elem() 
	{
		course	  = 1;
		group	  = 1;
		surname	  = "Иванов";
		creditNum = 100;
		disc	  = "ЯСП";
		mark	  = 3;
	}

	Elem& operator=(const Elem& e) {
		course	  = e.course;
		group	  = e.group;
		surname	  = e.surname;
		creditNum = e.creditNum;
		disc	  = e.disc;
		mark	  = e.mark;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Elem& e)
	{
		if (typeid(os) == typeid(ofstream))
		{
			os << e.course << endl;
			os << e.group << endl;
			os << e.surname << endl;
			os << e.creditNum << endl;
			os << e.disc << endl;
			os << e.mark << endl;
			return os;
		}
		else
		{

			os << "Запись в журнале сессии: " << endl;
			os << "Курс: " << e.course << " Группа: " << e.group << endl;
			os << "Фамилия: " << e.surname << endl;
			os << "Номер зачетной книжки: " << e.creditNum << endl;
			os << "Дисциплина: " << e.disc << " Оценка: " << e.mark << endl;
			return os;
		}
	}

	friend istream& operator>>(istream& is, Elem& e) {

		cout << "Введите запись в журнале сессии: " << endl;
		cout << endl;

		int course;
		int group;
		string surname;
		int creditNum;
		string disc;
		int mark;
		cout << "Курс: "; is >> course;
		cout << "Группа: "; is >> group;
		cout << "Фамилия: "; is >> surname;
		cout << "Номер зачетной книжки: "; is >> creditNum;
		cout << "Дисциплина: "; is >> disc;
		cout << "Оценка: "; is >> mark;
		e = Elem(course, group, surname, creditNum, disc, mark);
		return is;
	}
};
