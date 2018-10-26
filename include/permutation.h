#pragma once
#include<vector>
#include<string>

#include "media_number.h"

class permutation_number{
  public:
    permutation_number(std::vector<int> numbers,int N);
    std::vector<int> get_vector();
    std::string to_string();
    int get_N();
  private:
    std::vector<int> numbers;
    int N;
};

permutation_number generate_permutation_1(long index,int N);

long from_permutation_1(permutation_number& p_number);

permutation_number generate_permutation_2(long index,int N);

long from_permutation_2(permutation_number& p_number);

permutation_number generate_permutation_dict(long index, int N);

long from_permutation_dict(permutation_number& p_number);

permutation_number generate_permutation_increase(long index, int N);

long from_permutation_increase(permutation_number& p_number);
