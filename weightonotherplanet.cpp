// program for finding weigth on other planets
#include <iostream>

int main() {
  double weight;
  int ram;
  std::cout << "please enter your weight on earth\n";
  std::cin>>weight;
  std::cout<< "\n I have info for the planets\n";
  std::cout<<"1.Mercury\n 2.Venus\n 3.Mars\n 4.Jupiter\n 5.Saturn\n 6.Uranus\n 7.Neptune\n";
  std::cout<<"which planet are you visiting?\n";
  std::cin >> ram;
  if(ram==1){
  weight = weight*0.38;
 }
 else if(ram==2){
  weight = weight*0.91;
 }
 else if(ram==3){
  weight = weight*0.38;
 }
 else if(ram==4){
  weight = weight*2.34;
 }
 else if(ram==5){
  weight = weight*1.06;
 }
 else if(ram==6){
  weight = weight*0.92;
 }
  else if(ram==7){
  weight = weight*1.19;
 }
  std::cout << "\n Your weight: " << weight<<"\n";
  
}