#include <iostream>
#include <string>
#include "func.h"

using namespace std;
using namespace Func;

int main() {
	int stop = 1;
	int deleteChoise;
	int searchChoise;
	int editChoise;
	int lenghtMassiv = 0;
	Store* arr = {};
	while (stop) {
		cin.clear();
		cout << "1. Add new product. " << endl;
		cout << "2. Read file." << endl;
		cout << "3. Output." << endl;
		cout << "4. Delete product. " << endl;
		cout << "5. Search." << endl;
		cout << "6. Edit. " << endl;
		int choice;
		cin >> choice;
		switch (choice){
		case 1:
			int size;
			cout << "The number of products to be added: ";
			cin >> size;
			arr = new Store[size];
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			lenghtMassiv += size;
			Add(arr, size);
			delete[]arr;
			break;
		case 2:
			arr = Read();
			lenghtMassiv = getLenghtMassiv();
			break;
		case 3:
			for (int i = 0; i < lenghtMassiv; i++) {
				cout << i+1 << ". " << arr[i];
			}
			break;
		case 4:
			for (int i = 0; i < lenghtMassiv; i++) {
				cout << i + 1<<". "<< arr[i];
			}
			cout << "Select a product: ";
			cin >> deleteChoise;
			if (lenghtMassiv <= 0)
				break;
			arr = Delete(arr, lenghtMassiv, deleteChoise - 1);
			lenghtMassiv--;
			break;
		case 5:
			cout << "Search at: " << endl;
			cout << "1. Name Product" << " 2. Price" << " 3. Quantity " << endl;
			cin >> searchChoise;
			if (lenghtMassiv <= 0)
				break;
			Search(arr, lenghtMassiv, searchChoise);
			break;
		case 6:
			for (int i = 0; i < lenghtMassiv; i++) {
				cout << i + 1 << ". " << arr[i];
			}
			cout << "Edit at: ";
			cin >> editChoise;
			arr = Edit(arr, lenghtMassiv, editChoise - 1);
			break;
		default:
			break;
		}
	}
}