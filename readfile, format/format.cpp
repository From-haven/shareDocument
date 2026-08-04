#include <print>
#include <vector>
#include <string>
#include "Data.h"
#include "read_file.h"
using namespace std;



int main(){
    // vector<Data> datas = {
    //     {"1","A",10},
    //     {"2","B",10.5},
    //     {"3","C",11.2},
    //     {"4","DE",double(11/3)},
    // };
    vector<Data> datas = readfile();
    println("{}",datas.size());
    println("|{:^3}| {:<12}| {:<14}|","STT","Ho va Ten","Luong");
    println("{:-^35}","-");
    for(auto data:datas){
        println("|{:<3}| {:<12}| {:<14}|",data.id,data.name,data.salary);
    }
    // return 0;

    
}
