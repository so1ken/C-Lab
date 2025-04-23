/*
 * #include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
int main() {
    // cyrillic support
    setlocale(LC_ALL, "Russian");

    // Function value
    wcout << "Fuction" << endl;
    float f, x, first;

    wcout << "Write first point (<4 and >0):";
    cin >> first; // Первая точка

    for (int i = 0; i <= 9; i++) {
        // Делим на 9, так как мы знаем первую
        x = first + ((4 - first) / 9) * i;
        f = sin(x) / x;
        cout << "x: " << x << endl << "value: " << f << endl;
    }

    wcout << "Fibonacci" << endl;
    int fin, first_, second, sum, temp, volume;

    wcout << "Write the border" << endl;
    cin >> fin;
    first_ = 0; second = 1;
    sum = 1; // Так как ищем со второго элемента
    volume = 2;
    if(fin > 1){
        while(sum < fin){
            temp = first_ + second;
            first_ = second;
            second = temp;

            sum += temp;
            volume += 1;
        }
    }else if (fin == 1){
        sum = 1;
    } else sum = 0;
    cout << "Kolichestvo elementov: "<< volume << endl << "Summa fibonacci: "<< sum;
    return 0;
}
