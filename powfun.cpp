#include <iostream>
using namespace std;
int power(int a, int y) {
 if (y == 0)
 return 1;
 int temp = power(a, y / 2);
 if (y % 2 == 0) {
 return temp * temp;
 } else {
 return a * temp * temp;
 }
}
int main() {
 int a = 2; 
 int y = 5; 
 int output = power(a, y); 
 cout << "The value of " << a << " raised to power " << y << " is: " << output << 
endl;
 cout << "Jyoti Kashyap" << endl;
 return 0;
}
