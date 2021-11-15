#include "header.h"

persona::persona() {
    id = idgen++;
    fam = "N\\N";
    name = "N\\N";
    och = "N\\N";
    whybad = "N\\N";
}

persona::persona(int m_id,string m_fam, string m_name, string m_och,string m_whybad) {
    id=m_id;
    fam = m_fam;
    name = m_name;
    och = m_och;
    whybad = m_whybad;
}

persona::persona(const persona &pers) {
    id = pers.id;
    fam=pers.fam;
    name = pers.name;
    och=pers.och;
    whybad=pers.whybad;
}

istream& operator>>(istream& in, persona&pers)
{
    cout << "Введите фамилию: ";
    in >> pers.fam;
    cout << "Введите имя: ";
    in >> pers.name;
    cout << "Введите отчество: ";
    in >> pers.och;
    cout << "Почему плохой?\n";
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(in,pers.whybad);
    return in;
}

ostream& operator<<(ostream& out, const persona&pers)
{
    out <<"  │ "<<setw(2)<< pers.id<<" │ "<<setw(13)<<pers.fam<<" │ "<<setw(13)<<pers.name<<" │ "<<setw(14)<<pers.och<<" │ "<< setw(31)<< pers.whybad<<" │"<<endl;
    return out;
}

bool operator>(const persona&chel1, const persona&chel2)
{
    return chel1.fam>chel2.fam;
}

bool operator<(const persona&chel1, const persona&chel2)
{
    return chel1.fam<chel2.fam;
}

bool operator==(const persona&chel1, const persona&chel2)
{
    return (chel1.fam==chel2.fam && chel1.name==chel2.name && chel1.och==chel2.och);
}

bool operator!=(const persona&chel1, const persona&chel2)
{
    return (chel1.id!=chel2.id);
}

void del(bin_tree<persona>&people)
{
    if (people.empty())
    {
        cout <<"──────╮\n"
               "  ╭───┴──────────────────────────────────────────────────────╮\n"
               "  │ Список плохих людей, к-рые как-либо насолили мне в жизни │\n"
               "  ╰───┬──────────────────────────────────────────────────────╯\n"
               "  ╭───┴─────────────────────╮\n"
               "  │ К сожалению список пуст │\n"
               "  ╰───┬─────────────────────╯\n"
               "──────╯\n";
        cout << "───╱╲──────────────────────────────────────╮\n"
                "  ╱▐▌╲  Нажмите ENTER, чтобы продолжить... │\n"
                "─╱ ╺╸ ╲────────────────────────────────────╯\n"
                " ▔▔▔▔▔▔\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    else
    {
        showhead1();
        people.show();
        showend1();
    }
    cout << "\nВведите id плохого человека, к-ого хотите удалить:\n";
    int vvodid=checker();
    persona temp(vvodid,"","","","");
    bin_tree<persona>::iterator it;
    it = people.find(temp);
    if (it== nullptr)
    {
        cout << "─╱▔▔▔╲──────────────────────────╮\n"
                "▕  ╳  ▎ Человека с таким id нет │\n"
                "─╲▁▁▁╱──────────────────────────╯\n\n";
        cout << "───╱╲──────────────────────────────────────╮\n"
                "  ╱▐▌╲  Нажмите ENTER, чтобы продолжить... │\n"
                "─╱ ╺╸ ╲────────────────────────────────────╯\n"
                " ▔▔▔▔▔▔\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
    else
    {
        people.erase(it);
    }
}