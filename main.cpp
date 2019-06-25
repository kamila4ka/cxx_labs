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

    for (Iterator<int> c(spisok1.begin()); c.isValid(); ++c)
    {
        cout << *c << " ";
    }

    cout << endl << endl;

    List<int> spisok2(spisok1);
    Iterator<int> b(spisok2.begin());
    cout << "copy: ";
    for (Iterator<int> c(spisok2.begin()); c.isValid(); ++c)
    {
        cout << *c << " ";
    }


    return 0;
}
