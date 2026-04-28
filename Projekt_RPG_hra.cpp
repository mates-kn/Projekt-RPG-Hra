#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
void knight(){
    cout << endl << "KNIGHT je takova nejvic balanced class. Na zacatku hry mate tyto staty:" << endl;
    cout << "Max pocet zivotu: 100" << endl;
    cout << "Max stamina: 50" << endl;
    cout << "Zakladni damage: 15" << endl;
    cout << "Zacatecni schopnost: Ohnivy mec (20 damage)" << endl;
}
void tank(){
    cout << endl << "TANK ma vice zivotu, vetsi damage ale mene stamina. Na zacatku hry mate tyto staty:" << endl;
    cout << "Max pocet zivotu: 120" << endl;
    cout << "Max stamina: 40" << endl;
    cout << "Zakladni damage: 20" << endl;
    cout << "Zacatecni schopnost: Strong punch (25 damage)" << endl;
}
void assasin(){
    cout << endl << "ASSASIN ma mene zivotu, mene damage ale vice stamina. Na zacatku hry mate tyto staty:" << endl;
    cout << "Max pocet zivotu: 90" << endl;
    cout << "Max stamina: 60" << endl;
    cout << "Zakladni damage: 10" << endl;
    cout << "Zacatecni schopnost: Movement confusion (15 damage)" << endl;
}
string jmeno;
int main() {
    system("Color e0");
cout << "AHOJ! Vitej v me hre. Nez si vyberes classu, je potreba vedet ze klasicky utok vzdy stoji 5 stamina a pouziti schopnosti stoji 10 stamina." << endl;
char potvrzeni;
do{
int volbapostavy = 0;
    cout << "Vyber si classu sve postavy:" << endl;
    cout << "1-Knight" <<endl;
    cout << "2-Tank" <<endl;
    cout << "3-Assasin" <<endl;
    cin >> volbapostavy;
    switch (volbapostavy){
    case 1:
        knight();
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 2:
        tank();
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 3:
        assasin();
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    default:cout << "Neplatna volba" << endl;
    }
}while (potvrzeni != 'a');
return 0;
}
