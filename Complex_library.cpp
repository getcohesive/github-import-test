#include<iostream>
#include<cmath>
using namespace std;

//sdsdsdsdsd

#define PI 3.14159265

class Complex
{
    private:
        float a, b;
    public:
        Complex(int x, int y)
        {
            a = x; b = y;
        }

        float modulus()
        {
            float mod = sqrt(pow(a, 2) + pow(b, 2));
            return mod;
        }

        void print_number()
        {
            if (b<0)
            {
                cout<<a<<"-"<<-b<<'i'<<endl;;
            }
            else
                cout<<a<<"+"<<b<<'i'<<endl;
        }

        Complex operator+(Complex c1)
        {
            return Complex(a+c1.a, b+c1.b);
        }

        Complex operator*(Complex c1)
        {
            return Complex(a*c1.a - b*c1.b, a*c1.b + b*c1.a);
        }

        Complex operator/(Complex c1)
        {
            if (c1.a == 0 && c1.b == 0)
            {
                cout<<"Division by zero error";
                return Complex(0, 0);
            }
            Complex temp = Complex(a, b)*c1;
            temp.a = temp.a/pow(c1.modulus(), 2);
            temp.b = temp.b/pow(c1.modulus(), 2);
            return temp;
        }

        float arg()
        {
            // the argument value of the number
            float angle = atan(b/a);
            angle = angle*180/PI;
            return angle;
        }
};

int main()
{
    Complex c1(3, 4), c2(12, 7);
    Complex c3 = c1+c2;
    c3.print_number();
    Complex ctest(1, 0);
    Complex c4 = c1 * ctest;
    c4.print_number();
    Complex c5 = ctest/c1;
    c5.print_number();
    cout<<c1.arg();
    Complex c6 = (c1 + c2) + c3;
    c6.print_number();

}
