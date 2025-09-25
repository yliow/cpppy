#include <iostream>

void increment_at(int x[], int i)
{
    x[i]++;
}

int main()
{
    int a[] = {2, 3, 5, 7};
    increment_at(a, 1);
    std::cout << a[1] << std::endl; // a[1] *is* changed
    increment_at(a, 2);
    std::cout << a[2] << std::endl; // a[2] *is* changed
    return 0;
}
