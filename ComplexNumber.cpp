#include<iostream>
using namespace std;

class Complex
{
	public:
		float real;
		float img;
		
		Complex ()
		{
			real = 0;
			img = 0;
			
		}
		
		Complex operator + (Complex c1)
		{
			Complex temp;
			temp.real = real + c1.real;
			temp.img = img + c1.img;
			return temp;
			
		}
		
		Complex operator * (Complex c2)
		{
			Complex temp;
			temp.real = real * c2.real - img * c2.img;
			temp.img = real * c2.img + img * c2.real;
			return temp;
		}
		
		friend istream & operator >> (istream &, Complex & i);
		friend ostream & operator << (ostream &, Complex & i);
		
};

istream & operator >> (istream &, Complex & i)
{
	cin >> i.real >> i.img;
	return cin;
}

ostream & operator << (ostream &, Complex & i)
{
	cout << i.real << " + " << i.img <<"i" << endl;
	return cout;
}

int main()
{
	Complex C1,C2,C3,C4;
	cout << "Enter real and imaginary part of the Complex Number 1 : \n";
	cin >> C1;
	cout << "Enter real and imaginary part of the Complex Number 2: \n";
	cin >> C2;
	
	cout << "\nComplex No. 1 : " << C1 << endl;
	cout << "\nComplex No. 2 : " << C2 << endl;
	
	C3 = C1 + C2;
	cout << "Addition of Complex No is : " << C3 << endl;
	C4 = C1 * C2;
	cout << "Multiplicaiton of Complex No. is : " << C4 << endl;
	
	return 0;
	 
}
