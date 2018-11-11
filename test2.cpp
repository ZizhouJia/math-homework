#include <iostream>
#include "media_number_c.h"
#include "NewPerm.h"
#include <time.h>
#include <Windows.h>
using namespace std;

int main()
{
    //long t=29;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);
    a.push_back(1);
    int N=5;
    int success=1;
    clock_t start;
    start = clock();
    //NewPerm np=NewPerm(a,6);
    for(int i=0;i<60;i++){
        NewPerm tmpnp=generate_permutation_new(i,N,a);

        //cout<<tmpnp.to<<endl;

        long reindex=from_permutation_new(tmpnp);
        if(i<10){
            cout<<"index="<<i<<" ,perm="<<tmpnp.to_string()<<",perm to index:"<<reindex<<endl;
        }else{
            cout<<"index="<<i<<",perm="<<tmpnp.to_string()<<",perm to index:"<<reindex<<endl;
        }

        if(reindex!=i){
            success=0;
            break;
        }
        //cout<<reindex<<endl;
    }
    cout<<clock()-start<<" ms"<<endl;
    if(success){
        std::cout<<"all test success"<<std::endl;
    }else{
        std::cout<<"test failed"<<std::endl;
    }




    vector<int> p;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    system("pause");
    return 0;
}
