#include <iostream>
#include <vector>
using namespace std;
#include <string.h>
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4;

vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

void
find_minmax(vector<double> numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
    for (double x:numbers) //нахождение мин и макс
    {
        if (x < min)
        {
            min = x;
        }
        if (x > max)
        {
            max = x;
        }
    }
}

int main()
{
    size_t numbers_count; //количество элементов
    cerr << "Enter numbers_count ";
    cin >> numbers_count;
    const auto numbers = input_numbers(numbers_count); //ввод чисел

    size_t bin_count; //количество корзин
    cerr << "Enter bin_count ";
    cin >> bin_count;


     vector<size_t>bins(bin_count, 0); //массив корзин
    double min = numbers[0];
    double max = numbers[0];

    for (int i = 1; i < numbers_count; i++) //нахождение мин и макс
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    for (double x : numbers) // проверка попадания в диапoзон
    {
        size_t bin_index = (size_t)((x - min) * bin_count) / (max - min); //определение индекса корзины для каждого элемента. bin_index -номер корзины
        if (bin_index == bin_count)
        {
            bin_index = bin_index - 1;
        }
        bins[bin_index]++;
    }

    double max_count = bins[0];
    for (size_t b : bins) //найти максимальное значение(max count) height
    {
        if (b > max_count)
        {
            max_count = b;
        }
    }
    double step = (max - min) / bin_count;
    double dia = min + step;
    double koeff = 1;//коэффицент
    if(max_count>MAX_ASTERISK)
    {
        koeff = (double)(MAX_ASTERISK) / max_count;
    }
    for (size_t bin : bins) //вывод гистограммы
    {
        if (bin < 100)
        {
            cout << "    ";
        }
        if (bin < 10)
        {
            cout << "    ";
        }
        cout << bin << "|";
        for (int i = 0; i < koeff * bin; i++)
        {
            cout << "*";
        }
        cout << endl;
        if(dia!=max)
        {
            cout << dia << endl;
        }
        dia=dia+step;

    }
    return 0;
}
