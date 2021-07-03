#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

class Product {
	int productID;
	char name[20];
	int price;
	int quantity;
public:
	Product() {
	}
	void set(int productID, const char name[], int price, int quantity) {
		this->productID = productID;
		strcpy(this->name,name);
		this->price = price;
		this->quantity = quantity;
	}
	friend istream& operator >> (istream&, Product&);		// Reading of Product
	friend ostream& operator << (ostream&, const Product&);	// Writing of Product
};
istream& operator >> (istream& in, Product& p) {
	in >> p.productID;				// Reading Product ID
	in.read(p.name, 16);			// Reading Product Name
	in >> p.price >> p.quantity;	// Reading Product Price and Quantity
	return in;
}
ostream& operator << (ostream& out, const Product& p) {
	out << '\t';
	out << setw(15) << left << p.productID;
	out << setw(15) << p.name;
	out << setw(12) << p.price;
	out << setw(10) << p.quantity;
	out << '\n';
	return out;
}