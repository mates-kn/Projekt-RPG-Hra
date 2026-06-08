RPG Arena Game (C++)

Jednoduchá textová RPG hra vytvořená v jazyce C++. Hráč si vybere jednu ze tří tříd postavy, bojuje v aréně proti monstrům, získává zkušenosti, vylepšuje své statistiky v obchodě a postupně se propracuje až k finálnímu bossovi.

Funkce hry
3 hratelné třídy:
Knight
Tank
Assasin
Soubojový systém založený na životech a stamině
Získávání XP a levelování
Obchod s vylepšováním statistik
2 minibossové
Finální boss Oddound s unikátní mechanikou
Jeden život – po smrti hra končí
Jak hrát
Výběr třídy

Na začátku hry si hráč vybere jednu ze tří tříd:

Knight
HP: 100
Stamina: 50
Damage: 20
Schopnost: Ohnivý meč (35 damage)
Tank
HP: 120
Stamina: 40
Damage: 25
Schopnost: Strong Punch (40 damage)
Assasin
HP: 90
Stamina: 60
Damage: 15
Schopnost: Movement Confusion (30 damage)
Souboje

Během souboje může hráč:

Útočit (-5 stamina)
Odpočívat (+10 stamina)
Použít schopnost (-25 stamina)

Za vítězství získává peníze a zkušenosti.

Obchod

Ve vesnici lze za získané peníze vylepšovat:

Maximální životy
Maximální staminu
Damage
Damage schopnosti

Každé vylepšení navíc přidává XP.

Bossové
Miniboss 1
Každý třetí útok způsobí dvojnásobné poškození.
Miniboss 2
Každý třetí útok si obnoví 10 životů.
Oddound (Finální boss)

Oddound mění své chování podle typu poškození, které obdrží.

Pokud dostane sudé poškození:
Příští zásah do něj způsobí dvojnásobné poškození.
Pokud dostane liché poškození:
Jeho příští útok způsobí dvojnásobné poškození.

Oddound si při útoku losuje dvě náhodná čísla a podle jejich parity vypočítává poškození různými způsoby.

Autor

Matěj Kníže

Školní projekt vytvořený v jazyce C++.
