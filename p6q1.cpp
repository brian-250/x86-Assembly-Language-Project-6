// P6Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
float pnt_f = 0.5;
float two = 2.0;

float a = 0;
float b = 0;
float c = 0;
float h = 0;

// Used variable 'l' since it wouldn't let me use 'length'
float l = 0;
float width = 0;

float t_area = 0;
float t_perimeter = 0;

float rec_area = 0;
float rec_perimeter = 0;

void question() {
    std::cout << "Enter the values of a,b,c, and h for the triangle: ";
    std::cin >> a >> b >> c >> h;

    std::cout << "Enter the length and the width of the rectangle: ";
    std::cin >> l >> width;
}

void Display() {
    std::cout << "Triangle" << std::endl;
    std::cout << "      Area.........................................." << t_area << std:: endl;
    std::cout << "      Perimeter................................" << t_perimeter << std:: endl;
    std::cout << "Rectangle" << std::endl;
    std::cout << "      Area........................................" << rec_area << std::endl;
    std::cout << "      Perimeter ..............................." << rec_perimeter << std:: endl;
}

int main()
{
    _asm {
        call question;
        fld c;
        fld h;
        fmul;
        fld pnt_f;
        fmul;
        fstp t_area;

        fld a;
        fld b;
        fadd;
        fld c;
        fadd;
        fstp t_perimeter;

        fld l;
        fld width;
        fmul;
        fstp rec_area;

        fld width;
        fld l;
        fadd;
        fld two;
        fmul;
        fstp rec_perimeter;

        call Display;
    }
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
