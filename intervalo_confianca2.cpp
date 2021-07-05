#include <iostream>
#include <math.h>
#include "hypergeometric.hpp"

double t_distribution_pdf(double x, int v){
    return (pow(1 + (pow(x, 2)/v), (v + 1) / (-2)) * gamma((v+1)/2))/ ((sqrt(M_PI * v) * gamma(v / 2)));
}

double t_distribution_cdf(double x, int v){
    return 0.5 * (1.0 + (x * gamma(v + 1) * hypergeometric_2f1(0.5, (v+1)/2, 1.5, pow(x, 2)/(-v))) / sqrt(M_PI * v) * gamma(v / 2) );
}

double t_distribution_cdf(double x1, double x2, int v){
    return t_distribution_cdf(x2, v) - t_distribution_cdf(x1, v);
}

int main() {
    double x1, x2, v, prob;
    int resp;
    std::cout << "Digite x1: \n";
    std::cin >> x1;
    std::cout << "Digite v: \n";
    std::cin >> v;
    std::cout << "Deseja calcular a probabilidade entre 2 pontos? \n (DIGITE 1 CASO AFIRMATIVO E 0 CASO CONTRÁRIO)\n";
    std::cin >> resp;
    if (resp){
        std::cout << "Digite x2: \n";
        std::cin >> x2;
        prob = t_distribution_cdf(x1, x2, v);
    }else{
        prob = t_distribution_cdf(x1, v);
    }

    std::cout << "\n Probabilidade: " << prob;

    return 0;
}