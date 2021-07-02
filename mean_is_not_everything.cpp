#include <iostream>
#include <math.h>

double normal_distribution_pdf(double x, double mu, double std_dev){
    double  prob = 0.0;
    prob = (1 / sqrt(2 * M_PI * pow(std_dev, 2))) * exp((-1 * pow(x - mu, 2 )) / (2 * pow(std_dev, 2)));
    return prob;
}

double normal_distribution_pdf(double x){
    double  prob = 0.0;
    double std_dev = 1.0;
    double mu = 0.0;
    prob = (1 / sqrt(2 * M_PI * pow(std_dev, 2))) * exp((-1 * pow(x - mu, 2 )) / (2 * pow(std_dev, 2)));
    return prob;
}

int main() {
    double num, std_dev, mu;
    int ans;
    std::cout << "Digite um número" << std::endl;
    std:: cin >> num;
    std::cout << "Você possui a média e o desvio padrão do conjunto? \n(DIGITE 1 CASO AFIRMATIVO E 0 CASO CNTRÁRIO)" << std::endl;
    std::cin >> ans;
    if(ans) {
        std::cout << "Digite a média do conjunto" << std::endl;
        std::cin >> mu;
        std::cout << "Digite o desvio padrão do conjunto" << std::endl;
        std::cin >> std_dev;
        std::cout << "\nProbabilidade: " << normal_distribution_pdf(num, mu, std_dev) << std::endl;
    }
    else
        std::cout << "\nProbabilidade: " << normal_distribution_pdf(num) << std::endl;
    return 0;
}