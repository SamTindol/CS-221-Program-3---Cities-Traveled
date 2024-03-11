#include "CityList.h"
#include <iostream>
using namespace std;

// Default constructor
CityList::CityList()
{
	maxItems = 10;
	dynamicArray = new ItemType[10];
}

// Copy Cinstructor
CityList::CityList(CityList& data)
{
	length = data.length;
	maxItems = data.maxItems;
	dynamicArray = new ItemType[data.maxItems];
	*dynamicArray = data;

	for (int index = 0; index < length; index++)
	{
		dynamicArray[index] = data.dynamicArray[index];
	}
}

// Non-default constructor
CityList::CityList(int myMaxItems)
{
	maxItems = myMaxItems;
	dynamicArray = new ItemType[myMaxItems];
}

// destructor;
CityList::~CityList()
{
	if (dynamicArray != NULL)
	{
		delete[] dynamicArray;
	}
	dynamicArray = NULL;
}

// Put Item function
bool CityList::PutItem(ItemType myItem)
{
	ResetList();
	int date = 0;
	bool found = false;
	bool result = false;
	int index = length;

	GetItem(myItem, found);

	if (!IsFull() && !found)
	{
		while (dynamicArray[curPos].operator<(myItem) == true && curPos < length)
		{
			curPos++;
		}

		if (curPos != length)
		{
			while (index - 1 >= curPos)
			{
				dynamicArray[index] = dynamicArray[index - 1];
				index--;
			}
		}

		dynamicArray[curPos] = myItem;
		length++;
		result = true;
		cout << "Added: " << myItem.GetData(date) << ", " << date << endl;
	}

	return result;
}

// Get Item Function
ItemType CityList::GetItem(ItemType myItem, bool& found)
{
	return BinarySearch(myItem, 0, length, found);
}

// Delete Item Function
bool CityList::DeleteItem(ItemType myItem)
{
	ResetList();
	bool result = false;
	int index = 0;

	while (dynamicArray[curPos].operator==(myItem) == false && curPos < length)
	{
		curPos++;
	}

	if (dynamicArray[curPos].operator==(myItem) == true)
	{
		index = curPos;
		while (index < length - 1)
		{
			dynamicArray[index] = dynamicArray[index + 1];
			index++;
		}
		length--;
		result = true;
	}
	
	return result;
}

void CityList::ResetList()
{
	curPos = 0;
}

void CityList::MakeEmpty()
{
	if (dynamicArray)
	{
		delete[] dynamicArray;
	}
	dynamicArray = new ItemType[maxItems];
	length = 0;
	ResetList();
}

void CityList::PrintList()
{
	ResetList();
	while (curPos < length)
	{
		dynamicArray[curPos].PrintInfo();
		curPos++;
	}
}

ItemType CityList::GetNext()
{
	curPos += 1;
	ItemType *result = new ItemType();

	if (curPos <= length) 
	{
		*result = dynamicArray[curPos];
	}
	else
	{
		result = new ItemType();
	}
	return *result;
}

int CityList::GetLength()
{
	return length;
}

bool CityList::IsFull()
{
	return (length == maxItems);
}

ItemType CityList::BinarySearch(ItemType myItem, int left, int right, bool &found)
{
	int middle = left + (right - left) / 2;
	if (!dynamicArray[middle].operator==(myItem))
	{
		if (left > right)
		{
			found = false;
			return ItemType();
		}
		else if (myItem.operator>(dynamicArray[middle]))
		{
			return BinarySearch(myItem, middle + 1, right, found);
		}
		else if (myItem.operator<(dynamicArray[middle]))
		{
			return BinarySearch(myItem, left, middle - 1, found);
		}
	}
	found = true;
	return dynamicArray[middle];
}