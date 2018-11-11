#include "NewPerm.h"
#include "media_number_c.h"
#include <iostream>
//排列
NewPerm::NewPerm(std::vector<int> numbers,int N){
    this->numbers=numbers;
    this->N=N;
}
//
std::vector<int> NewPerm::get_vector(){
    return this->numbers;
}
std::string NewPerm::to_string(){
    std::string str="";
    for(int i=this->numbers.size()-1;i>=0;--i){
        str+=std::to_string(this->numbers[i]);
        str+=" ";
    }
    return str;
}
int NewPerm::get_N(){
    return this->N;
}

//根据可选的下标生成排列，针对一个元素
//p是生成的排列，ava_flag是p中可选的下标,n是当前可选的下标个数，
//m是当前元素要选的位置个数，put_number是当前元素,mc是当前位的media_c
std::vector<int> generate_perm_pernum(std::vector<int> p,std::vector<int> ava_flag,int n,int m,int put_number,int mc){
    if(m==0){
        return p;
    }
/*
    if(m==n){
        for(int i=0;i<ava_flag.size();i++){
            p[ava_flag[i]]=put_number;
        }
        return p;
    }*/
    long tag=get_cni(n-1,m);
    if(mc<tag){
        //ava_flag.erase(0,1);
        ava_flag.pop_back();
        p=generate_perm_pernum(p,ava_flag,n-1,m,put_number,mc);
    }else{
        mc=mc-tag;
        p[ava_flag[ava_flag.size()-1]]=put_number;
        //p[ava_flag[0]]=put_number;
        ava_flag.pop_back();
        //ava_flag.erase(0,1);
        p=generate_perm_pernum(p,ava_flag,n-1,m-1,put_number,mc);
    }
    return p;
}

//index->perm,n->perm's length,m->not same number,a->0~m-1->1~m
NewPerm generate_permutation_new(long index,int N,std::vector<int> a){

    //10进制->c 进制
    media_number_c mc_number=media_number_c(index,a,N);
    //std::cout<<mc_number.to_number()<<std::endl;
    //std::cout<<mc_number.to_string()<<std::endl;
    std::vector<int> mc_vector=mc_number.get_vector();
    std::vector<int> p_vector(N,0);
    std::vector<int> ava_flag;
    for(int i=0;i<N;i++){
        p_vector[i]=0;
        ava_flag.push_back(i);
    }
    int cur_n=N;
    for(int i=0;i<a.size();i++){
        int num=i+1;
        p_vector=generate_perm_pernum(p_vector,ava_flag,cur_n,a[i],num,mc_vector[i]);
        cur_n=cur_n-a[i];
        ava_flag.clear();
        for(int j=0;j<N;j++){
            if(p_vector[j]==0){
                ava_flag.push_back(j);
            }
        }
    }
    NewPerm newperm = NewPerm(p_vector,N);
    return newperm;
}

//根据可选的下标生成排列，针对一个元素
//p是生成的排列，ava_flag是p中可选的下标,n是当前可选的下标个数，
//m是当前元素要选的位置个数，put_number是当前元素,mc是当前位的media_c
int from_permutation_pernum(std::vector<int> p,std::vector<int> ava_flag,int n,int m,int put_number){
    if(m==0){
        return 0;
    }
    int index=0;
    //long tag=p[ava_flag[0]];
    long tag=p[ava_flag[ava_flag.size()-1]];
    if(tag==put_number){
        ava_flag.pop_back();
        //ava_flag.erase(0,1);
        index=get_cni(n-1,m)+from_permutation_pernum(p,ava_flag,n-1,m-1,put_number);
    }else{
        ava_flag.pop_back();
        //ava_flag.erase(0,1);
        index=from_permutation_pernum(p,ava_flag,n-1,m,put_number);
    }
    return index;
}

//perm->index,p_number->排列数
//a_vector 重复元素计数
//ava_flag 记录可以放的元素的位置
long from_permutation_new(NewPerm& p_number){

    std::vector<int> p_vector=p_number.get_vector();
    int N=p_number.get_N();
    int m=0;
    std::vector<int> ava_flag(N,0);
    for(int i=0;i<N;i++){
        if(p_vector[i]>m){
            m=p_vector[i];
        }
        ava_flag.push_back(i);
    }
    std::vector<int> a_vector(m,0);
    for(int i=0;i<m;i++){
        a_vector[i]=0;
    }
    for(int i=0;i<N;i++){
        a_vector[p_vector[i]-1]=a_vector[p_vector[i]-1]+1;
    }
    std::vector<int> mc_vector(m,0);
    int cur_n=N;
    for(int i=0;i<a_vector.size();i++){
        int num=i+1;
        int index=from_permutation_pernum(p_vector,ava_flag,cur_n,a_vector[i],num);
        mc_vector[i]=index;
        cur_n=cur_n-a_vector[i];
        ava_flag.clear();
        for(int j=0;j<N;j++){
            if(p_vector[j]>num){
                ava_flag.push_back(j);
            }
        }
    }

    media_number_c mnc=media_number_c(mc_vector,a_vector,N);
    return mnc.to_number();
}
