#include "checks.h"

string enterPassword() {
    string password;
    char buff;
    int count = 0;
    while (true) {
        buff = _getch();
        if (buff == 13) {
            break;
        }
        else if (buff == 8) {
            if (count != 0) {
                cout << (char)8 << ' ' << char(8);
                password.erase(password.length() - 1);
                count--;
            }
        }
        else {
            cout << '*';
            password += buff;
            count++;
        }
    }
    return password;
}

string checkForEnters() {
    string buffer;
    char buff;
    int count = 0;
    while (true) {
        buff = _getch();
        if (buff == 13) {
            break;
        }
        else if (buff == 8) {
            if (count != 0) {
                cout << (char)8 << ' ' << char(8);
                buffer.erase(buffer.length() - 1);
                count--;
            }
        }
        else if (buff != 32) {
            cout << buff;
            buffer += buff;
            count++;
        }
    }
    cout << endl;
    return buffer;
}

int checkNumeric() {
    int number;
    while (true) {
        cin >> number;
        if (cin.get() != '\n') {
            cout << "Некорректный ввод. Повторите" << endl;
            cin.clear();
            cin.ignore(81, '\n');
        }
        else {
            return number;
        }
    }
}

int checkNumberCONST(int a, int b) {
    int number;
    while (true) {
        cin >> number;
        if (cin.get() != '\n') {
            cout << "Некорректный ввод. Повторите" << endl;
            cin.clear();
            cin.ignore(81, '\n');
        }
        else if (number != a && number != b) {
            cout << "Некорректный ввод. Повторите" << endl;
        }
        else {
            return number;
        }
    }
}

int checkNumberCONST(int a, int b, int c) {
    int number;
    while (true) {
        cin >> number;
        if (cin.get() != '\n') {
            cout << "Некорректный ввод. Повторите" << endl;
            cin.clear();
            cin.ignore(81, '\n');
        }
        else if (number != a && number != b && number != c) {
            cout << "Некорректный ввод. Повторите" << endl;
        }
        else {
            return number;
        }
    }
}

int checkNumericInRange(int a, int b) {
    int number;
    while (true) {
        cin >> number;
        if (cin.get() != '\n') {
            cout << "Некорректный ввод. Повторите" << endl;
            cin.clear();
            cin.ignore(81, '\n');
        }
        else if (number < a || number > b) {
            cout << "Некорректный ввод. Повторите" << endl;
        }
        else {
            return number;
        }
    }
}

string checkForUniqueLogin(account* arr, int count) {
    string login;
    bool flag = false;
    system("cls");
    while (true) {
        cout << "Введите логин: ";
        login = checkForEnters();
        for (int i = 0; i < count; i++) {
            if (login == arr[i].login) {
                flag = true;
            }
        }
        if (flag == false) {
            return login;
        }
        else {
            system("cls");
            cout << "Такой логин уже присутствует в базе. Повторите ввод" << endl;
            flag = false;
        }
    }
}

string enterProdName() {
    string buffer;
    char buff;
    int count = 0;
    while (true) {
        buff = _getch();
        if (buff == 13) {
            break;
        }
        else if (buff == 8) {
            if (count != 0) {
                cout << (char)8 << ' ' << char(8);
                buffer.erase(buffer.length() - 1);
                count--;
            }
        }
        else if (buff != 95) {
            cout << buff;
            buffer += buff;
            count++;
        }
    }
    if (buffer[buffer.length() - 2] == ' ') {
        while ((buffer[buffer.length() - 1]) != ' ') {
            buffer.erase(buffer.length() - 1);
        }
    }
    cout << endl;
    return buffer;
}

int enterDay(int month, int year) {
    int day;
    bool flag = true;
    if (year % 4 == 0) {
        switch (month) {
        case 12: case 1: case 3: case 5: case 7: case 9: case 11: day = checkNumericInRange(1, 31); break;
        case 4: case 6: case 8: case 10: day = checkNumericInRange(1, 30); break;
        case 2: day = checkNumericInRange(1, 29); break;
        }
    }
    else {
        switch (month) {
        case 12: case 1: case 3: case 5: case 7: case 9: case 11: day = checkNumericInRange(1, 31); break;
        case 4: case 6: case 8: case 10: day = checkNumericInRange(1, 30); break;
        case 2: day = checkNumericInRange(1, 28); break;
        }
    }
    return day;
}

string enterTextInfo() {
    string buffer;
    char buff;
    int count = 0;
    while (true) {
        buff = _getch();
        if (buff == 13) {
            break;
        }
        else if (buff == 8) {
            if (count != 0) {
                cout << (char)8 << ' ' << char(8);
                buffer.erase(buffer.length() - 1);
                count--;
            }
        }
        else if (buff != 32 && !(buff >= 48 && buff <= 57)) {
            cout << buff;
            buffer += buff;
            count++;
        }
    }
    cout << endl;
    return buffer;
}