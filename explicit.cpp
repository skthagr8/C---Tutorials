#include <iostream>
#include <string>

class MyClass {
public:
    // Explicit constructor
    explicit MyClass(int x) : value(x) {}

    void print() {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};

int main() {
   //  MyClass obj = 42; // Error: No implicit conversion allowed
   MyClass obj(42);    // Allowed: Explicit construction
    obj.print();        // Output: Value: 42

    return 0;
}
