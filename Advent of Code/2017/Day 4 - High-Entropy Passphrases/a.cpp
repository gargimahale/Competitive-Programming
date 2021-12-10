#include <bits/stdc++.h>
using namespace std;

namespace {

constexpr bool kPart1 = true;  // Use true for part 1, false for part 2.

// Returns true if |passphrase| is valid.  In part 1, a valid passphrase
// contains no duplicate words.  In part 2, it contains no words that are
// anagrams of each other.
bool PassphraseValid(const string& passphrase) {
  // Convert the passphrase to a set of words, checking each against previous
  // words in the passphrase.
  istringstream stringstream(passphrase);
  unordered_set<string> words;
  const auto ProcessWord = [](string word) {
    if (!kPart1) {
      // Map all anagrams to the same word by sorting the characters.
      sort(word.begin(), word.end());
    }
    return word;
  };
  for (istream_iterator<string> i(stringstream), end; i != end; ++i) {
    // If the next word was already seen, mark the passphrase invalid.
    if (!words.insert(ProcessWord(*i)).second)
      return false;
  }
  return true;
}

}  // namespace

int main(void) {
  ifstream myFile("input.txt");
  string passphrase;
  int valid_passphrases = 0;
  while (getline(myFile, passphrase)) {
    if (PassphraseValid(passphrase))
      ++valid_passphrases;
  }

  cout << "Valid passphrases: " << valid_passphrases << "\n";
}
