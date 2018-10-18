#include<vector>
#include<string>
#include<iostream>

#include "permutation.h"

permutation_number::permutation_number(std::vector<int> numbers,int N){
  this->numbers=numbers;
  this->N=N;
}

std::vector<int> permutation_number::get_vector(){
  return this->numbers;
}

std::string permutation_number::to_string(){
  std::string str="";
  for(int i=this->numbers.size()-1;i>=0;--i){
    str+=std::to_string(this->numbers[i]);
    str+=" ";
  }
  return str;
}

int permutation_number::get_N(){
  return this->N;
}

permutation_number generate_permutation_1(long index,int N){
  decrease_media_number m_number(index,N);
  std::vector<int> m_vector=m_number.get_vector();
  std::vector<int> p_vector(N,0);

  for(int i=0;i<N;++i){
    p_vector[i]=i;
  }
  for(int n=N;n>=1;--n){
    int space=0;
    if(n!=1){
      space=m_vector[N-n];
    }
    for(int j=N-1;j>=0;--j){
      if(p_vector[j]>=n){
        continue;
      }
      if(p_vector[j]==space){
        p_vector[j]=n;
        break;
      }
      --p_vector[j];
    }
  }
  permutation_number p_number(p_vector,N);
  return p_number;
}

long from_permutation_1(permutation_number& p_number){
  std::vector<int> p_vector=p_number.get_vector();
  int N=p_number.get_N();
  std::vector<int> m_vector(N-1,0);
  for(int n=2;n<=N;++n){
    for(int j=N-1;j>=0;--j){
      if(p_vector[j]==n){
        int count=0;
        for(int k=j-1;k>=0;--k){
          if(p_vector[k]<n){
            ++count;
          }
        }
        m_vector[N-n]=count;
        break;
      }
    }
  }
  decrease_media_number m_number(m_vector,N);
  return m_number.to_number();
}

permutation_number generate_permutation_2(long index,int N){
  decrease_media_number m_number(index,N);
  std::vector<int> m_vector=m_number.get_vector();
  std::vector<int> p_vector(N,1);
  for(int i=0;i<N-1;++i){
    int left=0;
    if(i==N-2){
      left=1;
    }else{
      if((N-i)%2==1){
        left=(1+m_vector[i+1])%2;
      }else{
        left=(1+m_vector[i+1]+m_vector[i+2])%2;
      }
    }
    int step=m_vector[i];
    if(left){
      for(int j=0;j<N;++j){
        if(step==0 && p_vector[j]==1){
          p_vector[j]=N-i;
          break;
        }
        if(step!=0 && p_vector[j]==1){
          --step;
          continue;
        }
      }
    }else{
      for(int j=N-1;j>=0;--j){
        if(step==0 && p_vector[j]==1){
          p_vector[j]=N-i;
          break;
        }
        if(step!=0 && p_vector[j]==1){
          --step;
          continue;
        }
      }
    }
  }
  permutation_number p_number(p_vector,N);
  return p_number;
}

long from_permutation_2(permutation_number& p_number){
  std::vector<int> p_vector=p_number.get_vector();
  int N=p_number.get_N();
  std::vector<int> m_vector(N-1,0);
  int left=1;
  for(int n=2;n<=N;++n){
    if(left){
      int count=0;
      for(int j=N-1;j>=0;--j){
        if(p_vector[j]==n){
          for(int k=j-1;k>=0;--k){
            if(p_vector[k]<n){
              ++count;
            }
          }
          m_vector[N-n]=count;
          break;
        }
      }
    }else{
      int count=0;
      for(int j=0;j<N;++j){
        if(p_vector[j]==n){
          for(int k=j+1;k<N;++k){
            if(p_vector[k]<n){
              ++count;
            }
          }
          m_vector[N-n]=count;
          break;
        }
      }
    }
    if(n%2==0){
      left=(m_vector[N-n]+1)%2;
    }else{
      left=(m_vector[N-n]+m_vector[N-n+1]+1)%2;
    }
  }
  decrease_media_number m_number(m_vector,N);
  return m_number.to_number();
}
