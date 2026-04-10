// ============================================================
// Lab: Strings and String Operations with Function & Operator
//       Overloading in C++
// Course: Object-Oriented Programming for Engineers
// Level: 2nd Year Engineering
// Duration: 70 minutes
// ============================================================
// SINGLE FILE IMPLEMENTATION - No header files allowed
// ============================================================
// STUDENT VERSION - Implement all TODO sections
// ============================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

class MyString {
private:
    string data;

public:
    // ---- Constructors ----
    MyString();
    MyString(const string& str);
    MyString(const char* str);

    // ---- Getter ----
    string getData() const;

    // ---- Basic String Operations ----
    int length() const;
    char charAt(int index) const;
    MyString substring(int start, int len) const;

    // ---- String Manipulation ----
    MyString toUpperCase() const;
    MyString toLowerCase() const;
    MyString trim() const;
    MyString reverse() const;

    // ---- Search Operations ----
    int find(const MyString& target) const;
    int count(char ch) const;

    // ---- Function Overloading: append ----
    MyString append(const MyString& other) const;
    MyString append(const char* cstr) const;
    MyString append(char ch) const;
    MyString append(int number) const;

    // ---- Function Overloading: replace ----
    MyString replace(char oldCh, char newCh) const;
    MyString replace(const string& oldStr, const string& newStr) const;

    // ---- Operator Overloading ----
    MyString operator+(const MyString& other) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    char operator[](int index) const;
    MyString operator*(int times) const;

    // ---- Stream Overloading ----
    friend ostream& operator<<(ostream& os, const MyString& s);
    friend istream& operator>>(istream& is, MyString& s);
};

// ================================
// FUNCTION IMPLEMENTATIONS
// ================================

// ---- Constructors ----

MyString::MyString() {
    data = "";
}

MyString::MyString(const string& str) {
    data = str;
}

MyString::MyString(const char* str) {
    data = str;
}

// ---- Getter ----

string MyString::getData() const {
    return data;
}

// ---- Basic String Operations ----

int MyString::length() const {
    return data.length();
}

char MyString::charAt(int index) const {
    if (index < 0 || index >= data.length()) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

MyString MyString::substring(int start, int len) const {
    if (start < 0 || start >= data.length()) {
        throw out_of_range("Start index out of range");
    }
    return MyString(data.substr(start, len));
}

// ---- String Manipulation ----

MyString MyString::toUpperCase() const {
    string temp = data;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    return MyString(temp);
}

MyString MyString::toLowerCase() const {
    string temp = data;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return MyString(temp);
}

MyString MyString::trim() const {
    size_t start = data.find_first_not_of(" \t\n\r");
    size_t end = data.find_last_not_of(" \t\n\r");

    if (start == string::npos) return MyString("");

    return MyString(data.substr(start, end - start + 1));
}

MyString MyString::reverse() const {
    string temp = data;
    std::reverse(temp.begin(), temp.end());
    return MyString(temp);
}

// ---- Search Operations ----

int MyString::find(const MyString& target) const {
    size_t pos = data.find(target.data);
    return (pos == string::npos) ? -1 : pos;
}

int MyString::count(char ch) const {
    int cnt = 0;
    for (char c : data) {
        if (c == ch) cnt++;
    }
    return cnt;
}

// ---- append ----

MyString MyString::append(const MyString& other) const {
    return MyString(data + other.data);
}

MyString MyString::append(const char* cstr) const {
    return MyString(data + string(cstr));
}

MyString MyString::append(char ch) const {
    return MyString(data + ch);
}

MyString MyString::append(int number) const {
    return MyString(data + to_string(number));
}

// ---- replace ----

MyString MyString::replace(char oldCh, char newCh) const {
    string temp = data;
    for (char& c : temp) {
        if (c == oldCh) c = newCh;
    }
    return MyString(temp);
}

MyString MyString::replace(const string& oldStr, const string& newStr) const {
    string temp = data;
    size_t pos = 0;

    while ((pos = temp.find(oldStr, pos)) != string::npos) {
        temp.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }

    return MyString(temp);
}

// ---- Operator Overloading ----

MyString MyString::operator+(const MyString& other) const {
    return MyString(data + other.data);
}

bool MyString::operator==(const MyString& other) const {
    return data == other.data;
}

bool MyString::operator!=(const MyString& other) const {
    return data != other.data;
}

bool MyString::operator<(const MyString& other) const {
    return data < other.data;
}

bool MyString::operator>(const MyString& other) const {
    return data > other.data;
}

char MyString::operator[](int index) const {
    if (index < 0 || index >= data.length()) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

MyString MyString::operator*(int times) const {
    if (times <= 0) return MyString("");

    string result;
    for (int i = 0; i < times; i++) {
        result += data;
    }
    return MyString(result);
}

// ---- Stream Overloading ----

ostream& operator<<(ostream& os, const MyString& s) {
    os << s.data;
    return os;
}

istream& operator>>(istream& is, MyString& s) {
    is >> s.data;
    return is;
}

// ================================
// MAIN FUNCTION
// ================================

int main() {
    cout << "=== MyString Lab Demo ===" << endl;

    MyString s1("Hello World");
    MyString s2("hello world");
    MyString s3;
    MyString s4(string("C++ Programming"));

    cout << "\n--- Basic Operations ---" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s4: " << s4 << endl;
    cout << "Length of s1: " << s1.length() << endl;
    cout << "charAt(0): " << s1.charAt(0) << endl;
    cout << "substring(0,5): " << s1.substring(0, 5) << endl;

    cout << "\n--- String Manipulation ---" << endl;
    cout << s1.toUpperCase() << endl;
    cout << s1.toLowerCase() << endl;

    MyString padded("   test   ");
    cout << "[" << padded.trim() << "]" << endl;
    cout << s1.reverse() << endl;

    cout << "\n--- Search ---" << endl;
    cout << s1.find(MyString("World")) << endl;
    cout << s1.count('l') << endl;

    cout << "\n--- Append ---" << endl;
    MyString base("Data");
    cout << base.append("Base") << endl;
    cout << base.append(10) << endl;

    cout << "\n--- Operators ---" << endl;
    MyString a("Hi"), b("There");
    cout << a + b << endl;
    cout << (a == b) << endl;
    cout << a * 3 << endl;

    cout << "\nDone!" << endl;
    return 0;
}
