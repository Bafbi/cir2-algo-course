#include <iostream>

// int* ternaryCounter(int n);

// int main(int argc, char const *argv[])
// {

//     int n = 3;
//     int *arr = ternaryCounter(n);
    
//     for (int i = 0; i < n; i++)
//     {
//         std::cout << arr[i] << std::endl;
//     }



//     return 0;
// }


// // make a ternary counter that will return an array of array of size n
// // the array will be filled with 0, 1, 2
// // the array will be filled like this:
// // 0, 0, 0
// // 0, 0, 1
// // 0, 0, 2
// // 0, 1, 0
// // 0, 1, 1
// // 0, 1, 2
// // 0, 2, 0
// // 0, 2, 1

// int* ternaryCounter(int n)
// {
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = 0;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 2)
//         {
//             arr[i] = 0;
//             arr[i + 1]++;
//         }
//     }

//     return arr;
// }




// ```
// fn succ(&lettre, pos) do
//     lettre[i] = lettre[(i + 1) % (n - 1)]
// end

// fn suivant(&mot) do
//     uint i = n - 1
//     while succ(mot[i], i) == premiere do
//         i --
//     end
// end

// fn generateur(mot) do
//     while mot[n-1] != derniere do
//         show(suivant(mot))
//     end

// ```

// code this pseudo code

char basemot[] = {'a', 'l', 'g', 'o', 'r', 'i', 't', 'h', 'm', 'e'};

char succ(char *lettre, int n)
{
    // get letter pos in basemot
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (*lettre == basemot[i])
        {
            pos = i;
        }
    }
    *lettre = basemot[(pos + 1) % (n)];
    return *lettre;
}

void suivant(char *mot, int n)
{
    int i = n - 1;
    while (succ(&mot[i], n) == basemot[0])
    {
        i--;
    }
}

bool test(char *mot, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (mot[i] != basemot[n - 1])
        {
            return false;
        }
    }
    return true;
}

void generateur(char *mot, int n)
{
    while (!test(mot, n))
    {
        suivant(mot, n);
        std::cout << mot << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    char mot[] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    generateur(mot, 10);

    return 0;
}