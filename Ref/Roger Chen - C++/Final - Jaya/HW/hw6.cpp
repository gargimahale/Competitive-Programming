//HW6. Due: Monday, Nov. 9, at 11:59PM
//You are required to use smart pointers in HW6. Raw pointers are not allowed.
//Sparse Matrix -- only non-zero elements are created as nodes.  See the diagram.
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class triple {
public:
	int value;
	int row;
	int col;
};

class node {
public:
	int value;
	int r_position;
	int c_position;
	shared_ptr<node> r_next;
	shared_ptr<node> c_next;
	node() { value = -9999; r_position = c_position = -1; }
	node(int v, int r, int c) { value = v; r_position = r; c_position = c; }

};
class matrix {
public:
	int num_rows;
	int num_cols;
	vector<shared_ptr<node>> r_vec;
	vector<shared_ptr<node>> c_vec;
	
	matrix() {} //default constructor
	matrix(int r, int c);
	//Constructor: to create a matrix of r rows, c cols
	
	
	//**********************//
	//You need to implement all the following member function plus overloaded operator<< for "cout << M <<endl; where M is a matrix object.
	void add_node(int v, int r, int c);
	//Create a new node with value v at row r and col c.
	//If there already exist an element at this position, then just update the node
	//value at this position to v, and do not create a new node.

	matrix(int r, int c, int n, int k);
	//Constructor: To create a matrix of r rows, c cols, n nodes, with values randomly in -(k-1) ... (k-1);
	
	matrix operator+(const matrix& M);//matrix addition
	matrix operator*(const matrix& M); //matrix multiplication

	matrix(const initializer_list < triple>& I);//initializer_list
	//First triple is (-1, num_rows, num_cols), where -1 will be ignored, and all other triples are nodes (value, r_position, c_position).

	matrix(const matrix& M);//copy constructor
	void operator=(const matrix& M);//copy assignment
	~matrix();//destructor
	//You should do as few operations as possible to best benefit from smart pointers.

	matrix(matrix&& M);//move constructor
	void operator=(matrix&& M);//move assignment
};


int main() {
	matrix M1(7, 5, 11, 8), M2(7, 5, 10, 8), M3(7, 5), M4(5, 6, 13, 9), M5(7, 6);
	cout << M1 << endl<<endl;
	cout << M2 << endl << endl;
	M3 = M1 + M2;
	cout << M3 << endl<<endl;
	cout << M4 << endl<<endl;
	M5 = M1 * M4;
	cout << M5 << endl<<endl;
	matrix  M6{ {-1,6, 5},{ 300, 4 ,3} , { 200, 4, 2 }, {100, 3, 2},  };
	//M6's num_rows = 6, num_cols = 5, and there are three non-zero nodes in M6.
	cout << M6 << endl<<endl;
	matrix M7{ M6 };
	cout << M7 << endl<<endl;
	matrix M8;
	M8 = M7;
	cout << M8 << endl;
	return 0;
}



/*
//The following is a sample screenshot


7 0 0  -4 0 2
4 1 4
2 3 3  3 3 4
5 4 1
-5 5 1
4 6 0  -6 6 1  4 6 2


-5 0 0  7 0 1  7 0 2  5 0 3
1 1 2
-5 2 3
2 3 1
-6 4 0
-1 5 3


operator+
Move Constructor
Destructor
Move Assignment
Destructor

2 0 0  7 0 1  3 0 2  5 0 3
1 1 2  4 1 4
-5 2 3
2 3 1  2 3 3  3 3 4
-6 4 0  5 4 1
-5 5 1  -1 5 3
4 6 0  -6 6 1  4 6 2


-3 0 4
8 1 3  7 1 4
-6 2 3  -7 2 4
7 3 3  -2 3 4  -8 3 5
4 4 2  1 4 4

operator*
Move Constructor
Destructor
Move Assignment
Destructor

24 0 3  7 0 4
16 1 2  4 1 4
12 3 2  14 3 3  -1 3 4  -16 3 5
40 4 3  35 4 4
-40 5 3  -35 5 4
-72 6 3  -82 6 4

initializer_list

100 3 2
200 4 2  300 4 3

Copy Constructor

100 3 2
200 4 2  300 4 3

Copy Assignment

100 3 2
200 4 2  300 4 3
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor

*/
