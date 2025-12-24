#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Student{
    int id;
    int mssv;
    char* name;
    double gpa;
};
//input file text with fomat: id-mssv(name)gpa

void input_file_text(Student* &stu,int& n)
{
    ifstream inp("students.txt");
    if (!inp.is_open())
    {
        n = 0;
        //  co nen dua ham duoi len day k
        return;
    }

    char buffer[1024];
    n = 0;

    // Đếm số dòng
    while (inp.getline(buffer, 1024))
    {
        n++;
    }

    // giống rewind()
    inp.clear();
    inp.seekg(0, ios::beg);

    stu = new Student[n];

    for (int i = 0; i < n; i++)
    {
        // cau truc getline; ifstream.getline(char[], so ki tu, char<stop condition>)
        // id
        inp.getline(buffer, 1024, '-');
        stu[i].id = atoi(buffer);

        // mssv
        inp.getline(buffer, 1024, '(');
        stu[i].mssv = atoi(buffer);

        // name
        inp.getline(buffer, 1024, ')');
        int len = strlen(buffer);
        stu[i].name = new char[len + 1];
        strcpy(stu[i].name, buffer);

        // gpa
        inp.getline(buffer, 1024);
        stu[i].gpa = atof(buffer);
    }
    inp.close();
}
// function to convert int, long to string 
// #include <cstdio>   // hoặc <stdio.h>

// char str[20];
// int x = 123;

// sprintf(str, "%d", x);

void output_file_text(const Student* &stu,const int& n)
{
    ofstream out("output.txt",ios::trunc);
    for(int i=0;i<n;i++)
    {
        out << stu[i].id << "-" << stu[i].mssv << "(" << stu[i].name << ")" << stu[i].gpa << endl;
    }
    out.close();
}

// binary file

void input_binary_file(Student*&stu,int& n)// tam thoi ko xet la do binary ko can ki tu phan cach
{
    ifstream inp("input.bin",ios::binary);
    if(!inp.is_open())
    {
        return;
    }
    // input something
    inp.read((char*)&n, sizeof(n));
    inp.close();
}