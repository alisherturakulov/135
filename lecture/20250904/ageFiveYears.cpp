#include <iostream>
#include <string>//included in iostream but not always

int main(){

    int age{};
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Five years from now you will be : " << age + 5 << std::endl;
    return 0;
}
