// Vector2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Vector2.h"
using namespace::std;

int main()
{
    std::cout << "Hello World!\n"; 
	Vector2 a(1, 2);
	Vector2 b, z(6, 6);
	Vector2 c = a;
	Vector2 d; //4 6
	//cin >> d;
	// checked
	//I'll put the + if the metod is checke
	b = a + c;
	d.SetVector(7, 8);
	cout << "(1:2) -" <<a << '\n';
	cout << "(2:4) -" << b <<'\n';
	cout << "(1:2) -" << c << '\n';
	cout <<"(7:8)\ -" <<d << '\n';
	cout << "Stage 2\n";
	cout << "(6:6)/6 =" << z / 6 << "\n";
	cout << "(1:2)+(6:6) = " << a + z << "\n" << "(1:2)-(6:6) = " << a - z << '\n';
	a *= 3;
	cout << "(1:2)*=3 =" << a << '\n';
	cout << "(3:6)*(6:6) =" << a * z << '\n';
	a.SetVector(3, 4);
	cout << "length (3:4) =" << a.length() << '\n';
	c.SetVector(6, 0);
	cout << "norm (6:0) =" << c.norm() << '\n';
	cout << "reverse (3, 4) =" << -a << '\n';
	c.SetVector(6, 0);
	cout << "rotate (6, 0) = " << c.rotate(90) << "\n(6:0)= " << c;
	c.getRotated(90);
	cout << "\ngetRotated (6, 0) = " << c;




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
