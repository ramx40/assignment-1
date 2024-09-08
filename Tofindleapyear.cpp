789// Program for finding a Leap Year

#include <iostream>

int main() {
  int year =0;
  std::cout<<"Enter year:\n";
  std::cin >> year;
//   (||) is an OR operater used for as true or false
  if (year < 0001 || year > 9999){
    std::cout<<"Invalid Entry\n";
  }
  else if (year%4 == 0){
    std::cout <<year;
    std::cout<<" Its a leap year\n";
  }
  else{
    std::cout<<year;
    std::cout<<" Not a leap year\n";
  }
}