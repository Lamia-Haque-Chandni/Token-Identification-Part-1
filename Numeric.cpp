#include <iostream>
using namespace std;

bool numeric(string s){
    for (char num : s){
        if (num < '0' || num > '9'){
            return false;
        }
    }
    return true;
}

int main(){
    string a;

    cout << "Input: ";
    cin >> a;

    if (numeric(a)){
        cout << "Numeric" << endl;
    }
    else{
        cout << "Not Numeric" << endl;
    }

    return 0;
}
