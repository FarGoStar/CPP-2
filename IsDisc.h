#pragma once
#include <string>
#include "Elem.h"

//Поиск подходящей дисциплины
struct IsDisc
{

	string  disc;

	IsDisc(string _disc)
	{
		disc = _disc;
	}

	bool operator()(const Elem& e)
	{
		return e.disc == disc;
	}
};