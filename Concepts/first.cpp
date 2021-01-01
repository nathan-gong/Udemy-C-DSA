/*
Using MinGW compiler, VSCode, Windows:
Add .\bin to PATH environment var
Run Build Task -> C/C++: g++.exe build active file
*/

#include <iostream>

int main() {
    int a, b, c;
    a = 10;
    b = 20; 
    c = a + b;

    std::cout << c << std::endl;
    std::cout << "Hello World!\n";
}