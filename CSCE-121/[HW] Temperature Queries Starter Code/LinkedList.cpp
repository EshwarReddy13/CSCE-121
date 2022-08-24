#include <cstdlib>
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList():head(nullptr),tail(nullptr){}
	// Implement this function


LinkedList::~LinkedList() {
	// Implement this function
	Node *now = head;
	Node *later = nullptr;
	while(now != nullptr){
		later = now;
		now = now->next;
		delete(later);
	}
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& source): head(nullptr), tail(nullptr){
	// Implement this function
	if (source.head == nullptr){
		head = nullptr;
		tail = nullptr;
		return;
	}
	Node* temp = source.head;
	Node* node = nullptr;
	while(temp != nullptr){
		node = new Node();
		node->data = temp->data;
		node->next = nullptr;
		if (head == nullptr){
			head = node;
			tail = node;
		}else{
			tail->next = node;
			tail = node;
		}
		temp = temp->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	this->clear();

	if (source.head == nullptr){
		head = tail = nullptr;
		return *this;
	}
	Node* temp = source.head;
	Node* node = nullptr;
	while (temp != nullptr){
		node = new Node();
		node->data = temp->data;
		node->next = nullptr;
		if (head == nullptr){
			head = node;
			tail = node;
		}else{
			tail->next = node;
			tail = node;
		}
		temp = temp->next;
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	Node* node = new Node(location,year,month,temperature);
	bool a = false;
	if(head == nullptr){
		head = node;
		tail = head;
		head->next = nullptr;
		a = true;
	}
	if(head->next == nullptr&&a == false){
		if(node->data < head->data){
			node->next = head;
			head = node;
			a = true;	
		}
		else{
			head->next = node;
			node->next = nullptr; 
		}
	}
	if(a == false){
		if(node->data < head->data){
			node->next = head;
			head = node;
			a = true;
		}
		if(a == false){
			Node* now = head->next; 
			Node* later = head;

			while(now != nullptr){
				if(node->data < now->data){
					node->next = now;
					later->next = node;
					a = true;
					break;
				}
				now = now->next;
				later = later->next;
			}
		}
		if(a == false){
			node->next = nullptr;
			tail->next = node;
			this->tail = node;
		}
	}
	// if(head==nullptr){
	// 	head = node;
	// 	tail = node;
	// 	head->next=nullptr;
	// }else{
	// 	if(node > tail){
	// 		node->next = nullptr;
	// 		tail->next = node;
	// 		tail = node;
	// 	}else if(head > node){
	// 		node->next = head;
	// 		head = node;
	// 	}else{
	// 		Node* curr = head;
	// 		Node* after = head->next;
	// 		while(true){
	// 			if(node>curr && node<after){
	// 				node->next = after;
	// 				curr->next = node;
	// 				break;
	// 			}
	// 			curr = curr->next;
	// 			after = after->next;
	// 		}
	// 	}
	// }
}

void LinkedList::clear() {
	// Implement this function
	while(head!=nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	if(head == nullptr){
		return nullptr;
	}else{
		return this->head;
	}
}
string remove(string a){
	while (a[a.size() - 1] == '0' || a[a.size() - 1] == '.'){
		a.resize(a.size() - 1);
	}
	return a;
}
string LinkedList::print() const {
	string outputString;
	// Implement this function
	ostringstream cout;
	Node* node = head;
	while (node != nullptr){
		cout << node->data.id << " " << node->data.year << " " << node->data.month << " " << node->data.temperature << endl;
		node = node->next;
	}
	outputString = cout.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
