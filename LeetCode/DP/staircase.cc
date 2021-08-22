#include <cstdint>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Staircase{
public:

	int steps;
	int memo[1000005];

	Staircase(int _steps){
		steps = _steps;
		memset(memo, 0, sizeof(steps)*steps);
	}
	// TC: O(3^n), SC: O(N)
	int countPathsRecursive(int steps){
		if (steps <= 0){
			return 0;
		}
		return countPathsRecursive(steps-1) + countPathsRecursive(steps-2) + countPathsRecursive(steps-3);
	}

	// TC: O(N), SC: O(N)
	int countPathsMemo(int steps){
		if (steps < 0){
			return 0;
		}
		else if (steps == 0){
			return 1;
		}
		if (!memo[steps]){
			memo[steps] = memo[steps -1] + memo[steps-2] + memo[steps-3];
		}
		return memo[steps];
	}

	// TC: O(N), SC: O(N)
	int countPathsDP(int steps){
		if (steps < 0){
			return 0;
		}
		else if (steps == 0){
			return 1;
		}
		memo[0] = 1;
		memo[1] = 1;
		memo[2] = 2;
		for (int i = 3; i <= steps; ++i){
			memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
		}
		return memo[steps];
	}

	// TC: O(N), SC: O(1)
	int countPaths(int steps){
		if (steps < 0){
			return 0;
		}
		else if (steps == 0){
			return 1;
		}

		memset(memo, 0, sizeof(steps)*3);
		memo[0] = 1;
		memo[1] = 1;
		memo[2] = 2;

		for (int i = 3; i <= steps; ++i){
			int count = memo[1] + memo[2] + memo[0];
			memo[0] = memo[1];
			memo[1] = memo[2];
			memo[2] = count;
		}
		return memo[2];
	}
};

int32_t main(void){
	int steps = 5;
	Staircase* stair = new Staircase(steps);
	cout << stair->countPathsMemo(steps);

}