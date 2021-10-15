#include "panels.h"

void adminPanelWithoutRegistr(account* arr, int count, account current_user) {
    int mode;
    bool flag = true;
    while (flag) {
        cout << "С возвращением, " << current_user.login << "!" << endl;
        cout << "Меню:\n     1 - Посмотреть информацию об аккаунтах в базе\n     2 - Удалить аккаунт из базы\n     3 - Изменить информацию об аккаунте\n     4 - Добавить аккаунт в базу\n     5 - Панель пользователя" << endl;
        cout << "     0 - Выйти из аккаунта\nДействие: ";
        mode = checkNumeric();
        switch (mode) {
        case 0: system("cls"); flag = false; break;
        case 1:system("cls"); viewAccountInfo(arr, count); system("pause"); system("cls"); break;
        case 2:system("cls"); deleteAccontFromData(arr, count, current_user); break;
        case 3:system("cls"); editInfoaCC(arr, count, current_user); system("cls"); break;
        case 4:system("cls"); addAccountInArr(arr, count); system("cls"); break;
        case 5: system("cls"); userPanel(current_user); system("cls"); break;
        default: cout << "Некорректное значение. Повторите ввод" << endl; system("pause"); break;
        }
    }
    writeArrInFile(arr, count);
    delete[]arr;
}

void adminPanelWithRegistr(account* arr, int count, account current_user) {
    int mode;
    bool flag = true;
    while (flag) {
        cout << "С возвращением, " << current_user.login << "!" << endl;
        cout << "Меню:\n     1 - Посмотреть информацию об аккаунтах в базе\n     2 - Удалить аккаунт из базы\n     3 - Изменить информацию об аккаунте\n     4 - Добавить аккаунт в базу" << endl;
        cout << "     5 - У ВАС НОВЫЕ ЗАПРОСЫ НА РЕГИСТРАЦИЮ!\n     6 - Панель пользователя\n     0 - Выйти из аккаунта\nДействие: ";
        mode = checkNumeric();
        switch (mode) {
        case 0: system("cls"); flag = false; break;
        case 1:system("cls"); viewAccountInfo(arr, count); system("pause"); system("cls"); break;
        case 2:system("cls"); deleteAccontFromData(arr, count, current_user); break;
        case 3:system("cls"); editInfoaCC(arr, count, current_user); system("cls"); break;
        case 4:system("cls"); addAccountInArr(arr, count); system("cls"); break;
        case 5:system("cls"); registerNewAccount(arr, count); break;
        case 6: system("cls"); userPanel(current_user); system("cls"); break;
        default: cout << "Некорректное значение. Повторите ввод" << endl; system("pause"); break;
        }
    }
    writeArrInFile(arr, count);
    delete[]arr;
}

void userPanel(account current_user) {
    int countOfProduction = getCountOfProduction();
    production* arr = new production[countOfProduction];
    getArrOfProduction(arr, countOfProduction);
    decodeProductionName(arr, countOfProduction);
    bool flag = true;
    int mode;
    string buffer;
    while (flag) {
        cout << "-----Добро пожаловать, " << current_user.login << "-----" << endl;
        cout << "Меню:\n     1 - посмотреть информацию обо всём товаре\n     2 - добавить продукцию в файл\n     3 - удалить запись о продукции из файла\n     4 - измнить информацию в записи\n     5 - индивидуальное задание\n     6 - отсортировать массив\n     7 - поиск\n     0 - выйти из аккаунта\nДействие: ";
        mode = checkNumeric();
        switch (mode) {
        case 1: system("cls"); showArrOfProd(arr, countOfProduction); system("pause"); system("cls"); break;
        case 2: addProdInfoInArr(arr, countOfProduction); break;
        case 3: deleteProdInfo(arr, countOfProduction); break;
        case 4: editProdInfo(arr, countOfProduction); break;
        case 5: individualTask(arr, countOfProduction); break;
        case 6: sortArr(arr, countOfProduction); break;
        case 7: searchInProducton(arr, countOfProduction); break;
        case 0: flag = false; break;
        }
    }
    codeProductionName(arr, countOfProduction);
    writeProdArrInFile(arr, countOfProduction);
    delete[]arr;
    system("cls");
}