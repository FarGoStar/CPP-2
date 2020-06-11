#pragma once
#include "Elem.h"

//Поиск подходящей оценки
struct IsMark
{

	int  mark;

	IsMark(int _mark)
	{
		mark = _mark;
	}

	bool operator()(const Elem& e)
	{
		return e.mark == mark;
	}
};