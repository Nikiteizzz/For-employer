#include "searches.h"
#include "ctime"

void searchByName(production* arr, int count) {
    string buffer;
    system("cls");
    cout << "Введите искомое название: ";
    buffer = enterProdName();
    int j = 1;
    for (int i = 0; i < count; i++) {
        if (arr[i].name_of_production == buffer) {
            cout << "Запись " << j << endl;
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "Подходящих записей не было найдено(" << endl;
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");

}

void searchByDate(production* arr, int count) {
    date buffer;
    system("cls"); 
    int buffYear = time(NULL) / 31536000 + 1970;
    cout << "Введите нужный год: ";
    buffer.year = checkNumericInRange(buffYear - 60, buffYear);
    cout << "Введите нужный месяц: ";
    buffer.month = checkNumericInRange(1, 12);
    cout << "Введите нужную дату: ";
    buffer.day = enterDay(buffer.month, buffer.year);
    int j = 1;
    cout << "-----Результаты поиска-----" << endl;
    for (int i = 0; i < count; i++) {
        if (arr[i].date.year == buffer.year && arr[i].date.month == buffer.month && arr[i].date.day == buffer.day) {
            cout << "-----Запись " << j << "-----" << endl;
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "Подходящих записей не было найдено(" << endl;
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}

void searchByWorkshopNum(production* arr, int count) {
    system("cls");
    int buffer;
    cout << "Введите номер искомого цеха" << endl;
    buffer = checkNumeric();
    int j = 1;
    for (int i = 0; i < count; i++) {
        if (arr[i].number_of_workshop == buffer) {
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "Подходящих записей не было найдено(" << endl;
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}

void searchByWorkerName(production* arr, int count) {
    system("cls");
    worker buffer;
    cout << "Введите нужную фамиилию: ";
    buffer.surname_of_worker = enterTextInfo();
    cout << "Введите нужное имя: ";
    buffer.name_of_worker = enterTextInfo();
    cout << "Введите нужное отчество: ";
    buffer.patronymic_of_worker = enterTextInfo();
    system("cls");
    cout << "-----Результаты поиска-----" << endl;
    int j = 1;
    for (int i = 0; i < count; i++) {
        if (arr[i].worker.surname_of_worker == buffer.surname_of_worker && arr[i].worker.name_of_worker == buffer.name_of_worker && arr[i].worker.patronymic_of_worker == buffer.patronymic_of_worker) {
            cout << "-----Запись " << j << "-----" << endl;
            showProdArrElem(arr[i]);
            j++;
        }
    }
    if (j == 1) {
        cout << "Подходящих записей не было найдено(" << endl;
    }
    cout << "Выполнено успешно!" << endl;
    system("pause");
    system("cls");
}
