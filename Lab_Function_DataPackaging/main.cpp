#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int RANGE = 18; // Диапазон значений (0-17)
int SIZE; // Размер массива


void packArray(int arr[], int size, int compressed[]) {
    fill(compressed, compressed + RANGE, 0); // Инициализируем массив compressed нулями
    for (int i = 0; i < size; ++i) compressed[arr[i]]++; // Увеличиваем счетчик для числа arr[i]
}


void unpackArray(int compressed[], int arr[], int &size) {
    size = 0; // Инициализируем размер восстановленного массива нулем
    for (int num = 0; num < RANGE; ++num) { // Проходим по всем возможным значениям (0-17)
        for (int i = 0; i < compressed[num]; ++i) arr[size++] = num; // Записываем число num и увеличиваем размер массив

    }
}

int main() {

    cout << "Write Size Array" << endl;
    cin >> SIZE;

    srand(time(0)); // Инициализируем генератор случайных чисел

    int originalArray[SIZE]; // Исходный массив
    int index = 0; // Текущий индекс в массиве

    // Заполняем массив упорядоченными значениями
    for (int num = 0; num < RANGE; ++num) {
        // Генерируем случайное количество повторений для текущего числа
        int count = rand() % 200; // От 1 до 200 повторений

        while((index + count) > SIZE) { // пока выходим выходим за пределы массива
            count = SIZE - index; // Уменьшаем количество повторений
        }
        for (int i = 0; i < count; ++i) {
            originalArray[index++] = num; // Заполняем массив
        }
        if (index >= SIZE) break; // Если массив заполнен, выходим
    }

    // Выводим первые 20 элементов для проверки
    cout << "First 20 elements ORIGINAL array: ";
    for (int i = 0; i < 100; ++i) {
        cout << originalArray[i] << " ";
    }
    cout << endl;

    int compressed[RANGE]; // Массив для хранения сжатых данных
    int restoredArray[SIZE]; // Массив для восстановления данных
    int restoredSize; // Размер восстановленного массива

    // Упаковываем данные
    packArray(originalArray, SIZE, compressed);

    // Выводим сжатый массив
    cout << "Compressed array: ";
    for (int count : compressed) {
        cout << count << " ";
    }
    cout << endl;

    // Распаковываем данные
    unpackArray(compressed, restoredArray, restoredSize);

    // Выводим первые 20 элементов восстановленного массива для проверки
    cout << "First 20 elements RESTORED array: ";
    for (int i = 0; i < 100; ++i) {
        cout << restoredArray[i] << " ";
    }
    cout << endl;

    return 0;
}