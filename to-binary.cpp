#include <iostream>

// https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int main() {
    std::cout << "binary value of 624485 = " << toBinary(624485) << "\n";
    return 0;
}