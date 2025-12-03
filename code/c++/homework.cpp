#include <iostream>
using namespace std;

struct Student {
    char STUID[8]; 
    char FullName[30];
    char Gender[6];   
    float Point;
};

int main()
{
    Student * stu = new Student[10];
    FILE * fpin = fopen("input.txt","rt");
    FILE * fpout = fopen("output.txt","wt");
    int size = 0;
    if(fpin != NULL)
    {
        for(int i = 0;feof(fpin)==0;i++)
        {
            fscanf(fpin, "%[^-]-%[^(](%[^)])%f\n",
                &stu[i].STUID,
                &stu[i].FullName, 
                &stu[i].Gender,
                &stu[i].Point);
            size ++;
        }

        
        for(int i=0;i<size;i++)
        {
            for(int j = 0;j<size - i - 1;j++)
            {
                if(stu[j].Point > stu[j+1].Point)swap(stu[j],stu[j + 1]);
            }
        }
        
        for(int i = size-1;i>=0 && stu[size -1].Point == stu[i].Point;i--)
        {
            fprintf(fpout,"%s-%s(%s)%f\n",
                &stu[i].STUID,
                &stu[i].FullName,
                &stu[i].Gender,
                &stu[i].Point);
        }
        fclose(fpin);
        fclose(fpout);
    }

    return 0;
}