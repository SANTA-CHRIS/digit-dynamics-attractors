#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Square each digit and concatenate
string squareDigits(const string &num) {
    string result = "";
    for (char c : num) {
        int d = c - '0';
        int sq = d * d;
        result += to_string(sq);
    }
    return result;
}

// Sum digits in groups of 3
string sumGroupsOf3(const string &num) {
    string result = "";
    for (size_t i = 0; i < num.size(); i += 3) {
        int sum = 0;
        for (size_t j = i; j < i + 3 && j < num.size(); ++j) {
            sum += num[j] - '0';
        }
        result += to_string(sum);
    }
    return result;
}

int main() {
    string number;
    cout << "Enter the starting number: ";
    cin >> number;

    unordered_set<string> seen; // Track all numbers to detect loops
    int step = 0;

    while (seen.find(number) == seen.end()) {
        seen.insert(number);
        cout << "Step " << ++step << " (current number): " << number << endl;

        // Step 1: Square digits
        number = squareDigits(number);
        cout << " -> After squaring digits: " << number << endl;

        // Step 2: Sum digits in groups of 3 while divisible by 3
        while (number.size() % 3 == 0 && number.size() > 0) {
            string summed = sumGroupsOf3(number);
            if (summed == number) break; // Stop if summing does not change number
            number = summed;
            cout << " -> After summing groups of 3: " << number << endl;
        }
    }

    cout << "🔥 Brutal stable number reached: " << number << " 🔥" << endl;

    return 0;
}

