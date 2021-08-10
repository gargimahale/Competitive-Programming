//CIS554 HW4 Due: 11:59pm, 10/28 Wednesday
//When comparing two structures, you should compare the sums of all integers in the two structures
//Do not assign name to a lambda, i.e., implement in-place lambda.
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

int main() {

	set<map<list<int*>*, vector<int> *, myCompare1>, myCompare2> M1
	{
		{   {
				{ new list<int*>{new int{10}, new int{20}, new int{30} }   , new vector<int> {20, 40}   },
				{ new list<int*>{new int{40}, new int{20}, new int{30} }   , new vector<int> {20, 40,100}   }
			}
		},


		{	{
				{ new list<int*>{new int{10}, new int{20}, new int{30} }   , new vector<int> {20, 40}   },
				{ new list<int*>{new int{40}, new int{20}, new int{30} }   , new vector<int> {20, 40, 200}   }
			}
		}
	};
	//Implement the needed overloading operator<< to support the following printing.
	cout << M1 << endl;



	/*
	For the following, implement the functions used
	in sorting the list elements using regular function, functor, and lambda in the three cases.
	In addition, you need to implement the needed overloaded operator<< to supporting the printing.
	*/

	cout << endl;
	list<map < list<int*>*, vector<int*> *, myCompare1 >> L1{ {
				{
					new list<int*>{new int{10}, new int{20}, new int{30} } ,
					new vector<int *> {new int{20}, new int{400}}
				},

				{
					new list<int*>{new int{40}, new int{20}, new int{30} }   ,
					new vector<int *> {new int{20}, new int{40}, new int{100}}
				}
	} , {
				{
					new list<int*>{new int{10}, new int{20}, new int{30} } ,
					new vector<int *> {new int{20}, new int{40}}
				},

				{
					new list<int*>{new int{40}, new int{20}, new int{30} }   ,
					new vector<int *> {new int{20}, new int{40}, new int{200}}
				}
	} };
	cout << L1 << endl;
	L1.sort(f1);//???: use a regular function f1
	cout << L1 << endl;
	cout << endl;
	list<map < list<int*>*, vector<int*>*, myCompare1 >> L2{ {
				{
					new list<int*>{new int{10}, new int{20}, new int{30} } ,
					new vector<int*> {new int{20}, new int{400}}
				},

				{
					new list<int*>{new int{40}, new int{20}, new int{30} }   ,
					new vector<int*> {new int{20}, new int{40}, new int{100}}
				}
	} , {
				{
					new list<int*>{new int{10}, new int{20}, new int{30} } ,
					new vector<int*> {new int{20}, new int{40}}
				},

				{
					new list<int*>{new int{40}, new int{20}, new int{30} }   ,
					new vector<int*> {new int{20}, new int{40}, new int{200}}
				}
	} };

	cout << L2 << endl;
	L2.sort(f2);//use a functor f2
	cout << L2 << endl;
	cout << endl;

	list<map < list<int*>*, vector<int*>*, myCompare1 >> L3{ {
				{
					new list<int*>{new int{10}, new int{20}, new int{30} } ,
					new vector<int*> {new int{20}, new int{400}}
				},

				{
					new list<int*>{new int{40}, new int{20}, new int{30} }   ,
					new vector<int*> {new int{20}, new int{40}, new int{100}}
				}
	} , {
				{
					new list<int*>{new int{10}, new int{20}, new int{30} } ,
					new vector<int*> {new int{20}, new int{40}}
				},

				{
					new list<int*>{new int{40}, new int{20}, new int{30} }   ,
					new vector<int*> {new int{20}, new int{40}, new int{200}}
				}
	} };

	cout << L3 << endl;
	L3.sort(a lambda);//???: use a lambda 
	cout << L3 << endl;

	return 0;
}
//The following is a sample display
/*

{ < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 100 ] >  < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] >  }

( < ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] > < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] > )
( < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] > < ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] > )

( < ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] > < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] > )
( < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] > < ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] > )

( < ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] > < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] > )
( < ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] > < ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] > )

*/