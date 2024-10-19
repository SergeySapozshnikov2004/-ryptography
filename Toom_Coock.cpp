#include "Polynom_2/Polynom.cpp"
#include <iostream>
#include <algorithm>
#include <cmath>

std::vector<long double> splitting_digits(int a, int b)
{       
    std::vector<long double> a_r;

    while (a != 0)
    {
        a_r.push_back(a % b);
        a /= b;
    }

    std::reverse(a_r.begin(), a_r.end());   
    return a_r;
}

std::vector<long double> difference_vector(std::vector<long double> input_vec)
{
    for(size_t i = 0; i < input_vec.size() - 1; ++i)
    {
        dif_vec.push_back(input_vec[i+1] - input_vec[i]);
    }   
}

std::vector<long double> newton_coefficients(std::vector<long double> w_at_point)
{
    std::vector<long double> coef;
    std::vector<long double> dif_vec;
    coef.push_back(w_at_point[0]);
    for(size_t j = 0; j < w_at_point.size(); ++j)
    {
        if (w_at_point.size() != 1)
        {
            newton_coefficients(dif_vec);
        }       
        for(size_t i = 0; i < w_at_point.size() - 1; ++i)
        {
            dif_vec.push_back(w_at_point[i+1] - w_at_point[i]);
        }
    }
}

int toom_coock(int u, int v, int b, int r)
{
    Polynom u_x = Polynom(splitting_digits(u, b));
    Polynom v_x = Polynom(splitting_digits(v, b));

    std::vector<long double> w_at_point;  
    for (size_t i = 0; i <= 2 * r; ++i)
    {
        w_at_point.push_back(u_x.value_at_point(i) * v_x.value_at_point(i));
        // std::cout << u_x.value_at_point(i) * v_x.value_at_point(i) << std::endl;
    } 

    // long double y = 0;
    // for(size_t i = 0; i < w_r.size(); ++i)
    // {
    //     y += w_r[w_r.size() - 1 - i] * pow(b, i);
    // }   
    // return int(y);
}   

int main()
{
    std::cout << "y = " << toom_coock(111, 555, 10, 2);
    return 0;                                       
}               