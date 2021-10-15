#include "admin_functions.h"

void 


viewAccountInfo(account* arr, int count) {
    for (int i = 0; i < count; i++) {
        if (arr[i].accessLevel != 2) {
            cout << "-----������� " << i + 1 << "-----" << endl;
            cout << "�����: " << arr[i].login << endl;
            cout << "����: ";
            if (arr[i].role == 1) {
                cout << "�����(1)" << endl;
            }
            else {
                cout << "������������(0)" << endl;
            }
        }
    }
}

void deleteAccontFromData(account*& arr, int& count, account current_user) {
    viewAccountInfo(arr, count);
    int chosenAccount;
    cout << "������� ����� ������, ������� ������ ������� ��� ������� 0, ���� ������ ����� �� ����� ������: ";
    chosenAccount = checkNumericInRange(0, count);
    if (chosenAccount != 0) {
        chosenAccount--;
        if (chosenAccount != -1) {
            if (arr[chosenAccount].login == current_user.login) {
                cout << "���������� ������� �������, �� ������� �� ������ ����������. ��� �� �����" << endl;
                system("pause");
                system("cls");
            }
            else {
                deleteUserWithNumber(arr, count, chosenAccount);
                cout << "��������� �������!" << endl;
                system("pause");
                system("cls");
            }
        }
        else {
            cout << "�������� �������!" << endl;
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
        cout << "������� ����� ������, ������� ������ ���������������(0 ��� ������) : ";
        number = checkNumericInRange(0, count);
        if (number == 0) {
            flag = false;
        }
        number--;
        if (arr[number].login != current_user.login) {
            cout << "��� ������ �� ������ ��������:\n1 - �����\n2 - ������\n3 - ����\n4 - ������\n0 - ������\n��������: ";
            mode = checkNumericInRange(0, 4);
            switch (mode) {
            case 1: arr[number].login = checkForUniqueLogin(arr, count); cout << "��������� �������!" << endl; system("pause"); flag = false; break;
            case 2: cout << "������� ����� ������: "; arr[number].password = checkForEnters(); arr[number].password = sha256(arr[number].login + sha256(arr[number].login + arr[number].password)); cout << "��������� �������!" << endl; system("pause"); flag = false; break;
            case 3: cout << "������� ����� ���� (1 - �����, 0 - ������������): "; role = checkNumberCONST(0, 1); arr[number].role = role; cout << "��������� �������!" << endl; system("pause"); flag = false; break;
            case 4: cout << "������� ����� ������(0 - ������������, 1 - �������)"; arr[number].accessLevel = checkNumberCONST(0, 1); cout << "��������� �������!" << endl; system("pause"); system("cls"); flag = false; break;
            case 0: flag = false; system("pause"); system("cls"); break;
            }
        }
        else {
            cout << "������ ������������� �������, ��� ������� �� �����!" << endl;
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
    cout << "������� ������: ";
    password = checkForEnters();
    password = sha256(login + sha256(login + password));
    cout << "������� ���� (1 - �����, 0 - ������������)";
    role = checkNumberCONST(0, 1);
    arr[count - 1].login = login;
    arr[count - 1].password = password;
    arr[count - 1].role = role;
    arr[count - 1].accessLevel = 1;
    cout << "��������� �������!" << endl;
    system("pause");
}

void registerNewAccount(account*& arr, int& count) {
    cout << "-----����� ����������� ���������-----" << endl;
    int j = 0;
    int choose;
    for (int i = 0; i < count; i++) {
        if (arr[i].accessLevel == 2) {
            cout << "������ �� �����������:" << endl;
            cout << "�����: " << arr[i].login << endl;
            cout << "����: ";
            if (arr[i].role == 1) {
                cout << "�����" << endl;
            }
            else {
                cout << "������������" << endl;
            }
            cout << "�����������? (1 - ��, 2 - ���)" << endl;
            choose = checkNumberCONST(1, 2);
            if (choose == 1) {
                arr[i].accessLevel = 1;
            }
            else {
                deleteUserWithNumber(arr, count, i);
            }
        }
    }
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");
}

