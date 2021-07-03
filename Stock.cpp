#include "Product.cpp"

class Stock {
	int count;
	Product* product;				// Weak Aggregation
public:
	Stock() {
		count = 0;
	}
	friend istream& operator >> (istream&, Stock&);				// Reading of Stock
	friend ostream& operator << (ostream&, const Stock&);		// Writing of Stock
};
istream& operator >> (istream& in, Stock& s) {
	in.seekg(0, ios::end);										// File Pointer at the EOF
	s.count = in.tellg() / sizeof(Product);						// Taking total count of Products
	in.seekg(0);												// File Pointer at the Start of File
	s.product = new Product[s.count];							// Creating Product Array of count
	in.read((char*)s.product, sizeof(Product) * s.count);		// Reading total Products
	return in;
}
ostream& operator << (ostream& out, const Stock& s) {
	out << '\t';
	out << setw(15) << left << "ProductID" << setw(14) << "Name";
	out << setw(10) << "Price" << setw(5) << "Quantity\n";
	out << "\t-----------------------------------------------\n";
	for (int i = 0; i < s.count; i++)
		out << s.product[i];
	out << "\t-----------------------------------------------\n";
	return out;
}