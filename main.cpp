#include <iostream>
#include "vector.h"

int main() {
    Vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(7);

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
