#include <bits/stdc++.h>
#include <openssl/md5.h> // add -lcrypto at the end when compiling
using namespace std;

void P1(const string& input);
void P2(const string& input);
string md5string(const string& in);

int main(void) {
    // P1("abcdef"); // p1: 609043
    // P1("pqrstuv"); // p1: 1048970

    // ifstream infile("input.txt");
    // string input;
    // infile >> input;

    P1("iwrupvqb");
    // P2(input);
}

void P1(const string& input) {

    uint32_t result = 0;

    for (uint32_t i = 1; ; i++) {
        auto md5 = md5string(input + to_string(i));
        if (md5.compare(0, 5, "00000") == 0) {
            result = i;
            break;
        }
    }

    cout << "Number: " << result << endl;
}

void P2(const string& input) {

    uint32_t result = 0;

    for (uint32_t i = 1; ; i++) {
        auto md5 = md5string(input + to_string(i));
        if (md5.compare(0, 6, "000000") == 0) {
            result = i;
            break;
        }
    }

    cout << "Number: " << result << endl;
}

string md5string(const string& in) {

    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)in.data(), in.length(), result);

    ostringstream ss;
    ss << hex << setfill('0');
    for (auto c : result) {
        ss << setw(2) << (int32_t)c;
    }

    return ss.str();
}