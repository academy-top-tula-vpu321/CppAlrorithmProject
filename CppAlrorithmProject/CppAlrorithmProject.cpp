#include <iostream>

void BinNum(int n)
{
    if (n > 1)
        BinNum(n / 2);
    std::cout << n % 2;
}

unsigned long long Hanoy(int n)
{
    if (n == 0) return 0;
    return Hanoy(n - 1) * 2 + 1;
}

unsigned long long Fib(int n)
{
    static int fib[100];

    if (n == 0 || n == 1) 
        return n;
    if (fib[n] == 0) 
        fib[n] = Fib(n - 2) + Fib(n - 1);
    return fib[n];
}

unsigned long long FibLoop(int n)
{
    int f0{ 0 };
    int f1{ 1 };
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = f0 + f1;
        f0 = f1;
        f1 = temp;
    }
    return f0;
}

unsigned long long Fact(int n)
{
    if (n == 0)
        return 1;
    return Fact(n - 1) * n;
}

double PowerReq(double x, int n)
{
    if (n == 0)
        return 1;
    return PowerReq(x, n - 1) * x;
}

double PowerBinReq(double x, int n)
{
    if (n == 0) return 1;
    if (n % 2)
        return PowerBinReq(x, n - 1) * x;
    else
    {
        int p = PowerBinReq(x, n / 2);
        return p * p;
    }
}

double PowerBinLoop(double x, int n)
{
    double result{ 1 };
    while (n)
    {
        if (n % 2)
            result *= x;
        x *= x;
        n /= 2;
    }
    return result;
}

void ArraySortQuickReq(int array[], int begin, int end)
{
    int left{ begin };
    int right{ end };
    int pivot = array[(begin + end) / 2];

    do
    {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;

        if (left <= right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);

    if (begin < right) ArraySortQuickReq(array, begin, right);
    if (left < end) ArraySortQuickReq(array, left, end);
}

void ArraySortQuick(int array[], int size)
{
    ArraySortQuickReq(array, 0, size - 1);
}

void ArrayPrint(int array[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int main()
{
    srand(time(nullptr));

    const int size{ 20 };
    int array[size];

    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;

    ArrayPrint(array, size);

    /*int amountMax = array[0];
    int index = 0;
    for (int i = 0; i < size / 2 + 1; i++)
    {
        int amount{};
        for (int j = i; j < i + size / 2; j++)
            amount += array[j];
        if (amount > amountMax)
        {
            amountMax = amount;
            index = i;
        }
    }*/

    int amountMax{};
    for (int i = 0; i < size / 2; i++)
        amountMax += array[i];
    int index = 0;

    int amountCurr = amountMax;
    
    for (int i = 1; i < size / 2 + 1; i++)
    {
        int amount = amountCurr - array[i - 1] + array[i + size];
        if (amount > amountMax)
        {
            amountMax = amount;
            index = i;
        }
        amountCurr = amount;
    }


    /*ArraySortQuick(array, size);
    ArrayPrint(array, size);*/
}
