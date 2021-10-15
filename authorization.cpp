#include "authorization.h"

account logging(account* arr, int count) {
    string login, password;
    while (true) {
        cout << "������� �����: ";
        cin >> login;
        cout << "������� ������: ";
        password = enterPassword();
        password = sha256(login + sha256(password + login));
        for (int i = 0; i < count; i++) {
            if (arr[i].login == login) {
                if (arr[i].password == password) {
                    system("cls");
                    return arr[i];
                }
            }
        }
        system("cls");
        cout << "������������ ����. ���������" << endl;
    }
}

void askForRegistration() {
    int count_of_accounts;
    count_of_accounts = getCountOfAccounts();
    account* arr_of_accounts = new account[count_of_accounts];
    getArrOfAccounts(arr_of_accounts, count_of_accounts);
    string login, password;
    login = checkForUniqueLogin(arr_of_accounts, count_of_accounts);
    cout << "������� ������: ";
    password = checkForEnters();
    password = sha256(login + sha256(password + login));
    cout << "������� �������� ���� (1 - �����, 0 - ������������): ";
    int role;
    role = checkNumberCONST(0, 1);
    delete[]arr_of_accounts;
    ofstream file(FILE_DATA_ACCOUNTS, ios::app);
    file << login << " " << password << " " << role<<" " << "2" << endl;
    file.close();
    cout << "��������� �������! �������� ������������� ����������� �� ��������������!" << endl;
    system("pause");
    system("cls");
}
