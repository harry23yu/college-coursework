#include <iostream>

using namespace std;

void function(int num, int ctr, int &r) {
  int i;
  for(i = 2;i <= num/2; i++){
    if(num % i==0){
      ctr++;
      break;
    }
  }
  if(ctr == 0 && num != 1)
    r = 1;
  
  else
    r = 0;
}

int main(){

  int num, ctr = 0, r = -1;
  cout << "Input a number: ";
  cin >> num;
  
  function(num, ctr, r);
  cout << r << endl;;

  return 0;
}
