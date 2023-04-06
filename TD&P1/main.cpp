#include <iostream>

/*
fn div(a,b) do
    while a >= b do
        a = a - b
        q ++
    end
    return q, a
end
*/

int* eu_div(int a, int b) {
    int q = 0;
    while (a >= b) {
        a = a - b;
        q++;
    }
    int* arr = new int[2];
    arr[0] = q;
    arr[1] = a;
    return arr;
}

int main(int, char**) {
    std::cout << "Hello, world!\n";
    int* arr = eu_div(10, 3);
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
}
