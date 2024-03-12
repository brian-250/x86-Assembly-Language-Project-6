#include <iostream>
#include <iomanip>

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
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "      Triangle" << std::endl;
    std::cout << "              Area.........................................." << t_area << std:: endl;
    std::cout << "              Perimeter....................................." << t_perimeter << std:: endl;
    std::cout << "      Rectangle" << std::endl;
    std::cout << "              Area.........................................." << rec_area << std::endl;
    std::cout << "              Perimeter ...................................." << rec_perimeter << std:: endl;
}

int main()
{
    _asm {
        call question;      // Call 'question()' to print question
        fld c;              // s[0] = c
        fld h;              // s[0] = c, s[1] = h
        fmul;               // st[0] = ch
        fld pnt_f;          // st[0] = pnt_f, st[1] = ch
        fmul;               // st[0] = pnt_f(ch)
        fstp t_area;        // t_area = pnt_f(ch)

        fld a;              // st[0] = a
        fld b;              // st[0] = b, st[1] = a
        fadd;               // st[0] = a+b
        fld c;              // st[0] = c, st[1] = a+b
        fadd;               // st[0] = (a+b)+c
        fstp t_perimeter;   // t_perimeter = (a+b)+c

        fld l;              // st[0] = l
        fld width;          // st[0] = width, st[1] = l
        fmul;               // st[0] = (l)(width)
        fstp rec_area;      // rec_area = (l)(width)

        fld width;          // st[0] = width
        fld l;              // st[0] = l, st[1] = width
        fadd;               // st[0] = width + l
        fld two;            // st[0] = two, st[1] = width + 1
        fmul;               // st[0] = two(width + 1)
        fstp rec_perimeter; // rec_perimeter = two(width + 1)

        call Display;       // Call 'Display()' to print output
    }
}
