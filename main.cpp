#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
#define LINE_D for (size_t i = 0; i < 6; i++)cout<<'-';
class Fraction
{
	int integer; // целая часть
	int numerator;// числитель
	int denominator;//знаменатель
public:
	// Методы
	int Get_integer()const
	{
		return integer;
	}
	int Get_numerator()const
	{
		return numerator;
	}
	int Get_denominator()const
	{
		return denominator;
	}
	void Set_integer(int integer)
	{
		this->integer = integer;
	}
	void Set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void Set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	void Print()
	{
		//cout << " \t   " << numerator << "\n\t " << integer << "----\n" << " \t   " << denominator << endl;
		cout << " \n\n\t   " << numerator << "\n\t " << integer; LINE_D;
		cout << "\n \t   " << denominator << endl;
	}
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		Set_integer(integer);
		Set_numerator(numerator);
		Set_denominator(denominator);
		if (denominator == 0)this->denominator = 1;
		return *this;
	}
	Fraction& to_proper()
	{
		if (integer > 0)
		{
			int a = integer * denominator + numerator;
			integer = 0;
			numerator = a;
			cout << "\nЦелая часть интегрируется в числитель = ";
			Print();
			return *this;
		}
		else cout << "to_proper() - целая часть отсутствует!";
	}
	Fraction& to_improper()
	{
		if (numerator > denominator)
		{
			do
			{
				this->numerator -= denominator;
				this->integer++;
			} while (numerator >= denominator);
			cout << "\nВыделение целой части из числителя = ";
			Print();
			return *this;
		}
		else
		{
			if (numerator == denominator)
			{
				this->integer++;
				this->numerator -= denominator;
				cout << "\nВыделение целой части из числителя = ";
				Print();
				return *this;
			}
			else cout << "\nto_improper() - числитель меньше знаменателя!";

		}
	}
	// Операторы 


};

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	cout << "\nЧислитель = "; is >> numerator ;
	cout << "\nЗнаменатель = "; is >> denominator;
	cout << "\nЦелая часть = "; is >> integer ;
	obj(integer, numerator, denominator);
	system("cls");
	return is;
}
Fraction operator+( Fraction& Drob1,  Fraction& Drob2)
{
	Fraction result;
	if (Drob1.Get_denominator() == Drob2.Get_denominator())
	{
		result.Set_integer(Drob1.Get_integer() + Drob1.Get_integer());
		result.Set_numerator(Drob1.Get_numerator() + Drob1.Get_numerator());
		return result;
	}
	else
	{
		Drob1.to_proper();
		Drob2.to_proper();
		result.Set_numerator(((Drob1.Get_numerator() * Drob2.Get_denominator()) + (Drob2.Get_numerator() * Drob1.Get_denominator())));
		result.Set_denominator(((Drob1.Get_denominator() * Drob2.Get_numerator()) + (Drob2.Get_denominator() * Drob1.Get_numerator())));
		result.Set_integer(0);
		return result;
	}

}

void main()
{
	Fraction IND1;
	setlocale(LC_ALL, "");
	cout <<R"(Эта программа работает с дробями.
			  Введите дробь = )" << endl;
	cin >> IND1;
	IND1.Print();
	IND1.to_proper();
	IND1.to_improper();
	cout << "\nДля ввода 2 дроби нажмите любую клавишу...";
	_getch();
	Fraction IND2; 
	system("cls");
	cout << "Вторая дробь = ";
	cin >> IND2;
	cout << "Дробь №1 = "; IND1.Print();
	cout << "Дробь №2 = "; IND2.Print();
	IND1 = IND1 + IND2;
	IND1.to_improper();
	IND1.Print();

	_getch();
}
