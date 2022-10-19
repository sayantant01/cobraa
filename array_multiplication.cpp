#include<iostream>
#include<stdio.h>
using namespace std;
class arr_mul
{
    private:
    int a[3][3],c[3][3];
    public:
    arr_mul();
    arr_mul(int z[3][3]);
    arr_mul operator*(arr_mul const &t5);
    void display();
    
};
arr_mul::arr_mul()
{
}
arr_mul::arr_mul(int z[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            a[i][j]=z[i][j];
    }
}
arr_mul arr_mul :: operator*(arr_mul const &t5)
{
    arr_mul t4;
    for(int i=0;i<3;i++)    
    {    
        for(int j=0;j<3;j++)    
        {    
            t4.c[i][j]=0;
            for(int k=0;k<3;k++)    
            {    
                t4.c[i][j]+=a[i][k]*t5.a[k][j];    
            }    
        }    
    }    
    return t4;
}
void arr_mul ::display()
{
    cout<<"Multiplication : \n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
}
int main()
{
    int array[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
    int array2[3][3]={{9,8,7},{6,5,4,},{3,2,1}};
    arr_mul t(array);
    arr_mul t1(array2);
    arr_mul t3=t*t1;
    t3.display();
    return 0;
}