// create a pseudo code to get the max monotonic sequence in a table


#include <cstdlib>

uint[] init_tab(uint n)
{
    size_t[] T = new size_t[n];
    for (size_t i = 0; i < n; i++)
    {
        T[i] = rand() % 100;
    }
    return T;
}

#define N 100

auto T = init_tab(N);
size_t C;
size_t B = 0;

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < N - 2; i++)
    {
        if (T[i] < T[i + 1])
        {
            C++;
        }
        else
        {
            if (C > B)
            {
                B = C;
            }
            C = 0;
        }
    }

    return 0;
}
