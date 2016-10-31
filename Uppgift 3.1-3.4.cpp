// +---------------------------------------------------------------------------+
// | Uppgift 3.1-3.3 - Obligatorisk, Inlämningsuppgift 3 - Programmering 1     |
// | Uppgift 3.4 - Frivillig                                                   |
// +---------------------------------------------------------------------------+
// | Filnamn: Uppgift 3.1-3.4.cpp                                              |
// +---------------------------+------------------+-----------------+----------+
// | Skapad av: Niklas Engvall | Skapad: 16-10-30 | Ändrad 16-10-31 | V. 1.0.0 |
// +---------------------------+------------------+-----------------+----------+
// | UTVÄRDERING: Kul uppgift, tog ett tag och slutföra. Allrahelst sista uppg.|
// |                                                                           |
// |              Metodlösning:                                                |
// |              1. Kikade i läroboken på exempel xxxx, sidan xx som tog upp  |
// |                 klassen Person. Skrev därefter raderna xx-xx och testade  |
// |                 klassen med en egen liten rutin i main som jag raderade   |
// |                 efter test.                                               |
// |              2. Kikade i läroboken om linjär sökning, exempel xxxx,       |
// |                 sid. Skrev sedan funktionen på raderna xx-xx och la in en |
// |                 manuell tilldelning av Personvektorn för att kunna testa  |
// |                 funktionen (uppgift 3.3)                                  |
// |              3. Började sedan med bubblesort-funktionen och tog idén från |
// |                 bokens exempel xx.x, sid. xxx samt instruktionen för      |
// |                 inlämningsuppgift 3. Byggde vidare på main-funktionen för |
// |                 att även testa detta, dvs. uppgift 3.3 med allt bestämt i |
// |                 koden. Ingen manuell inmatning med cin ännu.              |
// |              4. Uppgift 3.4 - Va e detta? I boken fanns en itterativ      |
// |                 lösning och i instruktionen en grov pseudokod, tack o lov |
// |                 förstod jag kodexemplet bra men sen? Vad är en rekursiv   |
// |                 funktion? Ja att den anropar sig själv det är klart. Men  |
// |                 att sedan omsätta detta i praktiken det är en konst. Jag  |
// |                 gorde säkert närmare 30-40 kompileringar innan jag var    |
// |                 färdig med all kod. La in egen variabelkontroll, gjorde   |
// |                 om en del ifrån pseudokoden ANNARS OM vektorn består av   |
// |                 endast ett element till else if(first >= last). I övrigt  |
// |                 så använder jag referensanrop för att lösa detta, dock ej |
// |                                                                           |
// |                 Förslag på förbättringar:                                 |
// |                 1. Att göra om funktionerna till metoder för bättre       |
// |                    inkapsling. Samt använda bätter minnestilldelning med  |
// |                    new och pekare till klassernas objekt, metoder,attribut|                                         |
// |                 2. Göra om Person p[]-vektorn till pekarreferens för att  |
// |                    undvika minnesspill.                                   |
// |                 3. Att inte använda rekursivt anrop på binarSok om        |
// |                    mängden anrop ökar lavinartat då fylls stack-minnet    |
// |                    och programmet riskerar att krascha.                   |
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

    void SkrivUt();  // Metodprototyp - för att skriva ut attributen på skärmen
};

// METOD: Person::SkrivUt() - Skriver ut klassens attribut, namn och alder
void Person::SkrivUt()
{
    cout << namn << ", " << alder << " \x86r." << endl;
}

// Funktionsprototyper
int linsok(Person p[], int n, int a);   // För uppgift 3.2
void bubblesort(Person p[], int n);     // -"-
void byt(Person &p, Person &q);         // -"-
int binarSok(Person p[], int &alder, int &first, int &last); // Uppgift 3.4

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
        // Den inre loopen går igenom alla element som inte är färdigsorterade
        for(int j = 0; j < (n - 1 - i); j++)
        {
            if(p[j].alder > p[j+1].alder) // Om element t.v. är större än t.h.
            {
                byt(p[j], p[j+1]);        // Byt plats på dem
            }
        }
    }
}

// FUNKTION:   byt - Växlar plats på två Person objekt, se funktionen bubblesort
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

// FUNKTION:   binarSok - Söker efter ålder i en Person vektor med rekursiv
//             algoritm.
// RETURNERAR: index eller -1 om inte åldern hittats
int binarSok(Person p[], int &alder, int &first, int &last)
{
	int mid = (first + last) / 2; // Utgå från mittenvärdet när vi söker

	// Nedanstående rad använder jag för att se förloppet under felsökning
	//cout <<"Mid: " << mid << "First: " << first << ", Last: " << last << endl;

	if(p[mid].alder == alder) // Värdet hittat
	{
		return mid; // Returnera index för sökning
	}
	else if(first >= last)
	{
		return -1; // Värdet hittades inte
	}
	else if(alder < p[mid].alder)
	{
		last = mid - 1; // Sök i den nedre halvan av vektorn
	}
	else
	{
		first = mid + 1; // Sök i den övre halvan av vektorn
	}
	return binarSok(p, alder, first, last); // Rekursivt anrop
}

// FUNKTION: main, start på programmet - Uppgift 3.3
int main()
{
    Person familj[4];
/*  // Initiering av en familje-vektor med fyra personer - Uppgift 3.3 + 3.4
    familj[0].namn = "Niklas";
    familj[0].alder = 48;
    familj[1].namn = "Daniel";
    familj[1].alder = 14;
    familj[2].namn = "Agnes";
    familj[2].alder = 41;
    familj[3].namn = "Linus";
    familj[3].alder = 3;
*/
	// Mata in 4 familjemedlemmars namn och ålder - Uppgift 3.3 + 3.4
	string namn;
	int alder;
	cout << "Mata in 4 familjemedlemmars namn och \x86lder" << endl;
	cout << "==========================================" << endl << endl;

	for(int i = 0; i < 4; i++)
	{
		cout << "Ange namn p\x86 familjemedlem " << i + 1 << ": ";
		getline(cin, namn);
		cout << "Ange \x86lder p\x86 familjemedlem " << i+ 1 << ": ";
		cin >> alder;
		cin.ignore(1000,'\n'); // Flusha inmatningsbufferten

		familj[i].namn = namn;
		familj[i].alder = alder;
    }

    // Sorterar familje-vektorn, yngst först - äldst sist - Uppgift 3.3
    bubblesort(familj, 4);

    // Skriver ut familjevektorn.
    for(int i = 0; i < 4; i++)
    {
        familj[i].SkrivUt();
    }

    int index, first = 0, last = 3; // Används för uppgift 3.2 och 3.4

	// int alder = 14; // Vi ska söka efter vilket index vektorn med Daniels
	// ålder

	// Fråga användaren vilken ålder vi ska söka efter
	cout << "Ange \x86lder p\x86 familjemedlem du vill s\x94ka efter: ";
	cin >> alder;

    index = linsok(familj, 4, alder); // Utför Linjär sökning

    cout << "Linj\x84r s\x94kning: Personen med \x86ldern " << alder
         << " \x86r, finns p\x86 index: " << index << endl;

	index = binarSok(familj, alder, first, last); // binarSok - Uppgift 3.4

	cout << "Bin\x84r s\x94kning: S\x94kte efter \x86ldern " << alder
         << " \x86r och fann den p\x86 index: " << index << "." << endl;

    cin.get();
    return 0;
}

