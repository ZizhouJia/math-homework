#include <vector>
#include<string>
class media_number_c
{
    public:
        //N代表为N个数的全排列
        //number为升序中介数的10进制表示
        media_number_c(long number,std::vector<int> a, int N);
        media_number_c(std::vector<int> numbers, std::vector<int> a,int N);
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
        std::vector<int> a;
};
long get_factorial(int N);
long get_cni(int N,int i);
