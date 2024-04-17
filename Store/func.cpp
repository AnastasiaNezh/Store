#include "Func.h"
#include <fstream>
#include <iostream>
using namespace std;

Store* Func::Read() {
	int size;
	ifstream file("Store.txt");
	if (!file.is_open())
		return nullptr;
	file >> size;
	Store* arr = new Store[size];
	for (int i = 0; i < size; i++) {
		string nameProduct;
		int price;
		int quantity;
		file >> nameProduct >> price >> quantity;
		arr[i].setNameProduct(nameProduct);
		arr[i].setPrice(price);
		arr[i].setQuantity(quantity);
	}
	file.close();
	return arr;
}

void Func::Save(Store* arr, int size) {
	ofstream file("Store.txt");
	if (!file.is_open())
		return;
	file << size << endl;
	for (int i = 0; i < size; i++) {
		file << arr[i].getNameProduct() <<" "<< arr[i].getPrice()<<" "<< arr[i].getQuantity() << endl;
	}
	file.close();
}

void Func::Add(Store* arr, int size) {
	int sizeOld;
	ifstream file("Store.txt");
	if (!file.is_open())
		return;
	file >> sizeOld;
	if (sizeOld <= 0) {
		sizeOld = 0;
	}
	file.close();
	Store* arrOld = Read();
	Store* arrNew = new Store[size + sizeOld];
	for (int i = 0; i < size + sizeOld; i++) {
		if (i >= sizeOld) {
			arrNew[i] = arr[i-sizeOld];
			continue;
		}
		arrNew[i] = arrOld[i];
	}
	Save(arrNew,size + sizeOld);
	delete[]arrOld;
}

Store* Func::Delete(Store* arr, int size ,int answer) {
	Store* arrNew = new Store[size - 1];
	for (int i = 0; i < size - 1; i++) {
		if (i >= answer) {
			arrNew[i] = arr[i + 1];
			continue;
		}
		arrNew[i] = arr[i];
	}
	Save(arrNew, size - 1);
	return arrNew;
}

void Func::Search(Store* arr, int size, int answer) {
	string name;
	int price;
	int quantity;
	if (answer == 1) {
		cout << "Name product: ";
		cin >> name;
		for (int i = 0; i < size; i++) {
			if (!(name.compare(arr[i].getNameProduct()))){
				cout << arr[i];
			}
		}
	}
	else if (answer == 2) {
		cout << "Price: ";
		cin >> price;
		for (int i = 0; i < size; i++) {
			if (arr[i].getPrice() == price) {
				cout << arr[i];
			}
		}
	}
	else if (answer == 3) {
		cout << "Quantity: ";
		cin >> quantity;
		for (int i = 0; i < size; i++) {
			if (arr[i].getQuantity() == quantity) {
				cout << arr[i];
			}
		}
	}
}

Store* Func::Edit(Store* arr, int size, int answer) {
	int answerEdit;
	cout << arr[answer];
	cout << "What to change: 1) Name Product 2) Price 3) Quantity : ";
	cin >> answerEdit;
	if (answerEdit == 1) {
		string name;
		cout << "Name Product: ";
		cin >> name;
		arr[answer].setNameProduct(name);
	}
	else if (answerEdit == 2) {
		int price;
		cout << "Price: ";
		cin >> price;
		arr[answer].setPrice(price);
	}
	else if (answerEdit == 3) {
		int quantity;
		cout << "Quantity: ";
		cin >> quantity;
		arr[answer].setQuantity(quantity);
	}
	Save(arr, size);
	return arr;
}
int Func::getLenghtMassiv() {
	int size;
	ifstream file("Store.txt");
	if (!file.is_open())
		return 0;
	file >> size;
	file.close();
	return size;
}