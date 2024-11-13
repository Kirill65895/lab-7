#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    
    fstream inFile("avova.txt");
    if (!inFile.is_open()){
        cout << "Ошибка чтения" << endl;
        return 1;
    }
    
    int choice;

    while (true) {
    cout << "1) Найти кол-во букв" << endl;
    cout << "2) Найти двубуквенные сочетания" << endl;
    cout << "3) Завершить программу" << endl;
    cout << "  Ваш выбор: ";
    cin >> choice;

    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Команды не существует" << endl;
        cout << endl;
        continue;
    }

    switch (choice) {
    case 1: {
    char ch;
    char findCh;
    int findChCounter = 0;

    cout << "Введите букву ";
    cin >> findCh;

    while (inFile.get(ch)) {
        if (findCh == ch) {
            ++findChCounter;
        }
    }
    cout << "Количество букв " << findCh << " " << findChCounter << endl;
    cout << endl;
    cout << endl;
    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    break;
    }

    case 2: {
    string letter;
    string findTwoLetter;
    int findTwoLetterCounter = 0;

    cout << "Введите сочетание букв ";
    cin >> findTwoLetter;


    while (getline(inFile, letter)) {
        size_t pos = 0;
      
        while ((pos = letter.find(findTwoLetter, pos)) != (string::npos)) {
            ++findTwoLetterCounter;
            pos += findTwoLetter.length();
        }
    }

    cout << "Количество сочетаний букв " << findTwoLetter << " " << findTwoLetterCounter << endl;
    cout << endl;
    inFile.clear();
    inFile.seekg(0, ios::beg);

    break;
    }

    case 3: 
        return 0;

    default:
        cout << "Неверный ввод" << endl;
        cout << endl;
        break;
    }
  }
}
