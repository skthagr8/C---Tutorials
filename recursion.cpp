#include <iostream>
using namespace std;


int calculateFactorial(int number){
    if(number == 0 || number == 1){
        return 1;
    } else {
        return number * calculateFactorial(number - 1);
    }
}

int main (){
    int number = 5;
    cout << calculateFactorial(number) << endl;
    return 0;
}