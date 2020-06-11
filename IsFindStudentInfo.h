#pragma once
#include <string>
#include "Elem.h"

//Поиск подходящей записи
struct IsFindStudentInfo {
	int course;
	int group;
	string surname;
	int mark;
	int creditNum;
	IsFindStudentInfo(int _course, int _group, string _surname,
		int _creditNum, int _mark)
	{
		course = _course;
		group = _group;
		surname = _surname;
		mark = _mark;
		creditNum = _creditNum;
	}
	bool operator()(const Elem& e)
	{
		return (course == e.course)
			&& (group == e.group)
			&& (surname == e.surname)
			&& (mark == e.mark)
			&& (creditNum == e.creditNum);
	}
};