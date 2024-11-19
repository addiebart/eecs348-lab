#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> // for pow()

using namespace std;

int charToInt(const char& c) {
    switch (c) { // return doubles as break
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}

double extractNumeric(const string& str) {
    double out;
    int radixIndex = -1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            radixIndex = i;
            break;
        }
    }
    int wholepart = 0;
    double fractionalpart = 0;
    // ".002" will be the same as 0.002. "22." will be the same as 22.0.
    if (radixIndex == -1) { // no fractional part
        radixIndex = str.length();
    } else { // fractional part exists
        //find the fractional part
        for (int i = radixIndex + 1; i < str.length(); i++) {
            int exponent = i - radixIndex;
            int charint = charToInt(str[i]);
            if (charint < 0) {
                return -999999.99;
            }
            fractionalpart += (charint * (pow(0.1, exponent)));
        }
    }
    {
        //find the non fractional part
        for (int i = radixIndex - 1; i >= 0; i--) {
            int exponent = radixIndex - i - 1;
            int charint = charToInt(str[i]);
            if (charint < 0) {
                return -999999.99;
            }
            wholepart += (charint * (pow(10, exponent)));
        }
    }
    out = wholepart + fractionalpart;
    return out;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}