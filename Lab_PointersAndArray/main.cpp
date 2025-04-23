#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
};
int main() {
    int size;
    cout << "Write size for the dinamic array"<< endl;
    cin >> size;

    int first[10];

    int second[10];
    int* arr = second;

    int* third = new int[size];

    int* fours = new int[size];
    int* pr = fours;

    cout << "First array"<<endl;
    for(int i = 0; i < 10; i ++){
        first[i] = pow(i, 2);
        cout << first[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Second array"<<endl;
    for(int i = 0; i < 10; i++){
        *(arr + i) = pow(i, 2);
        cout << *(arr + i) << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Third dinamic array"<<endl;
    for(int i = 0; i < size; i ++){
        second[i] = pow(i, 2);
        cout << second[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Fours dinamic array"<<endl;
    for(int i = 0; i < size; i++){
        *(pr + i) = pow(i, 2);
        cout << *(pr + i) << " ";
    }
    cout << endl;
    cout << endl;
    cout <<"-----------------------------------------------" << "\n\n";

    cout << "Write size for List<>"<<"\n";
    cin >> size;

    Node* head = new Node{1, nullptr}; // Первый элемент списка (data = 0)
    Node* current = head;              // Текущий узел

    // Создаем оставшиеся узлы, начиная с 1
    for (int i = 2; i < size; i++) {
        current -> next = new Node{i}; // Создаем узел с data = i
        current = current->next;              // Переход к следующему узлу
    }

    // Вывод списка
    cout << "Spisok 4 zadanie:" << endl;
    current = head;
    while(current) {
        cout << current->data << " -> ";
        current = current->next;
    }

}