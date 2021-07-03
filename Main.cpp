#include "Functions.cpp"
#define QUIT 6

int main() {
	cout << "\n\n\t\t\t\"Toheed Departmental Store\"\n\n\n";
	string username, password;
	cout << "\tUsername: ";
	cin >> username;
	if(username != "talha123") {
		cout << "\t\t\t\aInvalid Username!";
		return 0;
	}
	cout << "\tPassword: ";
	cin >> password;
	if(password != "abcd789") {
		cout << "\t\t\t\aInvalid Password!";
		return 0;
	}
	system("CLS");
	
	//This will work first time without choice value.
	int choice;
	do {
		//Name
		cout << "\n\n\t\t\t\"Toheed Departmental Store\"\n\n\n";
		//Menu Functions
		cout << "\t1-Add New Product\n";
		cout << "\t2-Delete Existing Product\n";
		cout << "\t3-Modify Product Price\n";
		cout << "\t4-Search Product By ID\n";
		cout << "\t5-Show All Products\n";
		cout << "\t6-Exit\n";
		//User Input
		cout << "\n  Enter Your Choice: ";
		cin >> choice;
		cout << '\n';
		//Check on User Input
		if(choice != QUIT) 
			selection(choice);	//Written in Functions.cpp
	} while (choice != QUIT);	//User Choice Check
	//Program End
	system("CLS");
	cout << "\n\t\t\t\t\t\tThanks for Using!\n";
	return 0;
}