#include <iostream>

class numbers {
    private :
     const int constant = 10;
    public :
      int num;

    explicit numbers(int num) : num(num) {}
    numbers() : num(0) {}

    int getNumber() {
        return num;
    }
};


int main(){
    numbers n1;
    std::cout <<"The retrieve number is "<< n1.getNumber()<< std::endl;
    return 0;
}