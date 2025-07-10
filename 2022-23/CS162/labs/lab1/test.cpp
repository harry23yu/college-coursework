#include <iostream>
#include <string>

using namespace std;

void foo(int x);

int main() {
  string name = "HARRY YU";
  cout << "My name is: " << name << endl;
  foo(2);
  foo(4);
  foo(2 + 4);
  foo(2 - 4);
  foo(2 * 4);
  foo(2 / 4);
}


void foo(int x) {
  cout << "The function foo was passed the number: " << x << endl;
}
