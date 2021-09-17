#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool CheckSmil(char first, char second, char third);

int main()
{
    vector<int> positions;
    string str;
    cin >> str;

    for (int i = 0; i < str.length() - 1; i++) {
        if(CheckSmil(str[i], str[i+1], str[i+2])) {
            positions.push_back(i);
        }
    }

    for (auto i : positions) {
        cout << i << endl;
    }

    return 0;
}

bool CheckSmil(char first, char second, char third) {
    if(first == ':' || first == ';') {
        if(second == ')') {
            return true;
        } else if(second == '-') {
            return third == ')';
        }
    }
    return false;
}
