#include "searches.h"
#include "ctime"

void searchByName(production* arr, int count) {
    string buffer;
    system("cls");
    cout << "������� ������� ��������: ";
    buffer = enterProdName();
    int j = 1;
    for (int i = 0; i < count; i++) {
        if (arr[i].name_of_production == buffer) {
            cout << "������ " << j << endl;
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "���������� ������� �� ���� �������(" << endl;
    }
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");

}

void searchByDate(production* arr, int count) {
    date buffer;
    system("cls"); 
    int buffYear = time(NULL) / 31536000 + 1970;
    cout << "������� ������ ���: ";
    buffer.year = checkNumericInRange(buffYear - 60, buffYear);
    cout << "������� ������ �����: ";
    buffer.month = checkNumericInRange(1, 12);
    cout << "������� ������ ����: ";
    buffer.day = enterDay(buffer.month, buffer.year);
    int j = 1;
    cout << "-----���������� ������-----" << endl;
    for (int i = 0; i < count; i++) {
        if (arr[i].date.year == buffer.year && arr[i].date.month == buffer.month && arr[i].date.day == buffer.day) {
            cout << "-----������ " << j << "-----" << endl;
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "���������� ������� �� ���� �������(" << endl;
    }
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");
}

void searchByWorkshopNum(production* arr, int count) {
    system("cls");
    int buffer;
    cout << "������� ����� �������� ����" << endl;
    buffer = checkNumeric();
    int j = 1;
    for (int i = 0; i < count; i++) {
        if (arr[i].number_of_workshop == buffer) {
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "���������� ������� �� ���� �������(" << endl;
    }
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");
}

void searchByWorkerName(production* arr, int count) {
    system("cls");
    worker buffer;
    cout << "������� ������ ��������: ";
    buffer.surname_of_worker = enterTextInfo();
    cout << "������� ������ ���: ";
    buffer.name_of_worker = enterTextInfo();
    cout << "������� ������ ��������: ";
    buffer.patronymic_of_worker = enterTextInfo();
    system("cls");
    cout << "-----���������� ������-----" << endl;
    int j = 1;
    for (int i = 0; i < count; i++) {
        if (arr[i].worker.surname_of_worker == buffer.surname_of_worker && arr[i].worker.name_of_worker == buffer.name_of_worker && arr[i].worker.patronymic_of_worker == buffer.patronymic_of_worker) {
            cout << "-----������ " << j << "-----" << endl;
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "���������� ������� �� ���� �������(" << endl;
    }
    cout << "��������� �������!" << endl;
    system("pause");
    system("cls");
}
