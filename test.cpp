#include <iostream>
using namespace std;

int main(){
    string a = "bl4ue";
    bool numExists = false;
    string c = "";
    for(int ii = 0; ii < a.length(); ii++){
        if(a[ii] == '0' || a[ii] == '1' || a[ii] == '2' || a[ii] == '3' || a[ii] == '4' || a[ii] == '5' || a[ii] == '6' || a[ii] == '7' ||a[ii] == '8' ||a[ii] == '9' ){
            numExists = true;
            c += a[ii];
        }
    }
    if(numExists){
        int b = stoi(c);
        cout << b << endl;
    }

}