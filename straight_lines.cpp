#include <iostream>
#include <math.h>
void main()
{

    float m1, c1, m2, c2;
    float x1, y1, x2, y2;
    float dx, dy;
    float intersection_X, intersection_Y;
    std::cout << " Program to find the intersecting point of two lines:\n";
    std::cout << "Enter Line1 - X1: ";

    std::cin >> x1;
    std::cout << "Enter Line1 - Y1: ";
    std::cin >> y1;
    std::cout << "Enter Line1 - X2: ";
    std::cin >> x2;
   std::cout << "Enter Line1 - Y2: ";

    std::cin >> y2;
    dx = x2 - x1;

    dy = y2 - y1;
    m1 = dy / dx;

    // y = mx + c

    // intercept c = y - mx

    c1 = y1 - m1 * x1; // which is same as y2 - slope * x2

    std::cout << "Enter Line2 - X1: ";

    std::cin >> x1;

 

    std::cout << "Enter Line2 - Y1: ";

    std::cin >> y1;

 

    std::cout << "Enter Line2 - X2: ";

    std::cin >> x2;

 

    std::cout << "Enter Line2 - Y2: ";

    std::cin >> y2;

 

    dx = x2 - x1;
    dy = y2 - y1;
    m2 = dy / dx;
    c2 = y2 - m2 * x2; // which is same as y2 - slope * x2
    std::cout << "Equation of line1: ";

    std::cout << m1 << "X " << ((c1 < 0) ? ' ' : '+') << c1 << "\n";

    std::cout << "Equation of line2: ";

    std::cout << m2 << "X " << ((c2 < 0) ? ' ' : '+') << c2 << "\n";

 

    if( (m1 - m2) == 0)

        std::cout << "No Intersection between the lines\n";

    else

    {

        intersection_X = (c2 - c1) / (m1 - m2);
        intersection_Y = m1 * intersection_X + c1;
        std::cout << "Intersecting Point: = ";

        std::cout << intersection_X;

        std::cout << ",";

        std::cout << intersection_Y;

        std::cout << "\n";

    }
