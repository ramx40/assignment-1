// Program to check result
#include <iostream>
int main()
{
    double ram;
    std::cout << "Enter the marks:\n";
    std::cin >> ram;
      if (ram<1 || ram>100 ){
        std::cout << "Invalid Number\n";
    }
    else if (ram>60 ){
        std::cout << "Pass\n";
    }
    else if (ram<60){
        std::cout<< "Fail\n";
    }
    
          else if (ram=60){
        std::cout<< "Its okay\n";
    }
}