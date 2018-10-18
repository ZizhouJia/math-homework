#pragma once
#include<vector>
#include<string>

class decrease_media_number{
  public:
    //N代表为N个数的全排列
    //number为降序中介数的10进制表示
    decrease_media_number(long number,int N);

    decrease_media_number(std::vector<int> numbers,int N);
    //返回该数的十进制表示
    long to_number();
    //返回该数的字符串
    std::string to_string();
    //获取该数的vector
    std::vector<int> get_vector();
    //获取全排列的位
    int get_N();

  private:
    int N;
    std::vector<int> numbers;
    long factorial;
};

class increase_media_number{
  public:
    //N代表为N个数的全排列
    //number为降序中介数的10进制表示
    increase_media_number(long number,int N);
    //返回该数的十进制表示
    long to_number();
    //返回该数的字符串
    std::string to_string();
    //获取该数的vector
    std::vector<int> get_vector();
    //获取全排列的位
    int get_N();

  private:
    int N;
    std::vector<int> numbers;
};
