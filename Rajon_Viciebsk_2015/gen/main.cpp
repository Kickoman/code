#include <cstdio>

using namespace std;

int main()
{
    freopen("../z3/task.in", "w", stdout);
    printf("2000 2000\n");
    for (int i = 0; i < 2000; ++i)
    {
        for (int j = 0; j < 2000; ++j)
            printf("0 ");
        printf("\n");
    }
    return 0;
}
