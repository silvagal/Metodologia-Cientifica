#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

template <class T>
void swap(std::vector<T>& a, int& v1_idx, int& v2_idx){
    T aux = a[v1_idx];
    a[v1_idx] = a[v2_idx];
    a[v2_idx] = aux;
}

template <class T>
int hoarePartition(std::vector<T>& a, int& l, int& r){
    int p = a[l], i = l, j = r + 1;
    do{
        do {
            i = i + 1;
        }while(a[i] < p);
        do {
            j = j - 1;
        }while(a[j] > p);
        swap(a, i, j);
    }while(i < j);
    swap(a, i, j);
    swap(a, l, j);
    return j;
}

template <class T>
void quickSort(std::vector<T>& a, int& l, int& r){
    if (l < r){
        int s = hoarePartition(a, l, r);
        int s1 = s - 1;
        int s2 = s + 1;
        quickSort(a, l, s1);
        quickSort(a, s2, r);
    }
}

double mean(const std::vector<double>& data){
    double sum = 0.0;
    for (auto i:data)
        sum += i;
    return sum/data.size();
}

double mode(const std::vector<double>& data){
    int count = 1, max_count = -1, mode;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data.size(); ++j) {
            if (data[i] == data[j])
                count++;
        }
        if (count > max_count) {
            max_count = count;
            mode = data[i];
        }
        count = 1;
    }
    return mode;
}

double percentile(const std::vector<double>& data, int p){
    int n = data.size();
    if (n % 2 != 0)
        return data[(double) p / 100.00 * n];
    else
        return (data[(double) p / 100.00 * n] + data[((double) p / 100.00 * n) - 1]) / 2;
}

double median(const std::vector<double>& data) {
    return percentile(data, 50);
}

std::pair<double,double> interval(const std::vector<double>& data){
    std::pair <double,double> interval;
    interval.first = data[0];
    interval.second = data[data.size() - 1];
    return interval;
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

int main() {
    std::vector<double> vet = {30, 6, 4, 14, 39, 37, 27, 29, 43, 49, 9, 11, 8, 1, 6, 13, 38, 3, 36, 23, 13, 8, 50, 23,
                               36, 32, 49, 21, 38, 31, 44, 9, 44, 40, 25, 29, 27, 20, 30, 11, 25, 9, 16, 12, 35, 10,
                               11, 8, 26, 9, 10, 9, 30, 12, 6, 27, 44, 21, 47, 36, 50, 38, 50, 21, 14, 11, 6, 35,
                               26, 42, 3, 4, 8, 3, 11, 16, 38, 17, 7, 40, 38, 34, 47, 29, 46, 12, 15, 23, 36,
                               34, 12, 2, 11, 28, 7, 7, 46, 5, 11, 7};

    int l = 0, r = vet.size() - 1;

    quickSort(vet, l, r);
    for (auto& i : vet)
        std::cout << i << " ";

    std::cout << "\nmode : " << mode(vet) << std::endl;
    std::cout << "mean : " << mean(vet) << std::endl;
    std::cout << "median : " << median(vet) << std::endl;
    std::cout << "intervalo : " << interval(vet).first << " - " << interval(vet).second << std::endl;
    std::cout << "variance : " << variance(vet) << std::endl;
    std::cout << "standard deviation : " << std_dev(vet) << std::endl;
    return 0;
}
