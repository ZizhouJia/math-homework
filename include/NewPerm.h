#include<vector>
#include<string>

class NewPerm
{
    public:
        NewPerm(std::vector<int> numbers,int N);
        std::vector<int> get_vector();
        std::string to_string();
        int get_N();
    private:
        std::vector<int> numbers;
        int N;
};

NewPerm generate_permutation_new(long index,int N,std::vector<int> a);

long from_permutation_new(NewPerm& p_number);
