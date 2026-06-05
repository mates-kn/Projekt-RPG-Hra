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
int MZivoty = 0;
        int maxpocziv = 0;
        int maxstamina = 0;
        int maxdamage = 0;
        int maxschopnost = 0;
        int penize = 0;
        int xp = 0;
        int level = 1;
        int levelUP = 300;
int MB1Ziv = 120;
int pocetutokuMB1 = 1;
bool MB1 = false;
        bool Hracnazivu = true;
int MB2Ziv = 140;
int pocetutokuMB2 = 1;
bool MB2 = false;



void knight(){
    cout << endl << "KNIGHT je takova nejvic balanced class. Na zacatku hry mate tyto staty:" << endl;
    cout << "Max pocet zivotu: 100" << endl;
    cout << "Max stamina: 50" << endl;
    cout << "Zakladni damage: 20" << endl;
    cout << "Zacatecni schopnost: Ohnivy mec (35 damage)" << endl;
}
void tank(){
    cout << endl << "TANK ma vice zivotu, vetsi damage ale mene stamina. Na zacatku hry mate tyto staty:" << endl;
    cout << "Max pocet zivotu: 120" << endl;
    cout << "Max stamina: 40" << endl;
    cout << "Zakladni damage: 25" << endl;
    cout << "Zacatecni schopnost: Strong punch (40 damage)" << endl;
}
void assasin(){
    cout << endl << "ASSASIN ma mene zivotu, mene damage ale vice stamina. Na zacatku hry mate tyto staty:" << endl;
    cout << "Max pocet zivotu: 90" << endl;
    cout << "Max stamina: 60" << endl;
    cout << "Zakladni damage: 15" << endl;
    cout << "Zacatecni schopnost: Movement confusion (30 damage)" << endl;
}




void boj (){
    do{
        bool revive = true;
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
                if (stamina > maxstamina) stamina = maxstamina;
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





void miniboss1 (){
cout << "-------------------------------------\n";
cout << "          !!!POZOR!!!"<<endl;
cout << "Ted te ceka tvuj prvni bossfight s Minibossem 1.\n Jeho utoky jsou kazdy 3 utok dvojnasobne!";
    do{
        int UtokMB1 = 0;
        cout << "\n-------------------------------------\n";
        cout << "Tvoje zivoty: " << pocetzivotu << endl;
        cout << "Tvoje stamina: " << stamina << endl;
        cout << "Zivoty minibosse: " <<  MB1Ziv<< endl;

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
                    MB1Ziv -= damage;
                    stamina -= 5;
                } else {
                    cout << "Nemas dost stamina!\n";
                }
                break;

            case 2:
                cout << "Odpocivas a doplnujes stamina.\n";
                stamina += 10;
                if (stamina > maxstamina) stamina = maxstamina;
                break;

            case 3:
                if (stamina >= 25){
                    cout << "Pouzivas schopnost za " << schopnost << " damage!\n";
                    MB1Ziv -= schopnost;
                    stamina -= 25;
                } else {
                    cout << "Nemas dost stamina na schopnost!\n";
                }
                break;

            default:
                cout << "Neplatna volba!\n";
        }
        if (MB1Ziv >= 1){
            if(pocetutokuMB1 < 3){
                UtokMB1 += 15;
                cout << "Miniboss utoci za " << UtokMB1 << " damage!\n";
                pocetzivotu -= UtokMB1;
                pocetutokuMB1++;
            }
            else{
                UtokMB1 += 30;
                cout << "Miniboss utoci za " << UtokMB1 << " damage!\n";
                pocetzivotu -= UtokMB1;
                pocetutokuMB1 = 1;
            }
        }
if (MB1Ziv < 1){
    cout <<endl<< "VYHRAL JSI PRVNI BOSSFIGHT! Staty se ti tentokrat doplni automaticky :)"<< endl;
    penize += 200;
    xp += 200;
    pocetzivotu = maxpocziv;
    stamina = maxstamina;
    damage = maxdamage;
    schopnost = maxschopnost;
    MB1 = true;
}
if (pocetzivotu < 1){
    cout <<endl<< "Prohral jsi souboj! Bohuzel jsi umrel..."<< endl;
    Hracnazivu = false;
}
    }while (pocetzivotu > 0 && MB1Ziv > 0);
}



void miniboss2(){

cout << "-------------------------------------\n";
cout << "          !!!POZOR!!!"<<endl;
cout << "Ted te bossfight s Minibossem 2.\n Kazdy 3 utok si dobije 10 zivotu!!!";
    do{
        int UtokMB2 = 0;
        cout << "\n-------------------------------------\n";
        cout << "Tvoje zivoty: " << pocetzivotu << endl;
        cout << "Tvoje stamina: " << stamina << endl;
        cout << "Zivoty minibosse: " <<  MB2Ziv<< endl;

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
                    MB2Ziv -= damage;
                    stamina -= 5;
                } else {
                    cout << "Nemas dost stamina!\n";
                }
                break;

            case 2:
                cout << "Odpocivas a doplnujes stamina.\n";
                stamina += 10;
                if (stamina > maxstamina) stamina = maxstamina;
                break;

            case 3:
                if (stamina >= 25){
                    cout << "Pouzivas schopnost za " << schopnost << " damage!\n";
                    MB2Ziv -= schopnost;
                    stamina -= 25;
                } else {
                    cout << "Nemas dost stamina na schopnost!\n";
                }
                break;

            default:
                cout << "Neplatna volba!\n";
        }
        if (MB2Ziv >= 1){
            if(pocetutokuMB2 < 3){
                UtokMB2 += 30;
                cout << "Miniboss utoci za " << UtokMB2 << " damage!\n";
                pocetzivotu -= UtokMB2;
                pocetutokuMB2++;
            }
            else{
                UtokMB2 += 30;
                cout << "Miniboss utoci za " << UtokMB2 << " damage!\n";
                pocetzivotu -= UtokMB2;
                pocetutokuMB2 = 1;
                MB2Ziv += 10;
            }
        }
if (MB2Ziv < 1){
    cout <<endl<< "VYHRAL JSI PRVNI BOSSFIGHT! Staty se ti tentokrat doplni automaticky :)"<< endl;
    penize += 300;
    xp += 350;
    pocetzivotu = maxpocziv;
    stamina = maxstamina;
    damage = maxdamage;
    schopnost = maxschopnost;
    MB2 = true;
}
if (pocetzivotu < 1){
    cout <<endl<< "Prohral jsi souboj! Bohuzel jsi umrel..."<< endl;
    Hracnazivu = false;
}
    }while (pocetzivotu > 0 && MB2Ziv > 0);
}






void obchod(){
    int volbaUpgr;
    cout << "--------VITEJ V OBCHODE--------" << endl;
    cout << "Tady si muzes vylepsovat svoje staty, za kazdy upgrade \n dostanes taky 25 xp"<<endl;
    cout << "Mas: " <<penize<< " korun"<<endl;
    cout << "Jaky stat si chces vylepsit: "<< endl;
    cout << "1. volba -> +5 zivotu (cena -> 90)" << endl;
    cout << "2. volba -> +5 stamina (cena -> 125)" << endl;
    cout << "3. volba -> +5 damage (cena -> 90)" << endl;
    cout << "4. volba -> +5 schopnost (cena -> 200)" << endl;
    cout << "5. volba -> pokud nic vylepsovat nechces muzes se vratit do vesnice"<< endl;
    cout << "Zadej volbu:";
    cin >> volbaUpgr;
    switch (volbaUpgr){
case 1:
    if (penize >= 90){
        maxpocziv +=5;
        penize -= 90;
        xp += 25;
        cout << "Mas o 5 hp vic."<< endl;
        pocetzivotu=maxpocziv;
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
        stamina = maxstamina;
    }
    else{
        cout << "Nemas dost penez..."<< endl;
    }
    break;
case 3:
    if (penize >= 90){
        penize -= 90;
        maxdamage +=5;
        xp += 25;
        cout << "Budes davat o 5 damage vic."<< endl;
        damage = maxdamage;
    }
    else{
        cout << "Nemas dost penez..."<< endl;
    }
    break;
case 4:
    if (penize >= 200){
        penize -= 200;
        maxschopnost +=5;
        xp += 25;
        cout << "Tvoje schopnost bude ubirat o 5 hp vic."<< endl;
        schopnost = maxschopnost;
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
        maxdamage += 20;
        maxschopnost += 35;
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 2:
        tank();
        maxpocziv += 120;
        maxstamina += 40;
        maxdamage += 25;
        maxschopnost += 40;

        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    case 3:
        assasin();
        maxpocziv += 90;
        maxstamina += 60;
        maxdamage += 15;
        maxschopnost += 30;
        cout << endl << "Opravdu chces tuto postavu? (a/n): ";
        cin >> potvrzeni;
        break;
    default:cout << "Neplatna volba" << endl;
    }
}while (potvrzeni != 'a');
cout << "---------------------------------------------------------------------"<< endl;
cout << "Odted po kazdym souboji pujdes zpet do vesnice, lidi jsou tam moc hodni a po kazdem souboji\n ti vyleci vsechna zraneni jen za 25 korun."<<endl;
    pocetzivotu = maxpocziv;
    stamina = maxstamina;
    damage = maxdamage;
    schopnost = maxschopnost;
do{
if (penize >= 25 && pocetzivotu != maxpocziv){
    cout << "---------------------------------------------------------------------"<< endl;
    char doplneni;
    cout << "Mas: " <<penize<< " korun"<<endl;
    cout << "Chces doplnit staty po souboji za 25 korun?(a/n): ";
    cin >> doplneni;
    switch (doplneni){
case 'a':
    pocetzivotu = maxpocziv;
    stamina = maxstamina;
    damage = maxdamage;
    schopnost = maxschopnost;
    penize -=25;
    break;
case 'n':
    cout << "No kdyz myslis...";
    break;
    }
}




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
        xp = zbytek;
        level++;
        cout << "Ted mas level: " << level<<endl;
        levelUP += 50;
        }




//s funkci continue mi pomohl ChatGPT, 2 hodiny jsem se to snazil opravit sam ale neslo mi to bez AI :(

if(level == 4 && !MB1){
    miniboss1();
    continue;
}
if(level == 8 && !MB2){
    miniboss2();
    continue;
}
cout << "---------------------------------------------------------------------"<< endl;
    cout << "Tvuj level: "<< level << endl;
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
}while (pocetzivotu > 0 && Hracnazivu);
return 0;
}
