#include <string>
#include <fstream>
#include <vector>
#include <print>
#include <sstream>
#include "Data.h"
#include "read_file.h"
using namespace std;

vector<Data> readfile(){
    vector<Data> datas;
    ifstream inp("data.txt");
    if(! inp.is_open()){
        println("not read data.txt file");
        return datas;
    }

    string line;
    int n = 0;
    while(getline(inp,line)){
        n++;
        stringstream ss(line);
        Data temp;
        string buffer;
        getline(ss,buffer,',');
        temp.id = buffer;

        getline(ss,buffer,',');
        temp.name = buffer;

        getline(ss,buffer);
        temp.salary = stod(buffer);

        datas.push_back(temp);
    }
    return datas;
}