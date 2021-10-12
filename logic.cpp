#include "logic.h"
#include <cstdlib>
namespace logic
{

    void fill_mass_rand(int *arr,int n) //функция заполнения массива рандомными числами
    {
        for(int i = 0; i < n; i++) //цикл заполнения рандомными числами
        {
            arr[i] = rand() % 100;
        }
    }

    int mass_summ(int *arr, int n) //функция вычисления суммы чисел массива
    {
        int summ = 0;
        for(int i = 0; i < n; i++) //цикл вычисления суммы
        {
            summ += arr[i];
        }
        return summ;
    }
}
