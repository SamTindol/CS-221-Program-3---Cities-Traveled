#include <iostream>
#include "ItemType.h"
#include "CityList.h"
using namespace std;
int main()
{
	cout << "Test Driver" << endl << endl;
	CityList myList(6);
	ItemType city1 = ItemType(20220409, "St. Louis");
	ItemType city2 = ItemType(20230726, "Tampa");
	ItemType city3 = ItemType(20181018, "Atlanta");
	ItemType city4 = ItemType(20191025, "Pigeon Forge");
	ItemType city5 = ItemType(20240518, "New York");
	ItemType city6 = ItemType(20230311, "Nashville");
	ItemType city7 = ItemType(20230720, "Orlando");
	
	cout << "Adding cities to the array" << endl << "***********************************************" << endl << endl;
	myList.PutItem(city1);
	myList.PutItem(city2);
	myList.PutItem(city3);
	myList.PutItem(city4);

	cout << "\nList:" << endl;
	myList.PrintList();

	cout << "\nAdding a city that already exists" << endl << "*******************************************" << endl << endl;
	myList.PutItem(city3);

	cout << "\nList:" << endl;
	myList.PrintList();

	cout << "\nDeleting Tampa" << endl << "*************************************************************" << endl << endl;
	myList.DeleteItem(city2);

	cout << "List:" << endl;
	myList.PrintList();


	cout << "\nAttempt to copy the list to a new list" << endl << "******************************************" << endl << endl;
	CityList newList = myList;

	//system("pause");

	cout << "\nTry to print the new list" << endl << "*******************************************" << endl << endl;
	newList.PrintList();

	cout << "\nDelete St Louis from original list and see if it is different from list to list" << endl;
	cout << "****************************************************" << endl << endl;
	myList.DeleteItem(city1);

	cout << "\nOrigial List" << endl;
	myList.PrintList();

	cout << "\nNew List:" << endl;
	newList.PrintList();

	cout << "\n\n\nMaking original list empty" << endl;
	//myList.~CityList();
	//system("pause");
	myList.MakeEmpty();

	cout << "Original List:" << endl;
	myList.PrintList();
	
	system("pause");
	return 0;
}
