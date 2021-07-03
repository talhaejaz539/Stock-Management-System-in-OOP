#include <stdio.h>			//To use remove() function, to delete file
#include <fstream>
#include "Stock.cpp"

int checkPosition(int id) {
	return id - 10000;
}

void selection(int selection) {
	fstream file("datafile.bin", ios::binary | ios::in | ios::out);
	Product product, *delProduct;
	int productID;
	char name[20];	int price, quantity;
	if(selection == 1) {
		system("CLS");
		cout << "\t\tAdd Product:-\n";
		cout << "\t\t\t\tEnter ProductID: ";
		cin >> productID;
		//if(productID == )
		cout << "\t\t\t\tEnter Product Name: ";
		cin >> name;
		cout << "\t\t\t\tEnter Product Price: ";
		cin >> price;
		cout << "\t\t\t\tEnter Product Quantity: ";
		cin >> quantity;
		product.set(productID,name,price,quantity);
		file.seekp(0, ios::end);
		file.write((char*)&product,sizeof(Product));
		system("CLS");
		cout << "\n\t\t\t\t\t\tProduct Added Successfully!\n";
	}
	if(selection == 2) {
		system("CLS");
		cout << "\t\tDelete Product:-\n";
		cout << "\t\t\t\tEnter ProductID: ";
		cin >> productID;
		//if(productID == )
		int n = checkPosition(productID);
		file.seekg(0, ios::end);
		int count = file.tellg() / sizeof(Product);
		if (n > count){	
			if (count == 0) cout << "Sorry no record in the file\n";
			else			cout << "Sorry, File has less than n records\n";
		}
		file.seekg(0);
		delProduct = new Product[count];	
		file.read((char*)delProduct, sizeof(Product) * count);		
		n--;
		file.close();
		remove("datafile.bin");//delete complete file

		ofstream out("datafile.bin",ios::binary);	//File Recreated
		out.write((char*) &delProduct[0], sizeof(Product)* n);	//store first n-1 records
		//Skip nth record and store next records
		out.write((char*) &delProduct[n+1], sizeof(Product)* (count-n-1));							
		out.close();	//close file
		delete []delProduct;	//Delete array
		file.open("datafile.bin", ios::binary | ios::in | ios::out);//Reopen file
		cout << "\n\t\t\t\t\t\tProduct Deleted Successfully!\n";
	}
	if(selection == 3) {
		system("CLS");
		cout << "\t\tModify Product Price:-\n";
		cout << "\t\t\t\tEnter ProductID: ";
		cin >> productID;
		//if(productID == )
		int n = checkPosition(productID);
		n--;
		file.seekp(sizeof (Product) * n);
		cout << "\t\t\t\tEnter Product Name: ";
		cin >> name;
		cout << "\t\t\t\tEnter Product Price: ";
		cin >> price;
		cout << "\t\t\t\tEnter Product Quantity: ";
		cin >> quantity;
		product.set(productID, name, price, quantity);
		file.write((char*)&product,sizeof(Product));
		system("CLS");
		cout << "\n\t\t\t\t\t\tProduct Updated Successfully!\n";
	}
	if (selection == 4) {
		system("CLS");
		cout << "\t\tSearch Product:-\n";
		cout << "\t\t\t\tEnter ProductID: ";
		cin >> productID;
		int n = checkPosition(productID);
		n--;
		cout << "\n\t";
		cout << setw(15) << left << "ProductID" << setw(14) << "Name";
		cout << setw(10) << "Price" << setw(5) << "Quantity\n";
		cout << "\t-----------------------------------------------\n";
		file.seekg(sizeof (Product) * n);
		file.read ( (char*) &product, sizeof(Product) );
		cout << product;
		cout << '\n';
	}
	if(selection == 5) {
		system("CLS");
		cout << "\t\tStock Available:-\n";
		Stock stock;
		file >> stock;
		cout << stock;
	}
	file.close();
}