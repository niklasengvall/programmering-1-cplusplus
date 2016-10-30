// +---------------------------------------------------------------------------+
// | Uppgift 3.1-3.3 - Obligatorisk, Inlämningsuppgift 3 - Programmering 1     |
// | Uppgift 3.4 - Frivillig                                                   |
// +---------------------------------------------------------------------------+
// | Filnamn: Uppgift 3.1-3.4.cpp                                              |
// +---------------------------+------------------+-----------------+----------+
// | Skapad av: Niklas Engvall | Skapad: 16-10-30 | Ändrad 16-10-31 | V. 1.0.0 |
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
    string namn; // Attribut - Namn på person
    int alder;   // Personens ålder

    Person();                         // Konstruktorprototyper
    Person(string _namn, int _alder);
    void SkrivUt();  // Metodprototyp - för att skriva ut attributen på skärmen
};


// METOD: Person::Person, konstruktormetod
Person::Person(void)
{
    namn = "";
    alder = 0;
}
Person::Person(string _namn, int _alder)
{
    namn = _namn;
    alder = _alder;
}

// METOD: Person::SkrivUt() - Skriver ut klassens attribut, namn och alder
void Person::SkrivUt()
{
    cout << namn << ", " << alder << " år." << endl;
}

// Funktionsprototyper
int linsok(Person p[], int n, int a);   // För uppgift 3.2
void bubblesort(Person p[], int n);     // -"-
void byt(Person &p, Person &q);         // -"-

// FUNKTION:   linsok - Söker igenom Person vektorn p efter en person med
//             åldern a, n är antal element i vektorn.
// RETURNERAR: index för den person som har åldern a,
//             om ingen hittas, returneras -1.
int linsok(Person p[], int n, int a)
{
    for(int i = 0; i < n; i++) // gå igenom alla element i hela p[] vektorn
    {
        if(p[i].alder == a)    // tills vi eventuellt hittar rätt ålder
        {
            return i;
        }
    }
    return -1;
}

// FUNKTION:   bubblesort - Sorterar en Person-vektor efter ålder, yngst först.
//             n är antal element som ska sorteras.
// RETURNERAR: inget
void bubblesort(Person p[], int n)
{
    // Den yttre loopen som går igenom hela listan
    for(int i = 0; i < (n- 1); i++) 
    {
        // Den inre loopen går igenom alla elemen som inte är färdigsorterade
        for(int j = 0; j < (n - 1 - i); j++)
        {
            if(p[j].alder > p[j+1].alder) // Om element t.v. är större än t.h.
            {
                byt(p[j], p[j+1]);        // Byt plats på dem
            }
        }
    }
}

// FUNKTION:   byt - Växlar plats på två Person objekt, hör till funktionen bubblesort
// RETURNERAR: inget
void byt(Person &p, Person &q)
{
    Person temp;          // Skapar ett temporärt Person objekt
    temp.namn = p.namn;   // temp objekt tilldelas p:s namn och alder.
    temp.alder = p.alder;
    p.namn = q.namn;      // p objektet tilldelas q objektets attribut.
    p.alder = q.alder;
    q.namn = temp.namn;   // q objektet tilldelas temp objektets attribut, dvs.
    q.alder = temp.alder; // det som en gång var p objektets attribut.
}

// FUNKTION: main, start på programmet - Uppgift 3.3
int main()
{
    // Deklaration av en familje-vektor med fyra personer -Uppgift 3.3
    Person familj[4];
    familj[0].namn = "Niklas";
    familj[0].alder = 48;
    familj[1].namn = "Daniel";
    familj[1].alder = 14;
    familj[2].namn = "Agnes";
    familj[2].alder = 41;
    familj[3].namn = "Linus";
    familj[3].alder = 3;

    // Sorterar familje-vektorn, yngst först - äldst sist - Uppgift 3.3
    bubblesort(familj, 4);

    // Skriver ut familjevektorn.
    for(int i = 0; i < 4; i++)
    {
        familj[i].SkrivUt();
    }

    int index;
    int alder = 3; // Vi ska söka efter vilket index vektorn med Linus ålder har

    index = linsok(familj, 4, alder); 
    if(index >= 0)                    // Skriv ut indexet eller tala om att det
    {                                 // inte finns
        cout << "Personen med åldern " << alder << " år, finns på index: "
             << index << endl;
    }
    else
    {
        cout << "Personen med åldern " << alder << " år, finns inte i indexet!"
             << endl;
    }

    cin.get();
    return 0;
}

