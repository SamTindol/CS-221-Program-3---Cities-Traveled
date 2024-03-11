#pragma once
#include <string>
using namespace std;

class ItemType
{
private:
	int date;
	string city;

public:
	bool operator < (ItemType &item);
	bool operator > (ItemType &item);
	bool operator == (ItemType &item);
	ItemType();
	~ItemType();
	ItemType(int myDate, string myCity);


	string GetData();
	string GetData(int &myDate);
	void SetData(int myDate, string myCity);
	void PrintInfo();
};

