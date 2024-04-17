#include "Store.h"
#include <string>
#include <iostream>
using namespace std;
string Store::getNameProduct() {
	return _nameProduct;
}
int Store::getPrice() {
	return _price;
}
int Store::getQuantity() {
	return _quantity;
}
void Store::setNameProduct(string name) {
	if(_nameProduct.compare(name))
		_nameProduct = name;

}
void Store::setPrice(int price) {
	if(_price != price)
		_price = price;

}
void Store::setQuantity(int quantity) {
	if (_quantity = quantity)
		_quantity = quantity;
}
ostream& operator<<(ostream& out, const Store& store) {
	out << "Name Product: " << store._nameProduct << "; Price: " << store._price << "; Quantity: " << store._quantity << "\n" << endl;
	return out;
}
istream& operator>>(istream& in, Store& store) {
	cout << "Name Product: ";
	in >> store._nameProduct ;
	cout << "Price: ";
	in >> store._price;
	cout << "Quatity: ";
	in >> store._quantity;
	return in;
}