#pragma once
#include "ItemType.h"

class CityList : public ItemType
{
private: 
	int maxItems = 0;
	ItemType*dynamicArray = NULL;
	int length = 0;
	int curPos = 0;

	ItemType BinarySearch(ItemType myItem, int left, int right, bool &found);

public:
	CityList();
	CityList(CityList& data);
	CityList(int myMaxItems);
	~CityList();

	bool PutItem(ItemType myItem);
	ItemType GetItem(ItemType myItem, bool& found);
	bool DeleteItem(ItemType myItem);
	void ResetList();
	void MakeEmpty();
	void PrintList();
	ItemType GetNext();
	int GetLength();
	bool IsFull();
};

