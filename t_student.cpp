#include <iostream>
#include <vector>
#include <math.h>
#include<tuple>

double mean(const std::vector<double>& data){
    double sum = 0.0;
    for (auto i:data)
        sum += i;
    return sum/data.size();
}
double variance(const std::vector<double>& data){
    double variance = 0.0;
    double d_mean = mean(data);
    for (auto i : data)
        variance += pow(i - d_mean, 2.0);
    return variance/data.size();
}

double std_dev(const std::vector<double>& data){
    return sqrt(variance(data));
}

double t_distribution_pdf(double x, int v){
    return (pow(1 + (pow(x, 2)/v), (v + 1) / (-2)) * gamma((v+1)/2))/ ((sqrt(M_PI * v) * gamma(v / 2)));
}

double t_distribution_cdf(double x, int v){
    return 0.5 * (1.0 + (x * gamma(v + 1) * hypergeometric_2f1(0.5, (v+1)/2, 1.5, pow(x, 2)/(-v))) / sqrt(M_PI * v) * gamma(v / 2) );
}

double t_distribution_cdf(double x1, double x2, int v){
    return t_distribution_cdf(x2, v) - t_distribution_cdf(x1, v);
}

void t_distribution(const std::vector<double>& x1, const std::vector<double>& x2, std::tuple<double, double>& t_student){
    double x1_mean, x2_mean, x1_variance, x2_variance, t_stu, p_value;
    int degree_freedom;
    x1_mean = mean(x1);
    x1_variance = variance(x1);
    x2_mean = mean(x2);
    x2_variance = variance(x2);
    degree_freedom = x1.size() + x2.size() - 2;
    t_stu = (x1_mean - x2_mean)/sqrt((x1_variance + x2_variance) / degree_freedom);
    p_value = t_distribution_cdf(-t_stu, degree_freedom) + (1 - t_distribution_cdf(t_stu, degree_freedom));
    std::get<0>(t_student) = t_stu;
    std::get<1>(t_student) = p_value;
}

int main() {
    std::tuple<double, double> t_student;
    std::vector<double> x1 = {3.67, 11.36, 7.85, 2.89, 16.13, 12.24, 7.18, 2.82, 14.68, 14.82, 5.67, 4.41, 13.47,
                              11.05, 4.97, 15.86, 7.59, 9.16, 12.35, 10.14};
    std::vector<double> x2 = {18.45, 14.58, 2.51, 11.54, 17.82, 10.33, 18.59, 3.05, 1.69, 8.97, 14.5, 10.28, 17.04,
                              15.57, 1.39};

    t_distribution(x1, x2, t_student);

    std::cout << "Primeiro conjunto: " << std::endl;
    for (auto i : x1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Segundo conjunto: " << std::endl;
    for (auto i : x2) {
        std::cout << i << " ";
    }
    std::cout << "\n\nt_student: " << std::get<0>(t_student) << "\np_value: " << std::get<1>(t_student) << std::endl;

    return 0;
}