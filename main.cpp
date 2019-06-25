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
    spisok1.del(3);


    cout << "count: " << spisok1.getCount() << endl << "the first list: ";
    spisok1.getData();
    cout << endl << endl;

    List<int> spisok2(spisok1);
    cout << "copy: ";
    spisok2.getData();


    return 0;
}
