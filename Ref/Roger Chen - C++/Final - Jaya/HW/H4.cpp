//HW4 due: Monday(10/12/2020).
#include <iostream>
#include <list>
#include <string>

using namespace std;
template <class T> class ThreeD {
public:
	T ht;
	T wid;
	T dep;
	ThreeD() :ht(0), wid(0), dep(0) {}
	ThreeD(T i, T j, T k) :ht(i), wid(j), dep(k) {}
	T getVol() const { return ht * wid * dep; }
	bool operator==(const ThreeD<T>& t) const { return getVol() == t.getVol(); }
};

template <class T> class node {
public:
	T value;
	node<T>* next;
	node<T>* previous;
	node<T>() { next = nullptr; previous = nullptr; }
	node<T>(T v) { value = v; next = nullptr; previous = nullptr; }
	bool operator==(const node<T>& t) const { return value == t.value; }
};

template <class T> class linked_list {
public:
	node<T>* head;
	node<T>* tail;
	linked_list() { head = tail = nullptr; }
	linked_list(const initializer_list<T>& V);
	void push_front(T t);//The implementation is given below.
	void push_back(T t);//The implementation is given below.
	bool operator==(const linked_list<T>& L) const;

	linked_list(const linked_list<T>& L); //copy constructor
	linked_list(linked_list<T>&& L); //move constructor
	~linked_list();//destructor
	void operator=(const linked_list<T>& L);//Lvalue operator= ; i.e., copy assignment
	void operator=(linked_list<T>&& L);//Rvalue operator= ; i.e., move assignment
	
};

template <class T> ostream& operator<<(ostream& str, const linked_list<T>& L) {
	str << "[";
	node<T>* p = L.head;
	while (p) {
		str << p->value << " ";
		p = p->next;
	}
	str << "]";
	return str;
}
template <class T> linked_list<T>::linked_list(const initializer_list<T>& V) : linked_list() {
	//Your code
	cout << "initializer_list LL" << endl;
}

template <class T> linked_list<T>::~linked_list() {  //destructor										
	//Your code
	cout << "Destructor LL" << endl;
}

template <class T> linked_list<T>::linked_list(const linked_list<T>& L) : linked_list() { //copy constructor																			  																		  //num_nodes = 0;
    //Your code
	cout << "Copy Constructor LL" << endl;
}
template <class T> linked_list<T>::linked_list(linked_list<T>&& L) {//move constructor
	//Your code
	cout << "Move Constructor LL" << endl;
}

template <class T> void linked_list<T>::operator=(const linked_list<T>& L) { //Lvalue operator=
	//Your code
	cout << "Copy Assignment LL" << endl;
}

template<class T> void linked_list<T>::operator=(linked_list<T>&& L) {//R-value operator=
	//Your code
	cout << "Move Assignment LL" << endl;

}


template <class T> void linked_list<T>::push_front(T t) {
	node<T>* p = new node<T>(t);
	if (head == nullptr) { head = tail = p; }
	else {
		p->next = head;
		head->previous = p;
		head = p;
	}
}

template <class T> void linked_list<T>::push_back(T t)
{
	node<T>* p = new node<T>(t);
	if (head == nullptr) { head = tail = p; }

	else {
		p->previous = tail;
		tail->next = p;
		tail = p;
	}
}

template <class T> bool linked_list<T>::operator==(const linked_list<T>& L) const {
	//Your code
	//Two linked lists are equal if they have same number of nodes, and each pair of corresponding nodes have equal values.
	return true;
}







template <class T> ostream& operator<<(ostream& str, const ThreeD<T>& t) {
	str << "(" << t.ht << ", " << t.wid << ", " << t.dep << ")";
	return str;
}



template <typename T> class Node { //Your T has to support either int or float
public:
	T * pValue; //pValue is a pointer to an object of type T
	Node<T> * row_next;//Points to the next node in the same row
	Node<T> * col_next;//Points to the nexe node in the same col
	Node() {}
	Node(T v) { pValue = new T (v); }
};

template <typename T> class Ring2D {
public:
	Node<T> * head;//Points to the node at first row and first column

	Ring2D() {};

	//Implement the following functions:
	Ring2D(const initializer_list< initializer_list<T>>& I); //nested initializer_list; will explain in class 
	/*
	For example, {{1, 2, 3, 4} , {5, 6, 7, 8},  {9, 10, 11, 12}}: 3 rows and 4 columns; first row: pointers to 1 2 3 4;
	second row: pointers to 5 6 7 8; third row: pointers to 9 10 11 12
	*/

	~Ring2D();//destructor; 
	Ring2D(const Ring2D<T>& R);//copy constructor

	void operator=(const Ring2D<T>& R);//Lvalue operator=; i.e., copy assignment

	Ring2D(Ring2D<T>&& R);//move constructor
	void operator=(Ring2D<T>&& R);//Rvalue operator=; i.e.,move assignment
	Ring2D<T> ThreeTimes();//Return a Ring2D with values being three times of the current Ring2D

	bool operator==(const Ring2D<T>& R) const;
};

template <class T> bool Ring2D<T>::operator==(const Ring2D<T>& R) const {
	//Your code
	//If you return in the middle of code, you also need to print the following message
	cout << "Operator== Ring2D" << endl;
	return true;
}



template <class T> void Ring2D<T>::operator=(Ring2D<T>&& R) {//;//Rvalue operator=; move assignment
	//Your code
	cout << "Move Assignment Ring2D" << endl;
}

template<class T> Ring2D<T>::Ring2D(Ring2D<T>&& R) {//;//move constructor
	//Your code
	cout << "Move Constructor Ring2D" << endl;
}

template <class T> Ring2D<T> Ring2D<T>::ThreeTimes() {//ThreeTimes;
	//Your code
	cout << "ThreeTimes Ring2D" << endl;
	return temp;
}



template <class T> Ring2D<T>::~Ring2D() {//;//destructor
	//Your code
	//If you return in the middle of your code, you also need to print the following message.
	cout << "Destructor Ring2D" << endl;
}


template <class T> void Ring2D<T>::operator=(const Ring2D<T>& R) {//;//Lvalue operator=; copy assignment
	//Your code
	//If you return in the middle of your code, you also need to print the following message.
	cout << "Copy Assignment Ring2D" << endl;
}


template<class T> Ring2D<T>::Ring2D(const Ring2D<T>& R) {//copy constructor
	//Your code
	//If you return in the middle of your code, you also need to print the following message.
	cout << "Copy Constructor Ring2D" << endl;
}

template <class T> Ring2D<T>::Ring2D(const initializer_list< initializer_list<T>>& I) {


//Your code
	cout << "initializer_list Ring2D" << endl;
}


template<class T> ostream& operator<<(ostream& str, const Ring2D<T>& R) {
	//Your code
	

}



int main() {
	

	Ring2D<int> R1{{1, 2, 3, 4},  {5, 6, 7, 8},  {9, 10, 11, 12} };//initializer_list
	cout << R1 << endl << endl;
	Ring2D<int> R2{ R1 };
	cout << R2 << endl;
	Ring2D<int> R3;
	R3 = R1;
	cout << R3 << endl;
	Ring2D<int> R4;
	R4 = R1.ThreeTimes();
	cout << R4 << endl;
	Ring2D<linked_list<ThreeD<int>>> R5{ {{{3,4,5},{7,1,4},{6,7,3}},{{8,4,2},{8,8,2}}},
		{{{9,5,4},{10,3,2},{7,9,1},{2,2,3}}, { {5,4,8 },{4,2,16  }, {7, 8, 4} } } };
	cout << R5 << endl;
	Ring2D<linked_list<ThreeD<int>>> R6{ {{{5,3,4,},{14,2,1},{6,7,3}},{{8,2,4},{8,4,4}}},
		{{{9,4,5},{10,3,2},{7,3,3},{2,3,2}}, { {4, 5,8 },{8,2,8  }, {2, 16, 7} } } };
	cout << R6 << endl;

	if (R5 == R6) cout << "EQUAL" << endl;
	else cout << "NOT EQUQL" << endl;

	Ring2D<linked_list<ThreeD<int>>>* p1 = new Ring2D<linked_list<ThreeD<int>>>
	{ {{{5,3,4,},{14,2,1},{6,7,3}},{{8,2,4},{8,4,4}}},
		{{{9,4,5},{10,3,2},{7,3,3},{2,3,2}}, { {4, 5,8 },{8,2,8  }, {2, 16, 7} } } };
	cout << *p1 << endl;
	delete p1;

	return 0;
}

	//Sample screenshot
	/*
initializer_list Ring2D
{ 1 2 3 4 }
{ 5 6 7 8 }
{ 9 10 11 12 }


Copy Constructor Ring2D
{ 1 2 3 4 }
{ 5 6 7 8 }
{ 9 10 11 12 }

Copy Assignment Ring2D
{ 1 2 3 4 }
{ 5 6 7 8 }
{ 9 10 11 12 }

Copy Constructor Ring2D
ThreeTimes Ring2D
Move Constructor Ring2D
Destructor Ring2D
Move Assignment Ring2D
Destructor Ring2D
{ 3 6 9 12 }
{ 15 18 21 24 }
{ 27 30 33 36 }

initializer_list LL
initializer_list LL
initializer_list LL
initializer_list LL
Copy Constructor LL
Copy Constructor LL
Copy Constructor LL
Copy Constructor LL
initializer_list Ring2D
Destructor LL
Destructor LL
Destructor LL
Destructor LL
{ [ (3, 4, 5) (7, 1, 4) (6, 7, 3)  ] [ (8, 4, 2) (8, 8, 2)  ] }
{ [ (9, 5, 4) (10, 3, 2) (7, 9, 1) (2, 2, 3)  ] [ (5, 4, 8) (4, 2, 16) (7, 8, 4)  ] }

initializer_list LL
initializer_list LL
initializer_list LL
initializer_list LL
Copy Constructor LL
Copy Constructor LL
Copy Constructor LL
Copy Constructor LL
initializer_list Ring2D
Destructor LL
Destructor LL
Destructor LL
Destructor LL
{ [ (5, 3, 4) (14, 2, 1) (6, 7, 3)  ] [ (8, 2, 4) (8, 4, 4)  ] }
{ [ (9, 4, 5) (10, 3, 2) (7, 3, 3) (2, 3, 2)  ] [ (4, 5, 8) (8, 2, 8) (2, 16, 7)  ] }

operator== LL
operator== LL
operator== LL
operator== LL
Operator== Ring2D
EQUAL
initializer_list LL
initializer_list LL
initializer_list LL
initializer_list LL
Copy Constructor LL
Copy Constructor LL
Copy Constructor LL
Copy Constructor LL
initializer_list Ring2D
Destructor LL
Destructor LL
Destructor LL
Destructor LL
{ [ (5, 3, 4) (14, 2, 1) (6, 7, 3)  ] [ (8, 2, 4) (8, 4, 4)  ] }
{ [ (9, 4, 5) (10, 3, 2) (7, 3, 3) (2, 3, 2)  ] [ (4, 5, 8) (8, 2, 8) (2, 16, 7)  ] }

Destructor LL
Destructor LL
Destructor LL
Destructor LL
Destructor Ring2D
Destructor LL
Destructor LL
Destructor LL
Destructor LL
Destructor Ring2D
Destructor LL
Destructor LL
Destructor LL
Destructor LL
Destructor Ring2D
Destructor Ring2D
Destructor Ring2D
Destructor Ring2D
Destructor Ring2D

C:\Users\Roger\source\repos\Project28\Debug\Project28.exe (process 9456) exited with code 0.
Press any key to close this window . . .

	*/

