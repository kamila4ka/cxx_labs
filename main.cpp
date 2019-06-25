#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> spisok1;

    for(int i=0; i<4; i++)
            spisok1.append(i);

    spisok1.addbegin(22);
    spisok1.add(9, 3);
    spisok1.del(4);

    Iterator<int> c(spisok1.begin());
    for (int i=0; i<spisok1.getCount(); ++i)
    {
        cout << *c << " ";
        ++c;
    }

    cout << endl << endl;

    List<int> spisok2(spisok1);
    Iterator<int> b(spisok2.begin());
    cout << "copy: ";
    for (auto i=spisok2.begin(); i!=spisok2.end(); ++i)
    {
        cout << *b << " ";
        ++b;
    }


    return 0;
}
