#include "media_number_c.h"
#include <vector>
#include <string>

long get_factorial(int N){
  long current=1;
  while(N!=1){
    current*=N;
    --N;
  }
  return current;
}
long get_cni(int N,int i){
  if(i>N){
    return 0;
  }
  if(N==i|i==0){
    return 1;
  }
  long current=get_factorial(N)/(get_factorial(i)*get_factorial(N-i));
  return current;
}



//十进制->c
//number 十进制,N 全排列总数，a 不同的数的计数
media_number_c::media_number_c(long number,std::vector<int> a, int N){
    this->N=N;
    this->a=a;
    //m个不同的数
    int m=a.size();
    long current = number;
    int i=0;
    int current_n=get_cni(N,a[i]);
    int cur_cn=N;
    while(i<m){
        if(current==0){
            this->numbers.push_back(current);
        }else{
            this->numbers.push_back(current%current_n);
        }
        current=current/current_n;
        i++;
        cur_cn=cur_cn-a[i-1];
        if(cur_cn!=0){
            current_n=get_cni(cur_cn,a[i]);
        }
    }
}

media_number_c::media_number_c(std::vector<int> numbers,std::vector<int> a_vector,int N){
    this->N=N;
    this->numbers=numbers;
    this->a=a_vector;
}
//返回该数的十进制表示
long media_number_c::to_number(){
    long denum = this->numbers[0];
    int i=1;
    int cur_cn=this->get_N();
    int re=get_cni(cur_cn,this->a[i-1]);
	//int current_n = ;
	while (i<this->numbers.size()){
		denum += re*this->numbers[i];
		cur_cn=cur_cn-a[i-1];
		re=re*get_cni(cur_cn,this->a[i]);
		i++;
	}
    return denum;
}
//返回该数的字符串
std::string media_number_c::to_string(){
    std::string str = "";
	for (int i = this->numbers.size() - 1; i >= 0; i--){
		str += std::to_string(this->numbers[i]);
		if (i != 0){
			str += ",";
		}
	}
    return str;
}
//获取该数的vector
std::vector<int> media_number_c::get_vector(){
    return this->numbers;
}
//获取全排列的位
int media_number_c::get_N(){
    return this->N;
}

