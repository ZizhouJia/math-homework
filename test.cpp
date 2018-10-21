#include<iostream>
#include<string>

#include "permutation.h"

long get_factorial(int N){
  long current=1;
  while(N!=1){
    current*=N;
    --N;
  }
  return current;
}

int main(){
  int N[4]={1,2,5,10};
  int succeed=1;

  for(int n=0;n<4;++n){
    long count=get_factorial(N[n]);

    for(long i=0;i<count;++i){
      permutation_number number=generate_permutation_1(i,N[n]);
      long index=from_permutation_1(number);
      if(index!=i){
        std::cout<<"permutation 1 error in test N="<<std::to_string(N[n])<<std::endl;
        std::cout<<"error in ("<<std::to_string(index)<<","<<std::to_string(i)<<")"<<std::endl;
        std::cout<<number.to_string()<<std::endl;
        succeed=0;
        break;
      }
    }

    for(long i=0;i<count;++i){
      permutation_number number=generate_permutation_2(i,N[n]);
      long index=from_permutation_2(number);
      if(index!=i){
        std::cout<<"permutation 2 error in test N="<<std::to_string(N[n])<<std::endl;
        std::cout<<"error in ("<<std::to_string(index)<<","<<std::to_string(i)<<")"<<std::endl;
        std::cout<<number.to_string()<<std::endl;
        succeed=0;
        break;
      }
    }
    
    for(long i=0;i<count;++i){
      permutation_number number=generate_permutation_dict(i,N[n]);
      long index=from_permutation_dict(number);
      if(index!=i){
        std::cout<<"permutation 2 error in test N="<<std::to_string(N[n])<<std::endl;
        std::cout<<"error in ("<<std::to_string(index)<<","<<std::to_string(i)<<")"<<std::endl;
        std::cout<<number.to_string()<<std::endl;
        succeed=0;
        break;
      }
    }
    
    for(long i=0;i<count;++i){
      permutation_number number=generate_permutation_increase(i,N[n]);
      long index=from_permutation_increase(number);
      if(index!=i){
        std::cout<<"permutation 2 error in test N="<<std::to_string(N[n])<<std::endl;
        std::cout<<"error in ("<<std::to_string(index)<<","<<std::to_string(i)<<")"<<std::endl;
        std::cout<<number.to_string()<<std::endl;
        succeed=0;
        break;
      }
    }
  }
  if(succeed){
    std::cout<<"all test succeed"<<std::endl;
  }else{
    std::cout<<"test failed"<<std::endl;
  }


}
