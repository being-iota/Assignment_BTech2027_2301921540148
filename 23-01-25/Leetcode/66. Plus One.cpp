// approach 1 : Traverse from the End (Iterative)
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--) {
        digits[i]++;
        if (digits[i] < 10) {
            return digits; 
        }
        digits[i] = 0; 
    }
    // If carry exists, prepend 1
    digits.insert(digits.begin(), 1);
    return digits;
}

// approach 2 :  Using Reverse and Carry
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    reverse(digits.begin(), digits.end());
    int carry = 1; 
    for (int i = 0; i < digits.size(); i++) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
    }
    if (carry) {
        digits.push_back(1);
    }
    reverse(digits.begin(), digits.end());
    return digits;
}


// approach 3 : Using Recursion
#include <vector>
using namespace std;

vector<int> plusOneHelper(vector<int>& digits, int index) {
    if (index < 0) {
        digits.insert(digits.begin(), 1);
        return digits;
    }
    digits[index]++;
    if (digits[index] < 10) {
        return digits;
    }
    digits[index] = 0;
    return plusOneHelper(digits, index - 1);
}

vector<int> plusOne(vector<int>& digits) {
    return plusOneHelper(digits, digits.size() - 1);
}
