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
        cout<<length<<endl;
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
    friend istream& operator>>(istream& inputStream, String & s); // Наладга дружбы межды приватным value и operator>>. Operator>> объявляется в публичной секции
    String& operator=(const String& other) // Перегрузка оператора присвоения
    {
        if (this != &other) {
            delete[] value;
            length = other.length;
            value = new char[length+1];
            for (int i=0; i<=length; i++) {
                value[i]=other.value[i];
            }
        }
        return *this;
    }
    String operator-() const // Перегрузка оператора унарного минуса
    {
        String ret;
        ret.length = length;
        delete[] ret.value;
        ret.value = new char[length+1];
        for (int i=0; i<length; i++) {
            ret.value[i] = value[length-i-1];
        }
        ret.value[length] = 0;
        return ret;
    }
    ~String() // Деструктор. Освобождает динамическую память
    {
        delete[] value;
    }
};
ostream& operator<<(ostream& outputStream, const String & s) // Перегруженный оператор для вывода строки в поток. Сдвиг бинарный
{
    return outputStream << s.value;
}
istream& operator>>(istream& inputStream, String & s) // Перегруженный оператор для ввода значения строки из потока ввода
{
    inputStream >> s.value;
    for (int i=0; s.value[i] != '\0'; i++) // Вычисление длины введенной строки
        s.length+=1;
    return inputStream;
}
int main(int argc, char **argv) // Проверка возможностей оператора
{
    cout << "Введите строку 1" << endl;
    String stroka1;
    cin >> stroka1;
    cout << "Введите строку 2" << endl;
    String stroka2;
    cin >> stroka2;
    stroka2 = stroka1;
    cout << "Вывод присвоенной строки" << endl;
    cout << stroka2 << endl;
    cout << "Вывод обратной строки" << endl;
    cout << -stroka2 << endl;
    return 0;
}

