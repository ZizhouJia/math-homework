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

//N代表为N个数的全排列
//number为升序中介数的10进制表示
//已知十进制序号构造中介数(十进制数->递增进制数)
increase_media_number::increase_media_number(long number, int N){
	this->N = N;
	this->factorial = get_factorial(this->N);
	long current = number;
	int current_n = 2;
	while (current_n != N+1){
        if(current ==0){
            this->numbers.push_back(current);
        }else{
            this->numbers.push_back(current%current_n);
        }
		current = current / current_n;
		++current_n;
	}
}
//已知中介数初始化
increase_media_number::increase_media_number(vector<int> numbers, int N){
	this->N = N;
	this->factorial = get_factorial(this->N);
	this->numbers = numbers;
}

//返回该数的十进制表示,(递增进制数->十进制数)
long increase_media_number::to_number(){
	long denum = 0;
	int current_n = 2;
	while (current_n-2<this->numbers.size()){
		denum += get_factorial(current_n-1)*this->numbers[current_n-2];
		current_n++;
	}
	return denum;
}
//返回该数的字符串
string increase_media_number::to_string(){
	string str = "";
	for (int i = this->numbers.size() - 1; i >= 0; i--){
		str += std::to_string(this->numbers[i]);
		if (i != 0){
			str += ",";
		}
	}
	return str;
}
//获取该数的vector
vector<int> increase_media_number::get_vector(){
	return this->numbers;
}
//获取全排列的数字个数
int increase_media_number::get_N(){
	return this->N;
}

increase_media_number::~increase_media_number(){

}
