
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <numeric>

std::string cat(const std::string& word, int number){
    return word + std::to_string(number);
}

auto cat2(std::string const& s, int i) {
return s + '-' + std::to_string(i);
}


int main () {

std::vector<int> v{2,3,5};
auto s =std::accumulate(begin(v), end(v),std::string{"XY"}, // Initial value
[](const std::string& acc, int i) {
            return acc + '-' + std::to_string(i);
        }
    );
 // XY-2-3-5
std::cout << s << std::endl;

    
    return 0;
}