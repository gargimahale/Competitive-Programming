#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s, int start, int end){
        while(start <= end){
            if (s[start] != s[end]){
                return false;
            }
            ++start, --end;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        const int n = s.size();
        if (n <= 1){
            return true;
        }
        
        int start = 0, end = n-1;
        while(start <= end){
            if (s[start] != s[end]){
                return isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1);
            }
            ++start, --end;
        }
        
        return true;
    }
};