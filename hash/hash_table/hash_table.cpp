#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <cstdio>
#include "chained_hash.h"

using namespace std;

int main()
{
	HashMap hash;
	int key, value;
	int choice;
	while (1)
	{
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key" << endl;
		cout << "3.Delete element at a key" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> value;
			cout << "Enter key at which element to be inserted: ";
			cin >>
				key;
			hash.ChainedHashInsert(key, value);
			break;
		case 2:
			cout << "Enter key of the element to be searched: ";
			cin >> key;
			cout << "Element at key " << key << " : ";
			if (hash.ChainedHashSearch(key) == -1)
			{
				cout << "No element found at key " << key << endl;
				continue;
			}
			break;
		case 3:
			cout << "Enter key of the element to be deleted: ";
			cin >> key;
			hash.ChainedHashDelete(key);
			break;
		case 4:
			exit(1);
		default:
			cout << "\nEnter correct option\n";
		}
	}
	return 0;
}