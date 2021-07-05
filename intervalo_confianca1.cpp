#include <iostream>
#include <math.h>

double normal_distribution_cdf(double x, double mu, double std_dev){
    return 0.5 * (1 + erf( (x - mu)/(std_dev * sqrt(2))));
}

double normal_distribution_cdf(double x){
    double mu = 0.0;
    double std_dev = 1.0;
    return 0.5 * (1 + erf( (x - mu)/(std_dev * sqrt(2))));
}

double normal_distribution_cdf(double x1, double x2, double mu, double std_dev){
    return normal_distribution_cdf(x2, mu, std_dev) - normal_distribution_cdf(x1, mu, std_dev);
}

double normal_distribution_cdf(double x1, double x2){
    return normal_distribution_cdf(x2) - normal_distribution_cdf(x1);
}

int main() {
    double prob, p1, p2 = -1.0, mu = -1.0, std_dev;
    int resp;
    std::cout << "Você possui a média e o desvio padrão do conjunto? \n (DIGITE 1 CASO AFIRMATIVO E 0 CASO CONTRÁRIO)\n";
    std::cin >> resp;
    if (resp){
       std::cout << "\nDigite a média: ";
       std::cin >> mu;
       std::cout << "\nDigite o desvio padrão ";
       std::cin >> std_dev;
    }
    std::cout << "Digite: \n 0 - caso queira descobrir a probabilidade de um ponto estar entre menos infinito e um ponto\n"
                 "1 - caso queira descobrir a probabilide de um ponto estar entre dois pontos conhecidos\n";
    std::cin >> resp;
    std::cout << "\nDigite o ponto: ";
    std::cin >> p1;
    if (resp){
        std::cout << "\nDigite o outro ponto: ";
        std::cin >> p2;
    }
    if (p2 == -1 && mu != -1)
        prob = normal_distribution_cdf(p1, mu, std_dev);
    else if (p2 == -1 && mu == -1)
        prob = normal_distribution_cdf(p1);
    else if (p2 != -1 && mu != -1)
        prob = normal_distribution_cdf(p1, p2, mu, std_dev);
    else
        prob = normal_distribution_cdf(p1, p2);

    std::cout << "\n Probabilidade: " << prob;

    return 0;
}