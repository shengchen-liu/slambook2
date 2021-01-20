#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
  cout << "Hello SLAM!" << endl;
  string food = "pizza";
  string* ptr = &food;
  cout << ptr << endl;

  *ptr = "Hambu";
  cout << ptr << endl;
  int *p = 0;  // pointer p points to address 0, but at this address we don't initialize a value
  cout << p << endl;
  *p = 1;
  return 0;
}
 