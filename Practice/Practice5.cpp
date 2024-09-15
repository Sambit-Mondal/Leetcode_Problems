#include<bits/stdc++.h>
using namespace std;

bool isEligibleToVote(int age) {
    if(age >= 18) {
        return true;
    }
    return false;
}

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if(isEligibleToVote(age)) {
        cout << "You are eligible to vote." << endl;
    } else {
        cout << "You are not eligible to vote." << endl;
    }

    int *agePtr = &age;
    if(isEligibleToVote(*agePtr)) {
        cout << "Pointer: You are eligible to vote." << endl;
    } else {
        cout << "Pointer: You are not eligible to vote." << endl;
    }

    return 0;
}