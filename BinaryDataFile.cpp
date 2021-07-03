#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

class Product {
	int productID;
	char name[20];
	int price;
	int quantity;
public:
	Product() { }
	Product(int productID,const char name[],int price, int quantity) {
		set(productID,name,price,quantity);
	}
	void set(int productID,const char name[],int price, int quantity) {
		this->productID = productID;
		strcpy(this->name,name);
		this->price = price;
		this->quantity = quantity;
	}
	friend ostream& operator << (ostream&, const Product&);
};
ostream& operator << (ostream& out, const Product& p) {
	out << setw(15) << left << p.productID;
	out << setw(25) << p.name;
	out << setw(5) << p.price;
	out << setw(5) << p.quantity;
	out << '\n';
	return out;
}

int main() {
	#define COUNT 75
	Product p[COUNT];
	int productID;
	char name[20];
	int price;
	int quantity;
		
	ifstream in("txtfile.txt");
	for(int i=0;i<COUNT;i++) {
		in >> productID >> name >> price >> quantity;
		p[i].set(productID,name,price,quantity);
	}
		
	ofstream out("datafile.bin",ios::binary);
	out.write((char*)p,sizeof(Product)*COUNT);
	out.close();
	cout << "File Written Successfully!";
	return 0;
}
