#include<vector>
#include<string>
#include<iostream>

#include "media_number.h"

long get_factorial(int N){
  long current=1;
  while(N!=1){
    current*=N;
    --N;
  }
  return current;
}

decrease_media_number::decrease_media_number(long number,int N){
  this->N=N;
  this->factorial=get_factorial(this->N);
  long current=number;
  int current_n=N;
  number=number%(this->factorial);
  while(current_n!=1){
    this->numbers.push_back(current%current_n);
    current=current/current_n;
    --current_n;
  }
}

decrease_media_number::decrease_media_number(std::vector<int> numbers,int N){
  this->N=N;
  this->factorial=get_factorial(this->N);
  this->numbers=numbers;
}

long decrease_media_number::to_number(){
  long total=0;
  long current=1;
  for(int i=0;i<this->numbers.size();++i){
    total+=(current*this->numbers[i]);
    current*=(this->N-i);
  }
  return total;
}

std::string decrease_media_number::to_string(){
  std::string str="";
  for(int i=this->numbers.size()-1;i>=0;--i){
    str+=std::to_string(this->numbers[i]);
    if(i!=0){

        str+=",";
    }
  }
  return str;
}

std::vector<int> decrease_media_number::get_vector(){
  return this->numbers;
}

int decrease_media_number::get_N(){
  return this->N;
}
