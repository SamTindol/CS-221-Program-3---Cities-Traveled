#include "ItemType.h"
#include <iostream>
using namespace std;


bool ItemType::operator < (ItemType &item)
{
	return city > item.city;
}

bool ItemType::operator > (ItemType &item)
{
	return city < item.city;
}

bool ItemType::operator == (ItemType &item)
{
	return city == item.city;
}

ItemType::ItemType()
{
	date = 19700101;
	city = "Nowhere";
}

ItemType::~ItemType()
{
	date = 19700101;
	city = "Nowhere";
}

ItemType::ItemType(int myDate, string myCity)
{
	date = myDate;
	city = myCity;
}


string ItemType::GetData()
{
	return city;
}

string ItemType::GetData(int& myDate)
{
	myDate = date;
	return city;
}

void ItemType::SetData(int myDate, string myCity)
{
	date = myDate;
	city = myCity;
}

void ItemType::PrintInfo()
{
	cout << "On: " << date << ", To: " << city;
	cout << endl;
}