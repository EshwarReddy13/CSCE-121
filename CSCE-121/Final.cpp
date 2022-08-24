#include <iostream>
using namespace std;


//     Dyanmic 2D Arrays

// int main(){
//     int numRows = 2;
//     int numCols =4;
//     //Initialzing the array
//     int** twoDarray = new int*[numRows];
//     for(int i=0;i<numRows;i++){
//         twoDarray[i] = new int[numCols];
//     }

//     //Allocating the array
//     int k=0;
//     for(int i=0;i<numRows;i++){
//         for(int j=0;j<numCols;j++){
//             twoDarray[i][j] = k;
//             k++;
//         }
//     }

//     //Deleting the array
//     for(int i=0;i<numRows;i++){
//         delete[] twoDarray[i];
//         twoDarray[i] = nullptr;
//     }
//     delete [] twoDarray;
//     twoDarray = nullptr;

//     //Printing the array
//     for(int i=0;i<numRows;i++){
//         for(int j=0;j<numCols;j++){
//             cout << twoDarray[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }



//   Passing by Pointer and Reference

// void PrintByPtr(int* pVal){
//     cout << "Print by Pointer: " << endl;
//     if(pVal){
//         *pVal +=1;
//         cout << "Ptr val: " << pVal << endl;
//         cout << "Actual val: " << *pVal << endl;
//     }
// }
// void PrintByReference(int& val){
//     cout << "Print by Refernce: " << endl;
//     val+=1;
//     cout << "val: " << val << endl;
// }

// int main(){
//     int val = 10;
//     PrintByPtr(&val);
//     PrintByReference(val);
//     return 0;
// }



//  Classes

//A.cpp
// class DynamicArray{
// public:
//     //Default Constructor
//     DynamicArray(): pValues(nullptr),size(0),cap(0){};

//     //Constructor
//     DynamicArray(int cap): pValues(nullptr),size(0),cap(cap){
//         pValues = new int[cap];
//         for(int i=0;i<cap;i++){
//             pValues[i] = i+1;
//         }
//         size = cap;
//     };

//     //Copy Constructor
//     DynamicArray(const DynamicArray& other): pValues(nullptr),cap(other.cap),size(other.size){
//         pValues = new int[other.cap];
//         for(int i=0;i<other.size;i++){
//             pValues[i] = other.pValues[i];
//         }
//     };

//     //Copy Assignment
//     DynamicArray& operator=(const DynamicArray& rhs){
//         if(this == &rhs){
//             return *this;
//         }

//         //Clean it up
//         if(pValues){
//             delete[] pValues;
//             pValues = nullptr;
//         }
//         size =0;
//         cap =0;

//         pValues = new int[rhs.cap];
//         for(int i=0;i<rhs.size;i++){
//             pValues[i] = rhs.pValues[i];
//         }
//         size = rhs.size;
//         cap = rhs.cap;
//         return *this;
//     };

//     //Destructor
//     ~DynamicArray(){
//         delete[] pValues;
//         pValues = nullptr;
//     };

//     void Print() const{
//         for(int i=0;i<cap;i++){
//             cout << pValues[i] << " ";
//         }
//         cout << endl;
//     };

//     int& At(int idx){
//         return pValues[idx];
//     };

// private:
//     int* pValues = nullptr;
//     int size=0;
//     int cap=0;
// };

// int main(){
//     DynamicArray myDA(10);
//     DynamicArray mycopy(myDA);
//     DynamicArray third;
//     third = myDA;
//     third.At(1) = 200;
//     myDA.At(0) = 100;
//     const DynamicArray why(10);

//     why.Print();
//     myDA.Print();
//     mycopy.Print();
//     third.Print();
//     return 0;
// }



//  Linked List
// struct Node{
//     Node(int val):value(val),next(nullptr){}
//     int value;
//     Node* next=nullptr;
// };

// class LinkedList{
// public:

//     LinkedList():head(nullptr),tail(nullptr){};

//     ~LinkedList(){
//         Node* node = head;
//         while(node!=nullptr){
//             Node* temp = node->next;
//             delete node;
//             node = temp;
//         }
//     };

//     void insert(int val){
//         Node* node = new Node(val);

//         //Check if the list is empty
//         if(head==nullptr){
//             head = node;
//             tail = node;
//             return;
//         }

//         tail->next = node;
//         tail = node;
//     };

//     void Print(){
//         Node* node = head;
//         while(node!=nullptr){
//             cout << node->value << " ";
//             node = node->next;
//         }
//     };


// private:
//     Node* head=nullptr;
//     Node* tail=nullptr;
// };


// int main(){
//     LinkedList ll;
//     ll.insert(10);
//     ll.insert(20);
//     ll.insert(30);
//     ll.Print();
//     return 0;
// }

// ~Polygon(){
// 	delete vertices;
// 	vertices = nullptr;
// 	numVertices =0;
// }

// Polygon(const Polygon& poly){
// 	vertices->x = poly.x;
// 	vertices->y = poly.y;
// 	numVertices = poly.numVertices;
// }

// Polygon& operator=(const Polygon& poly){
// 	if(this == &poly){
// 		return *this;
// 	}

// 	if(vertices){
// 		delete vertices;
// 		vertices = nullptr;
// 		numVertices=0;
// 	}

// 	vertices->x = poly.x;
// 	vertices->y = poly.y;
// 	numVertices = poly.numVertices;
// 	return *this;
// }