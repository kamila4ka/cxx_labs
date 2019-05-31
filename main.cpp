#include <iostream>
#include "list.h"

using namespace std;

class example
{
public:
    example(){}
    example(int a, int b): _a(a), _b(b){}
    int _a;
    int _b;
};

int main()
{
    List<int> spisok1; // использование List с типом int

    for(int i=0; i<4; i++)
            spisok1.append(i);
    spisok1.addbegin(22);
    spisok1.add(9, 3);
    spisok1.del(3);


    cout << "count: " << spisok1.getCount() << endl << "the first list: ";
        for(int i = 0; i<spisok1.getCount(); i++)
            cout << spisok1.getData(i) << " ";
    cout << endl << endl;

    spisok1.clear();
    cout << "cleared. count: " << spisok1.getCount() << endl;

    return 0;
}
