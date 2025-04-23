#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int Max_Word = 20; // Константа максимального колличества слов
    const int Max_Size = 10; // Константа Максимальной длины слова ( пока юзлес )

    string words[Max_Word]; // создаем массив для слов

    cout << "Write count words ( not more " << Max_Word << " word )"<< endl;
    int inputCount;
    cin >> inputCount; // Просим ввести колличество слов < 20. Затем записываем в переменную

    // Проверяем колличество слов
    if(inputCount <= Max_Word){
        cout << "Write words for add: "<< endl; // Записываем в массив слова
        for(int i = 0; i < inputCount; i++){
            string word;
            cin >> word;
            // Проверяем длину слова
            if(word.length() <= Max_Size) {
                words[i] = word;
            } else cout << "Error: You write a big word (NEED size < 10)"<< endl;
        }
        // Выводим только четные слова, как просят в условии
        for(int i = 1; i < inputCount; i = i + 2){
            cout << "Even Words, number - "<< i + 1 << " "<< words[i] << endl;
        }
    } else cout << "Error: You write not INCORRECT quantity words" << endl;

}