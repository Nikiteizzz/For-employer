#include "user_functions.h"
#include <vector>
#include <ctime>

void addProdInfoInArr(production*& arr, int& count) {
    system("cls");
    int new_count = count + 1;
    production* new_arr = new production[new_count];
    for (int i = 0; i < count; i++) {
        new_arr[i] = arr[i];
    }
    cout << "������� ������� ��������������: ";
    new_arr[count].worker.surname_of_worker = enterTextInfo();
    cout << "������� ��� ��������������: ";
    new_arr[count].worker.name_of_worker = enterTextInfo();
    cout << "������� �������� ��������������: ";
    new_arr[count].worker.patronymic_of_worker = enterTextInfo();
    cout << "������� ���: ";
    int buffYear;
    buffYear = time(NULL) / 31536000 + 1970;
    new_arr[count].date.year = checkNumericInRange(buffYear - 60, buffYear);
    cout << "������� �����: ";
    new_arr[count].date.month = checkNumericInRange(1, 12);
    cout << "������� ����: ";
    new_arr[count].date.day = enterDay(new_arr[count].date.month, new_arr[count].date.year);
    cout << "������� ����� ����: ";
    new_arr[count].number_of_workshop = checkNumeric();
    cout << "������� �������� ������: ";
    new_arr[count].name_of_production = enterProdName();
    cout << "������� ���������� ����������� ������: ";
    new_arr[count].count_of_production = checkNumericInRange(0, 100000);
    delete[]arr;
    arr = new_arr;
    count = new_count;
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");
}

void deleteProdInfo(production*& arr, int& count) {
    showArrOfProd(arr, count);
    int choose;
    cout << endl << "������� ����� ������, ������� ������ �������(0 ��� ������): ";
    choose = checkNumericInRange(0, count);
    if (choose != 0) {
        choose--;
        for (int i = choose; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        int newCount = count - 1;
        production* new_arr = new production[newCount];
        for (int i = 0; i < newCount; i++) {
            new_arr[i] = arr[i];
        }
        delete[]arr;
        arr = new_arr;
        count = newCount;
    }
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");
}

void editProdInfo(production* arr, int count) {
    int choose;
    bool flag = true;
    system("cls");
    showArrOfProd(arr, count);
    cout << "������� ����� ������, ������� ������ ���������������: ";
    choose = checkNumericInRange(1, count);
    choose--;
    cout << "��� �� ������ ��������:\n1 - ����\n2 - ���������� ���������\n3 - �������� ���������\n4 - ����� ����\n5 - ���\n0 - ����� �� ������ ��������������\n��������: ";
    int mode;
    mode = checkNumericInRange(0, 5);
    switch (mode) {
    case 1: editDate(arr[choose]); break;
    case 2: system("cls"); cout << "������� ����� ����������: "; arr[choose].count_of_production = checkNumericInRange(0, 100000); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    case 3: system("cls"); cout << "������� ����� �������� ��������: "; arr[choose].name_of_production = enterProdName(); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    case 4: system("cls"); cout << "������� ����� ����� ����: "; arr[choose].number_of_workshop = checkNumeric(); cout << "��������� �������!" << endl; system("pause"); system("cls"); break;
    case 5: editProdWorker(arr[choose]); break;
    }
}

void individualTask(production* arr, int count) {
    date first, last;
    int buffTime = time(NULL) / 32536000 + 1970;
    vector<int> workshop_num (1);
    workshop_num[0] = arr[0].number_of_workshop;
    system("cls");
    int buffer_count = 0, new_buffer_count;
    production* buff_arr = new production[buffer_count];
    int first_buffer, last_buffer, buffer;
    cout << "������� ��������� ����(���): ";
    first.year = checkNumericInRange(buffTime - 60, buffTime);
    cout << "������� ��������� ����(�����): ";
    first.month = checkNumericInRange(1, 12);
    cout << "������� �������� ����(����): ";
    first.day = enterDay(first.month, first.year);
    cout << "������� �������� ����(���): ";
    last.year = checkNumericInRange(buffTime - 60, buffTime);
    cout << "������� �������� ����(�����): ";
    last.month = checkNumericInRange(1, 12);
    cout << "������� �������� ����(����): ";
    last.day = enterDay(last.month, last.year);
    first_buffer = first.year * 10000 + first.month * 100 + first.day;
    last_buffer = last.year * 10000 + last.month * 100 + last.day;
    system("cls");
    int buffNum = arr[0].number_of_workshop;
    workshop_num[0] = arr[0].number_of_workshop;
    for (int i = 0; i < count; i++) {
        if (buffNum != arr[i].number_of_workshop) {
            buffNum = arr[i].number_of_workshop;
            workshop_num.push_back(buffNum);
        }
    }
    for (int k = 0; k < workshop_num.size(); k++) {
        cout << "���������� �� ���� � " << workshop_num[k] << endl;
        for (int i = 0; i < count; i++) {
            buffer = arr[i].date.year * 10000 + arr[i].date.month * 100 + arr[i].date.day;
            if (arr[i].number_of_workshop == workshop_num[k]) {
                if (buffer >= first_buffer && buffer <= last_buffer) {
                    cout << "������������� ���������: " << arr[i].name_of_production << endl;
                    cout << "���������� ���������� ���������: " << arr[i].count_of_production << endl;
                    cout << "��� ��������������: " << arr[i].worker.surname_of_worker << " " << arr[i].worker.name_of_worker << " " << arr[i].worker.patronymic_of_worker << endl << endl;
                }
            }
        }
        cout << endl << endl;
    }
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");
    delete[] buff_arr;
}

void searchInProducton(production* arr, int count) {
    cout << "���������� ����� ��:\n1 - ���\n2 - ������ ����\n3 - ������������ ���������\n4 - ���� �������\n��������: ";
    int mode;
    mode = checkNumericInRange(1, 3);
    switch (mode) {
    case 1: searchByWorkerName(arr, count); break;
    case 2: searchByWorkshopNum(arr, count); break;
    case 3: searchByName(arr, count); break;
    case 4: searchByDate(arr, count); break;
    }
}

void sortArr(production* arr, int count) {
    system("cls");
    cout << "�� ������ ������������� ������ ��:\n1 - ����\n2 - ������ ����\n0 - ����� �� ������\n��������:";
    int mode;
    mode = checkNumericInRange(0, 2);
    switch (mode) {
    case 1: sortByDate(arr, count); break;
    case 2: sortByWorkshopNum(arr, count); break;
    case 0: cout << "��������� �������!" << endl;
    }
}

void showProdArrElem(production element) {
    cout << "----------------------------------------------" << endl;
    cout << "����: " << element.date.day << "." << element.date.month << "." << element.date.year << endl;
    cout << "������������ ���������: " << element.name_of_production << endl;
    cout << "����������: " << element.count_of_production << endl;
    cout << "����� ����: " << element.number_of_workshop << endl;
    cout << "��� ��������������: " << element.worker.surname_of_worker << " " << element.worker.name_of_worker << " " << element.worker.patronymic_of_worker << endl;
    cout << "----------------------------------------------" << endl << endl << endl;

}

void showArrOfProd(production* arr, int count) {
    for (int i = 0; i < count; i++) {
        cout << "������ " << i + 1 << endl;
        cout << "----------------------------------------------" << endl;
        cout << "����: " << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
        cout << "������������ ���������: " << arr[i].name_of_production << endl;
        cout << "����������: " << arr[i].count_of_production << endl;
        cout << "����� ����: " << arr[i].number_of_workshop << endl;
        cout << "��� ��������������: " << arr[i].worker.surname_of_worker << " " << arr[i].worker.name_of_worker << " " << arr[i].worker.patronymic_of_worker << endl;
        cout << "----------------------------------------------" << endl << endl << endl;
    }
    cout << "��������� �������!" << endl;
}


