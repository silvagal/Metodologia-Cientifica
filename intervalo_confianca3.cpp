#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include "hypergeometric.hpp"
#include <boost/math/distributions/normal.hpp>

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

std::pair<double,double> t_distribution_confidence_interval(const std::vector<double>& data, double& alpha){
    int n = data.size();
    double data_mean,data_std_dev, p_value, t_stu, p1, p2;
    std::pair<double, double> points;

    data_mean = mean(data);
    data_std_dev = std_dev(data);
    p_value = 1 - alpha/2;
    t_stu = boost::math::quantile(data, alpha); // 95% of distribution is below
    p1 = data_mean - (t_stu * data_std_dev/sqrt(n));
    p2 = data_mean + (t_stu * data_std_dev/sqrt(n));

    points.first = p1;
    points.second = p2;

    return points;
}

int main() {
    std::vector<double> data = {18.45, 14.58, 2.51, 11.54, 17.82, 10.33, 18.59, 3.05, 1.69, 8.97, 14.5, 10.28, 17.04,
                              15.57, 1.39};
    double alpha = 0.05;
    std::pair<double, double> points;
    points = t_distribution_confidence_interval(data, alpha);
    std::cout << "p1: " << points.first << "p2: " << points.second;
    return 0;
}