#include<iostream>
using namespace std;
class Complex
{
    private:
    int real,imaginary;
    public:
        Complex(int a=0, int b=0)
        {
            real=a;
            imaginary=b;
        }
        Complex operator + (Complex const &n)
        {
            Complex add;
            add.real=real+n.real;
            add.imaginary=imaginary+n.imaginary;
            return add;
        }
       
        Complex operator-(Complex const &n)
        {
            Complex sub;
            sub.real=real-n.real;
            sub.imaginary=imaginary-n.imaginary;
            return sub;
        }
        void display1()
        {
            if(imaginary<0)
                cout<<"complex number: "<<real<<" "<<imaginary<<"i\n";
            else
                cout<<"complex number: "<<real<<" + "<<imaginary<<"i\n";
        }
        void display2()
        {
            if(imaginary<0)
                cout<<real<<" "<<imaginary<<"i\n";
            else
                cout<<real<<" + "<<imaginary<<"i\n";
        }
};

int main ()
{
  int a, b, c, d;
  cout << "Enter real part of 1st complex number ";
  cin >>a;
  cout << "Enter imaginary part of 1st complex number ";
  cin >>b;
  cout << "\nEnter real part of 2nd complex number ";
  cin >>c;
  cout << "Enter imaginary part of 2nd complex number ";
  cin >>d;
  Complex t(a,b),t1(c,d),t3,t4;
  cout<<"\nFirst ";
  t.display1();
  cout<<"Second ";
  t1.display1();
  cout<<"\nAddition: ";
  t3=t+t1;
  t3.display2();
  t4=t-t1;
  cout<<"Substraction: ";
  t4.display2();
  return 0;
}
