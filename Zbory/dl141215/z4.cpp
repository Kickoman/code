#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#ifdef LOCAL
    #define TASK "task"
#else
    #define TASK "match"
#endif // LOCAL

int main()
{
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
//    freopen("task.in", "r", stdin);
//    freopen("task.out", "w", stdout);
    string cmd;
    int lastKick = -1, services = 0,
        server = 1;
    int goals[3] = {0, 0, 0};
    while ((cin >> cmd) && cmd != "eom")
    {
        if (cmd == "service")
            services++, lastKick = server;
        if (cmd == "net")
            goals[3 - lastKick]++;
        if (cmd == "out")
            goals[3 - lastKick]++;
        if (cmd == "goal")
            goals[lastKick]++;
        if (cmd == "return")
            lastKick = 3 - lastKick;
//        cerr << goals[1] << " " << goals[2] << endl;
        if (services == 5)
            server = 3 - server, services = 0;
    }
    printf("%d %d", goals[1], goals[2]);
    return 0;
}
