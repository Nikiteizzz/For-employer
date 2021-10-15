#include "work_with_arr_and_file.h"

int getCountOfAccounts() {
    ifstream file(FILE_DATA_ACCOUNTS, ios::in);
    if (!file.is_open()) {
        cout << "При открытии файла возникли проблемы. Проверьте наличие файла: " << FILE_DATA_ACCOUNTS << endl;
        return -1;
    }
    string buffer;
    int count = 0;
    while (getline(file, buffer)) {
        count++;
    }
    file.close();
    return count;
}

void getArrOfAccounts(account* arr, int count) {
    ifstream file(FILE_DATA_ACCOUNTS, ios::in);
    for (int i = 0; i < count; i++) {
        file >> arr[i].login >> arr[i].password >> arr[i].role >> arr[i].accessLevel;
    }
    file.close();
}

void writeArrInFile(account* arr, int count) {
    ofstream file(FILE_DATA_ACCOUNTS, ios::out | ios::trunc);
    for (int i = 0; i < count; i++) {
        file << arr[i].login << " " << arr[i].password << " " << arr[i].role << " " << arr[i].accessLevel << endl;
    }
    file.close();
}

int getCountOfProduction() {
    ifstream file(FILE_DATA_PRODUCTION, ios::in);
    int count = 0;
    if (file.is_open()) {
        string buffer;
        while (getline(file, buffer)) {
            count++;
        }
    }
    return count;
}

void getArrOfProduction(production* arr, int count) {
    ifstream file(FILE_DATA_PRODUCTION, ios::in);
    for (int i = 0; i < count; i++) {
        file >> arr[i].date.day >> arr[i].date.month >> arr[i].date.year >> arr[i].number_of_workshop >> arr[i].count_of_production >> arr[i].worker.surname_of_worker >> arr[i].worker.name_of_worker >> arr[i].worker.patronymic_of_worker >> arr[i].name_of_production;
    }
    file.close();
}

void writeProdArrInFile(production* arr, int count) {
    ofstream file(FILE_DATA_PRODUCTION, ios::trunc | ios::out);
    for (int i = 0; i < count; i++) {
        file << arr[i].date.day << " " << arr[i].date.month << " " << arr[i].date.year << " " << arr[i].number_of_workshop << " " << arr[i].count_of_production << " " << arr[i].worker.surname_of_worker << " " << arr[i].worker.name_of_worker << " " << arr[i].worker.patronymic_of_worker << " " << arr[i].name_of_production << endl;
    }
    file.close();
}

void deleteUserWithNumber(account*& arr, int& count, int chosenAccount) {
    for (int i = chosenAccount; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
}

void addAdminAccount() {
    ofstream file(FILE_DATA_ACCOUNTS, ios::out);
    file << "admin 324c0f8e73cb16614fed0add7792ac958d5d3162428ca21b359015f48dbb522e 1 1" << endl;
    file.close();
}

bool checkRegRequest(account* arr, int count) {
    bool flag = false;
    for (int i = 0; i < count; i++) {
        if (arr[i].accessLevel == 2) {
            flag = true;
        }
    }
    return flag;
}
