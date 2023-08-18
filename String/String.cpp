#include "String.h"

int main() {
    auto string = String("ba");
    auto string1 = String("bal");
    std::cout << string[0] << std::endl;
    std::cout << string.size() << std::endl;
    string.concatChar('s');
    std::cout << string << std::endl;
    std::cout << string.concat(String("ala")) << std::endl;
    std::cout << string << std::endl;
    std::cout << (string < string1 )<< std::endl;
}