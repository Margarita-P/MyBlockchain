# MyBlockchain - Mano supaprastinta blokų grandinė.
### Versija 0.01  
Pradėtas blokų grandinės kūrimas. Tai bus supaprastinta blokų grandinė, kuriai bus naudojama mano sukurta hash funkcija (hash.cpp).
### Versija 0.02  
Pateikti blokų grandinės "griaučiai" - pati idėja kaip bus įgyvendinama blokų grandinė.   
### Versija 0.03  
Susieta blokų grandinė su hash funkcija.   
## Versija 0.1   
Realizuota blokų grandinė.  
Blokų grandinė naudoja mano sukurtą "hash" funkciją.  
Blokų grandinė turi detalų "output'inimą": Išvedamas bloko "vardas" (kelintas tai blokas), transakcijos (šiuo metu tik trys), šio bloko hash'as, praeito bloko hash'as, laiko žymė (angl. TimeStamp), bei identifikatorius (angl. Nonce). Vardas naudojamas, kad būtų lengviau atskirti tekstiniame faile kada prasideda sekantis blokas.  
Pavyzdys "output'inimo" : BlockchainInfo.txt.  
Faile matomi tik 10 blokų pateiktų kaip pavyzdys, ir kiekvienas iš blokų šiuo metu turi tik 3 transakcijas, kurių užtenka pavyzdžiui.  
#### Apie realizaciją:   
Vietoj Merkle tree šioje versijoje bloko hash'as apskaičiuojamas sudėjus visas transakcijas.  
Nonce šiuo metu yra unikalus skaičius, priskiriamas nuo 1 pridedant 1.  
Kiekvienas blokas turi praeito bloko hash'ą, tačiau Block1 ima GenesisBlock hash'ą, kuris yra hardcodint'as.  
Transakcijos imamos iš tekstinio failo Users.txt.  
Pačiai realizacijai naudojama klasė, ir blokai išvedami į rezultatų failą - BlockChainInfo.txt.  
#### Kas bus tobulinama:  
Bus pridedama versija bei "Difficulty target".  
Bloko hash'as bus apskaičiuojamas pasitelkiant Merkle tree.  
Bus daugiau transakcijų laikoma viename bloke.  
Bus įvykdita transakcijų verifikavimo funkcija, "mining" funkcija.  
Bus sukurtas pool'as transakcijų bei naudotojų su savais raktais, balansu.  
### Versija 0.12  
Šioje versijoje realizuoti vartotojai, juos galima rasti Users.txt, o transakcijos saugomos dabar Transactions.txt.  
Taip pat realizuota transakcijų verifikavimo sistema.  
#### Apie realizaciją:  
Vartotojai imami iš Users.txt failo, įvedami į atskirą klasę.  
Transakcijos imamos iš Transactions.txt failo, įvedamos į atskirą klasę.  
Vartotojų balansas yra atnaujinamas vykdant transakcijas - įvedant jas į blokus. Prieš atnaujinant balansą, kiekviena transakcija yra verifikuojama - patikrinama, ar vartotojas turi užtektinai pinigų, kad galėtų atlikti mokėjimą.
