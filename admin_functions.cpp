#include "admin_functions.h"

void 


viewAccountInfo(account* arr, int count) {
    for (int i = 0; i < count; i++) {
        if (arr[i].accessLevel != 2) {
            cout << "-----Аккаунт " << i + 1 << "-----" << endl;
            cout << "Логин: " << arr[i].login << endl;
            cout << "Роль: ";
            if (arr[i].role == 1) {
                cout << "Админ(1)" << endl;
            }
            else {
                cout << "Пользователь(0)" << endl;
            }
        }
    }
}

void deleteAccontFromData(account*& arr, int& count, account current_user) {
    viewAccountInfo(arr, count);
    int chosenAccount;
    cout << "Введите номер записи, которую хотите удалить или введите 0, если хотите выйти из этого режима: ";
    chosenAccount = checkNumericInRange(0, count);
    if (chosenAccount != 0) {
        chosenAccount--;
        if (chosenAccount != -1) {
            if (arr[chosenAccount].login == current_user.login) {
                cout << "Невозможно удалить аккаунт, на котором вы сейчас находитесь. Это же глупо" << endl;
                system("pause");
                system("cls");
            }
            else {
                deleteUserWithNumber(arr, count, chosenAccount);
                cout << "Выполнено успешно!" << endl;
                system("pause");
                system("cls");
            }
        }
        else {
            cout << "Отменено успешно!" << endl;
            system("pause");
            system("cls");
        }
    }
}

void editInfoaCC(account* arr, int count, account current_user) {
    viewAccountInfo(arr, count);
    bool flag = true;
    string login, password;
    int role;
    int number, mode;
    while (flag) {
        cout << "Введите номер записи, которую хотите отредактировать(0 для отмены) : ";
        number = checkNumericInRange(0, count);
        if (number == 0) {
            flag = false;
        }
        number--;
        if (arr[number].login != current_user.login) {
            cout << "Что именно вы хотите изменить:\n1 - Логин\n2 - Пароль\n3 - Роль\n4 - Статус\n0 - Отмена\nДействие: ";
            mode = checkNumericInRange(0, 4);
            switch (mode) {
            case 1: arr[number].login = checkForUniqueLogin(arr, count); cout << "Выполнено успешно!" << endl; system("pause"); flag = false; break;
            case 2: cout << "Введите новый пароль: "; arr[number].password = checkForEnters(); arr[number].password = sha256(arr[number].login + sha256(arr[number].login + arr[number].password)); cout << "Выполнено успешно!" << endl; system("pause"); flag = false; break;
            case 3: cout << "Введите новую роль (1 - Админ, 0 - Пользователь): "; role = checkNumberCONST(0, 1); arr[number].role = role; cout << "Выполнено успешно!" << endl; system("pause"); flag = false; break;
            case 4: cout << "Введите новый статус(0 - заблокирован, 1 - активен)"; arr[number].accessLevel = checkNumberCONST(0, 1); cout << "Выполнено успешно!" << endl; system("pause"); system("cls"); flag = false; break;
            case 0: flag = false; system("pause"); system("cls"); break;
            }
        }
        else {
            cout << "Нельзя редактировать аккаунт, под которым вы вошли!" << endl;
            system("pause");
        }
    }
}

void addAccountInArr(account*& arr, int& count) {
    string login, password;
    int role;
    int new_count = count + 1;
    account* new_arr = new account[new_count];
    for (int i = 0; i < count; i++) {
        new_arr[i] = arr[i];
    }
    delete[]arr;
    arr = new_arr;
    count = new_count;
    login = checkForUniqueLogin(arr, count);
    cout << "Введите пароль: ";
    password = checkForEnters();
    password = sha256(login + sha256(login + password));
    cout << "Введите роль (1 - админ, 0 - пользователь)";
    role = checkNumberCONST(0, 1);
    arr[count - 1].login = login;
    arr[count - 1].password = password;
    arr[count - 1].role = role;
    arr[count - 1].accessLevel = 1;
    cout << "Выполнено успешно!" << endl;
    system("pause");
}

void registerNewAccount(account*& arr, int& count) {
    cout << "-----Режим регистрации аккаунтов-----" << endl;
    int j = 0;
    int choose;
    for (int i = 0; i < count; i++) {
        if (arr[i].accessLevel == 2) {
            cout << "Запрос на регистрацию:" << endl;
            cout << "Логин: " << arr[i].login << endl;
            cout << "Роль: ";
            if (arr[i].role == 1) {
                cout << "админ" << endl;
            }
            else {
                cout << "пользователь" << endl;
            }
            cout << "Подтверидть? (1 - да, 2 - нет)" << endl;
            choose = checkNumberCONST(1, 2);
            if (choose == 1) {
                arr[i].accessLevel = 1;
            }
            else {
                deleteUserWithNumber(arr, count, i);
            }
        }
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}

