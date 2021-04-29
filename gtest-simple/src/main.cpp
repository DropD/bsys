#include "../include/square_plus_one.hpp"

int main() {
    using namespace gtest_simple;
    std::cout << square_plus_one(1) << std::endl;
    std::cout << square_plus_one(2.01) << std::endl;
    std::cout << square_plus_one(vec2di_ew(3, 13)) << std::endl;
    //std::cout << square_plus_one(vec2di_dot(5, 21)) << std::endl;
    std::cout << square_plus_one(8) << std::endl;
}
