//HW7
//Due: Monday, Nov. 23 at 11:59pm 
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>



using namespace std;

class my_hash1 {
	//hash ( sum(matrix element->string->ASCII)   );
	//Will explain in class
};

class my_equal_to1 {

	//equal num_rows && equal num_cols && equal sum(matrix element->string->ASCII);
	//Will explain in class

};



class myCompare1 {

	//compare sum(all ints)


};

class my_hash2 {

	//hash( sum ( int->string->ASCII)  )
	//will explain in class.
};

class my_equal_to2 {
	//equal hash(sum(int->string->ASCII))

};

//Also implement all needed overloaded operator<<






int main() {
	int n;
	cin >> n;
	vector<vector<vector<int>>> M(n);
	//n matrices of r row and c columns.
	//where r and c are both random numbers in 10-25
	//all matrix elements are random numbers in 0-99.
	//Will explain in class




	unordered_set<vector<vector<int>>, my_hash1, my_equal_to1> HT1;
	for (int i = 0; i < n; i++) {
		HT1.insert(M[i]);
	}
	cout << HT1 << endl;

	auto it = HT1.find(M[n - 1]);
	if (it != HT1.end()) {
		cout << *it << endl;
	}


	unordered_set<set<
		pair<list<int*>*, vector<int*>>, myCompare1>,
		my_hash2, my_equal_to2> HT2;

	set<pair<list<int*>*, vector<int*>>, myCompare1>
		s1{

			{ new list<int*>{new int{10}, new int{20}, new int{30} }   , {new int{20}, new int{40}}   },
			{ new list<int*>{new int{40}, new int{20}, new int{30} }   , {new int{20}, new int{40}, new int{100}}   }
	},
		s2{
			{ new list<int*>{new int{10}, new int{20}, new int{30} }   , {new int{20}, new int{40}} },
			{ new list<int*>{new int{40}, new int{20}, new int{30} }   , {new int{20}, new int{40}, new int{200}}   }
	};
	HT2.insert(s1);
	HT2.insert(s2);

	cout << HT2 << endl;
	cout << endl;
	auto it2 = HT2.find(s1);
	if (it2 != HT2.end())  cout << *it2 << endl;
	return 0;
}