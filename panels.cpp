#include "panels.h"

void adminPanelWithoutRegistr(account* arr, int count, account current_user) {
    int mode;
    bool flag = true;
    while (flag) {
        cout << "� ������������, " << current_user.login << "!" << endl;
        cout << "����:\n     1 - ���������� ���������� �� ��������� � ����\n     2 - ������� ������� �� ����\n     3 - �������� ���������� �� ��������\n     4 - �������� ������� � ����\n     5 - ������ ������������" << endl;
        cout << "     0 - ����� �� ��������\n��������: ";
        mode = checkNumeric();
        switch (mode) {
        case 0: system("cls"); flag = false; break;
        case 1:system("cls"); viewAccountInfo(arr, count); system("pause"); system("cls"); break;
        case 2:system("cls"); deleteAccontFromData(arr, count, current_user); break;
        case 3:system("cls"); editInfoaCC(arr, count, current_user); system("cls"); break;
        case 4:system("cls"); addAccountInArr(arr, count); system("cls"); break;
        case 5: system("cls"); userPanel(current_user); system("cls"); break;
        default: cout << "������������ ��������. ��������� ����" << endl; system("pause"); break;
        }
    }
    writeArrInFile(arr, count);
    delete[]arr;
}

void adminPanelWithRegistr(account* arr, int count, account current_user) {
    int mode;
    bool flag = true;
    while (flag) {
        cout << "� ������������, " << current_user.login << "!" << endl;
        cout << "����:\n     1 - ���������� ���������� �� ��������� � ����\n     2 - ������� ������� �� ����\n     3 - �������� ���������� �� ��������\n     4 - �������� ������� � ����" << endl;
        cout << "     5 - � ��� ����� ������� �� �����������!\n     6 - ������ ������������\n     0 - ����� �� ��������\n��������: ";
        mode = checkNumeric();
        switch (mode) {
        case 0: system("cls"); flag = false; break;
        case 1:system("cls"); viewAccountInfo(arr, count); system("pause"); system("cls"); break;
        case 2:system("cls"); deleteAccontFromData(arr, count, current_user); break;
        case 3:system("cls"); editInfoaCC(arr, count, current_user); system("cls"); break;
        case 4:system("cls"); addAccountInArr(arr, count); system("cls"); break;
        case 5:system("cls"); registerNewAccount(arr, count); break;
        case 6: system("cls"); userPanel(current_user); system("cls"); break;
        default: cout << "������������ ��������. ��������� ����" << endl; system("pause"); break;
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
        cout << "-----����� ����������, " << current_user.login << "-----" << endl;
        cout << "����:\n     1 - ���������� ���������� ��� ��� ������\n     2 - �������� ��������� � ����\n     3 - ������� ������ � ��������� �� �����\n     4 - ������� ���������� � ������\n     5 - �������������� �������\n     6 - ������������� ������\n     7 - �����\n     0 - ����� �� ��������\n��������: ";
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