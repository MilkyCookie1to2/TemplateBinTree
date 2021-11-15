#include "header.h"

int persona::idgen =1;

int main() {
    bin_tree<persona>people;
    while(1) {
        imghead();
        if (people.empty()) {
            cout << "  ╭───┸─────────────────────╮\n"
                    "  │ К сожалению список пуст │\n"
                    "  ╰───┰─────────────────────╯\n";
        } else
        {
            showhead();
            people.show();
            showend();
        }
        showmenu();
        int vvod = checker();
        switch(vvod)
        {
            case 1:
            {
                system("clear");
                persona temp;
                cin >> temp;
                people.add(temp);
                system("clear");
                break;
            }
            case 2:
            {
                system("clear");
                del(people);
                system("clear");
                break;
            }
            case 3: {
                return 0;
            }
        }
    }
}
