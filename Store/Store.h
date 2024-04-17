#pragma once
#include <string>
class Store {
private:
	std::string _nameProduct;
	int _price;
	int _quantity;
public:
	std::string getNameProduct();
	int getPrice();
	int getQuantity();
	void setNameProduct(std::string name);
	void setPrice(int price);
	void setQuantity(int quantity);
	friend std::ostream& operator<<(std::ostream& out, const Store& store);
	friend std::istream& operator>>(std::istream& in, Store& store);
};