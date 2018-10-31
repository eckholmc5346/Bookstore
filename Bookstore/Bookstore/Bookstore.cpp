#include<iostream>
#include "Bookstore.h"
#include <cstdlib>
using namespace std;


int main() {
	MyLibrary list;
	bool repeat = true;
	while (repeat) {
		cout << "\nMENU" << endl;
		int select;
		cout << "\n1. Insert book\t2. Delete\n3. Print\t4. Search" <<
			"\n5. Quit\n\nWhat do you choose: ";
		cin >> select;
		cin.ignore();
		switch (select) {
		case 1: {
			//Insert new book
			system("cls");
			cout << "INSERTING NEW BOOK" << endl << endl;
			string pName;
			int pQuan;
			double pPrice;
			cout << "\n\nWhat is the book title: ";
			getline(cin, pName);
			cout << "\nWhat is the quantity: ";
			cin >> pQuan;
			cout << "\nWhat is the price: ";
			cin >> pPrice;

			node* temp = new node(pName, pQuan, pPrice);
			list.Insert(temp);
			break;
		}
		case 2: {
			//Delete book
			system("cls");
			cout << "DELETE" << endl << endl;
			string pName;
			int Pquan = 0;
			double Pprice = 0;
			cout << "What is the title: ";
			getline(cin, pName);
			node* temp = new node(pName, Pquan, Pprice);
			list.Delete(temp);
			break;
		}
		case 3: {
			system("cls");
			list.print();
			break;
		}
		case 4: {
			system("cls");
			cout << "SEACH" << endl << endl;
			string Pname;
			int Pquan = 0;
			double Pprice = 0;
			cout << "What is the title: ";
			getline(cin, Pname);
			node* temp = new node(Pname, Pquan, Pprice);
			list.search(temp);
			break;
		}
		case 5: {
			repeat = false;
			break;
		}
		default:
			cout << "\n\nWrong input. Try Again" << endl << endl;
		}
	}
	system("pause");
	return 0;
}