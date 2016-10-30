// +---------------------------------------------------------------------------+
// | Uppgift 3.1-3.3 - Obligatorisk, Inlämningsuppgift 3 - Programmering 1     |
// | Uppgift 3.4 - Frivillig                                                   |
// +---------------------------------------------------------------------------+
// | Filnamn: Uppgift 3.1-3.4.cpp                                              |
// +---------------------------+------------------+-----------------+----------+
// | Skapad av: Niklas Engvall | Skapad: 16-10-30 | Ändrad 16-10-30 | V. 1.0.0 |
// +---------------------------+------------------+-----------------+----------+
// | UPPGIFT: Skapa en klass och konstruktor för ditt favoritdjur              |
// |                                                                           |
// +---------------------------------------------------------------------------+
//
#include <iostream> // Preprocessordirektiv: inkludera funktioner för in-utdata
#include <string>   // och stränghantering

using namespace std; // Vi ska använda standardbibliotekets funktioner

// KLASS: Person - För uppgift 3.1
class Person
{
public:
    string name; // Attribut - Namn på person
    int alder;   // Personens ålder

    Person(string _name, int _alder); // Konstruktorprototyp
    void SkrivUt();  // Metodprototyp - för att skriva ut attributen på skärmen
};


// METOD: Person::Person, konstruktormetod
Person::Person(string _name, int _alder)
{
    name = _name;
    alder = _alder;
}

// METOD: Person::SkrivUt() - Skriver ut klassens attribut
void Person::SkrivUt()
{
    cout << name << ", " << alder << " år." << endl;
}



// FUNKTION: main, start på programmet
int main()
{
    // Testar uppgift 3.1
    Person minPerson("Kalle", 45);
    minPerson.SkrivUt();

    cin.get();
    return 0;
}

