// Advent of Code 2017 day 5 solution
// Peter Kasting, Dec. 4, 2017

#include <bits/stdc++.h>
using namespace std;

namespace {

constexpr bool kPart1 = false;  // Use true for part 1, false for part 2.

// Reads whitespace-delimited ints on cin and returns a vector containing
// them.
vector<int> ReadInput() {
  vector<int> input;
  transform(istream_iterator<string>(cin),
                 istream_iterator<string>(),
                 back_inserter(input),
                 [](const string& str) { return stoi(str); });
  return input;
}

// Counts the number of steps needed to exit |offsets|, starting from the first
// offset.  At each step, the Program Counter (or index) is incremented by the
// current offset, and the offset is modified.  In part 1, the offset is always
// incremented by one; in part 2, the offset is incremented by 1 if less than 3,
// or decremented by 1 otherwise.
size_t CountSteps(vector<int> offsets) {
  size_t steps = 0;
  // We could make |pc| a size_t and eliminate the "positive" check, but this
  // assumes that any jump off the beginning of the list is not so large that it
  // wraps around to a valid list index.  In practice any list that violated
  // that would have to take up an enormous amount of memory, but might as well
  // avoid the issue.
  for (int pc = 0; (pc >= 0) && (static_cast<size_t>(pc) < offsets.size());
       ++steps) {
    int& offset = offsets[pc];
    pc += offset;
    offset += (kPart1 || (offset < 3)) ? 1 : -1;
  }
  return steps;
}

}  // namespace

int main(void) {
cout << "Steps to exit: " << CountSteps(ReadInput()) << "\n";
  return 0;
}