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
        int maxpocziv = 0;
        int maxstamina = 0;
        int maxdamage = 0;
        int maxschopnost = 0;
        int penize = 0;
        int xp = 0;
        int level = 0;
        int levelUP = 300;
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
        cout << "-------------------------------------\n";
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
                    cout << "Nemas dost stamina!\n";
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
                    cout << "Nemas dost stamina na schopnost!\n";
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
if (MZivoty < 1){
    cout <<endl<< "Vyhral jsi souboj!"<< endl;
    penize += 100*monstra;
    xp += 100*monstra;
}
if (pocetzivotu < 1){
    cout <<endl<< "Prohral jsi souboj! Bohuzel jsi umrel..."<< endl;
}
    }while (pocetzivotu > 0 && MZivoty > 0);
}
void obchod(){
    int volbaUpgr;
    cout << "--------VITEJ V OBCHODE--------" << endl;
    cout << "Tady si muzes vylepsovat svoje staty, za kazdy upgrade \n dostanes taky 25 xp"<<endl;
    cout << "Mas: " <<penize<< " korun"<<endl;
    cout << "Jaky stat si chces vylepsit: "<< endl;
    cout << "1. volba -> +5 zivotu (cena -> 75)" << endl;
    cout << "2. volba -> +5 stamina (cena -> 125)" << endl;
    cout << "3. volba -> +5 damage (cena -> 100)" << endl;
    cout << "4. volba -> +5 schopnost (cena -> 175)" << endl;
    cout << "5. volba -> pokud nic vylepsovat nechces muzes se vratit do vesnice"<< endl;
    cout << "Zadej volbu:";
    cin >> volbaUpgr;
    switch (volbaUpgr){
case 1:
    if (penize >= 75){
        penize -= 75;
        maxpocziv +=5;
        xp += 25;
        cout << "Mas o 5 hp vic."<< endl;
    }
    else{
        cout << "Nemas dost penez..."<< endl;
    }
    break;
case 2:
    if (penize >= 125){
        penize -= 125;
        maxstamina +=5;
        xp += 25;
        cout << "Mas o 5 stamina vic."<< endl;
    }
    else{
        cout << "Nemas dost penez..."<< endl;
    }
    break;
case 3:
    if (penize >= 100){
        penize -= 100;
        maxdamage +=5;
        xp += 25;
        cout << "Budes davat o 5 damage vic."<< endl;
    }
    else{
        cout << "Nemas dost penez..."<< endl;
    }
    break;
case 4:
    if (penize >= 175){
        penize -= 175;
        maxschopnost +=5;
        xp += 25;
        cout << "Tvoje schopnost bude ubirat o 5 hp vic."<< endl;
    }
    else{
        cout << "Nemas dost penez..."<< endl;
    }
    break;
case 5:
    break;
default: cout << "Neplatna volba!"<< endl;
}
}
int main() {
    std::srand(std::time(0));
    system("Color e0");
cout << "AHOJ! Vitej v me hre. Nez si vyberes classu, je potreba vedet ze klasicky utok vzdy stoji 5 stamina a pouziti schopnosti stoji 25 stamina." << endl;
cout << "A hlavne opatrne mas jen jeden pokus! Takze hlavne neumrit :D"<<endl;
char potvrzeni;
do{
        maxpocziv = 0;
        maxstamina = 0;
        maxdamage = 0;
        maxschopnost = 0;
int volbapostavy = 0;
cout << "--------------------------------------------------------------------------------"<<endl;
    cout << "Vyber si classu sve postavy:" << endl;
    cout << "1-Knight" <<endl;
    cout << "2-Tank" <<endl;
    cout << "3-Assasin" <<endl;
    cin >> volbapostavy;
    switch (volbapostavy){
    case 1:
        knight();
        maxpocziv += 100;
        maxstamina += 50;
        maxdamage += 15;
        maxschopnost += 20;
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 2:
        tank();
        maxpocziv += 120;
        maxstamina += 40;
        maxdamage += 20;
        maxschopnost += 25;

        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 3:
        assasin();
        maxpocziv += 90;
        maxstamina += 60;
        maxdamage += 10;
        maxschopnost += 15;
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    default:cout << "Neplatna volba" << endl;
    }
}while (potvrzeni != 'a');
cout << "---------------------------------------------------------------------"<< endl;
cout << "Odted po kazdym souboji pujdes zpet do vesnice, lidi jsou tam moc hodni a po kazdem souboji\n ti vyleci vsechna zraneni jen za 25 korun."<<endl;
pocetzivotu = maxpocziv;
do{
if (penize >= 25 && pocetzivotu != maxpocziv){
    cout << "---------------------------------------------------------------------"<< endl;
    char doplneni;
    cout << "Mas: " <<penize<< " korun"<<endl;
    cout << "Chces doplnit sve zivoty po souboji za 25 korun?(a/n): ";
    cin >> doplneni;
    switch (doplneni){
case 'a':
    pocetzivotu = maxpocziv;
    penize -=25;
    break;
case 'n':
    cout << "No kdyz myslis...";
    break;
    }
}

stamina = maxstamina;
damage = maxdamage;
schopnost = maxschopnost;
int volbamista = 0;
    if (xp == levelUP){
    cout << "---------------------------------------------------------------------"<< endl;
    cout << "--------DOSAHL JSI VYSSIHO LEVELU!--------"<<endl;
        xp-=levelUP;
        level++;
        cout << "Ted mas level: " << level << endl;
        levelUP+=50;
        }
    else if (xp>levelUP){
        cout << "---------------------------------------------------------------------"<< endl;
        cout << "--------DOSAHL JSI VYSSIHO LEVELU!--------"<<endl;
        int zbytek = xp-levelUP;
        xp += zbytek;
        level++;
        cout << "Ted mas level: " << level<<endl;
        levelUP += 50;
        }
cout << "---------------------------------------------------------------------"<< endl;
    cout << "Ted mas: " << xp<< " xp"<<endl;
    cout << "Na dalsi level ti zbyva: "<< levelUP-xp << "xp"<<endl;
    cout << "Muzes jit do areny (1) nebo do obchodu (2), takze si vyber kam chces jit: ";
    cin >> volbamista;
switch (volbamista){
    case 1:
        do {
int volbapoctu = 0;
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
        default:
            cout<< "Proti tolika nepratelum nelze bojovat"<<endl;
            break;
        }
    }while (pocetzivotu > 0 && MZivoty > 0);
    break;
    case 2:
        obchod();
        break;
    default: cout<< "Neplatna volba..."<<endl;
}
}while (level < 12);
return 0;
}
