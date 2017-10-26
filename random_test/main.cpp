#include <iostream>

int main() {
    int random;
    srand (time(NULL));
    std::cout << "Hello, World! This is another test!" << std::endl;
    random = rand()%10+1;
    std::cout << "The number is " << random << std::endl;
    return 0;
}