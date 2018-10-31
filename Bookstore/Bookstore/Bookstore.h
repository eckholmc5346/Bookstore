#ifndef BOOKSTORE_INCLUDED
#define BOOKSTORE_INCLUDED
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct node {
public:
	node(string name, int quantity, double price) {
		this->name = name;
		this->quantity = quantity;
		this->price = price;
		next = nullptr;
	}
	string name;
	int quantity;
	double price;
	node* next;
};

class MyLibrary {
public:
	MyLibrary() {
		counter = 0;
		head = nullptr;
		tail = nullptr;
	}
	int Count() {
		return counter;
	}
	bool isEmpty() {
		//This checks if the list is empty
		return counter == 0;
	}

	string getName(node* a) {
		return a->name;
	}
	bool inList(node* obj) {
		node* previous = head;
		node* current = head;
		while (current->next != nullptr) {
			previous = current;
			current = current->next;

			if (current->name == obj->name) {
				return true;
				break;
			}
			else {
				return false;
			}
		}
		return false;

	}


	//Insert function
	void Insert(node* obj) {
		if (isEmpty()) {
			//if empty, putting node object in list
			head = obj;
			tail = obj;
		}
		//if obj is smaller than smallest node in list
		else if (obj->name <= head->name) {
			obj->next = head;
			head = obj;
		}
		//if obj is largest node in list
		else if (obj->name >= tail->name) {
			tail->next = obj;
			tail = obj;
		}
		else {
			//runs if not in list yet
			node* current = head;
			node* previous = head;

			while (current->next != nullptr) {
				previous = current;
				current = current->next;
				if (current->name > obj->name) {
					head->next = current;
					previous->next = obj;
					break;
				}
			}
		}
		counter++;
	}
	void Delete(node* obj) {

		if (isEmpty()) { cout << "\nList is empty. Nothing can be deleted" << endl; }
		//Check if it's not in the list
		else if (obj->name < head->name || obj->name > tail->name) {
			cout << "Object is not in the list" << endl;
		}
		//Check if node is first
		else if (obj->name == head->name) {
			node* temp = head; //Assigning node to be deleted
			head = head->next; //Setting #2 to #1
			delete temp;
			cout << "\n\nBook has been deleted" << endl;
			counter--;
		}

		//Check if node is the last position
		else if (obj->name == tail->name) {
			node* previous = head;
			node* current = head;
			//Moving the list to the right one
			while (current->next != nullptr) {
				previous = current;
				current = current->next;
			}
			tail = previous;
			tail->next = nullptr; //Making sure nothing is coming after the tail
			delete current;
			counter--;
		}
		//Check if the node is in the list
		else {
			node* previous = head;
			node* current = head;
			while (current->next != nullptr) {
				previous = current;
				current = current->next;

				if (current->name == obj->name) {
					previous->next = previous->next->next;
					delete current;
					break;
				}
			}
			counter--;
		}
	}

	void print() {
		node* current = head;
		cout << setw(20) << left << "Title" << setw(20) << left << "Quantity" << setw(20) << left << "Price" << endl << endl;
		while (current != nullptr) {
			cout << setw(20) << left << current->name << setw(20)
				<< left << current->quantity << setw(20) << left << current->price << endl;
			current = current->next;
		}
		cout << endl;
	}

	//Search for node
	void search(node* obj) {
		node* current = head;
		bool found = false;
		while (current != nullptr) {
			if (obj->name == current->name) {
				cout << setw(20) << left << "Title" << setw(20) <<
					left << "Quantity" << setw(20) << left << "Price" << endl;
				cout << setw(20) << left << current->name << setw(20) << left <<
					current->quantity << setw(20) << left << current->price << endl;
			}
			current = current->next;
		}
	}



private:
	int counter = 0; //Number of elements in the list
	node* head; //first node
	node* tail; //last node
};

#endif#pragma once
