#pragma once
#include <string>
#include "Elem.h"

//Поиск подходящей записи по курсу, номеру группы и дисциплине для нахождения среднего балла
struct IsFindForAvg {
	int course;
	int group;
	string disc;
	IsFindForAvg(int _course, int _group, string _disc)
	{
		course = _course;
		group = _group;
		disc = _disc;
	}
	bool Find(const Elem& e)
	{
		return (course == e.course)
			&& (group == e.group)
			&& (disc == e.disc);
	}
};