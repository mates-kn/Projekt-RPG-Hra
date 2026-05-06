#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int pocetzivotu = 0;
int damage = 0;
int schopnost = 0;
int stamina = 0;
int monstra = 0;
int MDamage = 0;
int MZivoty = 0;
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
void boj (){
    do{
        cout << "\n-------------------------------------\n";
        cout << "Tvoje zivoty: " << pocetzivotu << endl;
        cout << "Tvoje stamina: " << stamina << endl;
        cout << "Zivoty monstra: " << MZivoty << endl;

        int volba;
        cout << "1 - Utok (stoji 5 stamina)\n";
        cout << "2 - Odpocinek (+10 stamina)\n";
        cout << "3 - Schopnost (stoji 25 stamina)\n";
        cout << "Vyber: ";
        cin >> volba;

        switch(volba){
            case 1:
                if (stamina >= 5){
                    cout << "Utocis za " << damage << " damage!\n";
                    MZivoty -= damage;
                    stamina -= 5;
                } else {
                    cout << "Nemáš dost stamina!\n";
                }
                break;

            case 2:
                cout << "Odpocivas a doplnujes stamina.\n";
                stamina += 10;
                if (stamina > 50) stamina = 50;
                break;

            case 3:
                if (stamina >= 25){
                    cout << "Pouzivas schopnost za " << schopnost << " damage!\n";
                    MZivoty -= schopnost;
                    stamina -= 25;
                } else {
                    cout << "Nemáš dost stamina na schopnost!\n";
                }
                break;

            default:
                cout << "Neplatna volba!\n";
        }
        if (MZivoty > 0){
            int mUtok = rand() % 6 + 10 * monstra;
            cout << "Monstrum utoci za " << mUtok << " damage!\n";
            pocetzivotu -= mUtok;
        }

    }while (pocetzivotu > 0 && MZivoty > 0);
}
int main() {
    std::srand(std::time(0));
    system("Color e0");
cout << "AHOJ! Vitej v me hre. Nez si vyberes classu, je potreba vedet ze klasicky utok vzdy stoji 5 stamina a pouziti schopnosti stoji 25 stamina." << endl;
char potvrzeni;
do{
pocetzivotu = 0;
damage = 0;
stamina = 0;
schopnost = 0;
int volbapostavy = 0;
    cout << "Vyber si classu sve postavy:" << endl;
    cout << "1-Knight" <<endl;
    cout << "2-Tank" <<endl;
    cout << "3-Assasin" <<endl;
    cin >> volbapostavy;
    switch (volbapostavy){
    case 1:
        knight();
        pocetzivotu = pocetzivotu + 100;
        stamina = stamina + 50;
        damage = damage + 15;
        schopnost = schopnost + 20;
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 2:
        tank();
        pocetzivotu = pocetzivotu + 120;
        stamina = stamina + 40;
        damage = damage + 20;
        schopnost = schopnost + 25;
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 3:
        assasin();
        pocetzivotu = pocetzivotu + 90;
        stamina = stamina + 60;
        damage = damage + 10;
        schopnost = schopnost + 15;
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    default:cout << "Neplatna volba" << endl;
    }
}while (potvrzeni != 'a');
do {
int volbapoctu;
cout << "Proti kolika monstrum chces bojovat (1-3):";
cin >> volbapoctu;
switch (volbapoctu) {
case 1:
    monstra = 1;
    MZivoty = 60 * monstra;
    boj();
    break;
case 2:
    monstra = 2;
    MZivoty = 60 * monstra;
    boj();
    break;
case 3:
    monstra = 3;
    MZivoty = 60 * monstra;
    boj();
    break;
}
}while (pocetzivotu > 0 && MZivoty > 0);
return 0;
}
