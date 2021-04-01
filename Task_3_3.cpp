#include <iostream>
#include <string>
using namespace std;
class String // Создание класса
{
private: // Секция приват, для объявления атрибутов
    char *value; // value - строка
    int length;  // length - длина строки
public: // Публичная секция
    String() // Дефолтный конструктор, инициализирует нулевыми значениями
    {
        value = new char[1];
        length = 0;
        value[0] = '\0';
    }
    String(string str) // Инициализация Си-строкой
    {
        length = str.length();
        value = new char[length+1];
        for (int i=0; i<=length; i++) {
            value[i]=str[i];
        }
    }
    String(const String& s) // Конструктор копирования, инициализирует экземпляры класса значениями другого экземпляра того же класса
    {
        length=s.length;
        value = new char[length+1];
        for (int i=0; i<=length; i++) {
            value[i]=s.value[i];
        }
    }
    friend ostream& operator<<(ostream& outputStream, const String & s); // Наладга дружбы межды приватным value и operator<<. Operator<< объявляется в публичной секции

    ~String() // Деструктор. Освобождает динамическую память
    {
        delete[] value;
    }
};
ostream& operator<<(ostream& outputStream, const String & s) // Перегруженный оператор для вывода строки в поток. Сдвиг бинарный
{
    return outputStream << s.value;
}
int main(int argc, char **argv) // Проверка рабоспособности конструктора
{
    cout << "Введите строку:" << endl;
    string example1;
    cin >> example1;
    String a(example1);
    cout << "Вывод строки, инициализированной коструктором: " << endl;
    cout << a << endl;
    return 0;
}
