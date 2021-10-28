# MyBlockchain - Mano supaprastinta blokų grandinė.
### Versija 0.01  
Pradėtas blokų grandinės kūrimas. Tai bus supaprastinta blokų grandinė, kuriai bus naudojama mano sukurta hash funkcija (hash.cpp).
### Versija 0.02  
Pateikti blokų grandinės "griaučiai" - pati idėja kaip bus įgyvendinama blokų grandinė.   
### Versija 0.03  
Susieta blokų grandinė su hash funkcija.   
# Versija 0.1   
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
# Versija 0.2  
#### Apie mano blokų grandinę:  
Mano blokų grandinė naudoja mano kurtą hash'inimo funkciją.   
Blokų grandinė realizuota naudojant klases. Yra blokų, vartotojų bei transakcijų klasės. Paeiliui yra imami iš tekstinių failų duomenys ir kai užpildoma blokų klasė atitinkamais kintamaisiais sukurtas blokas išvedamas į tekstinį failą. Taip išvedami visi blokai, kurie yra saugomi BlockChainInfo.txt.  
#### Kaip naudotis:  
Prieš paleidžiant programą pirmiausia reikia turėti transakcijų pool'ą. Pavyzdys: Transactions.txt. Pavyzdyje pateikti 30 transakcijų pool'as.  
Taip pat reikia turėti vartotojų pool'ą. Pavyzdys: Users.txt. Bei info.txt faile turi būti įrašytas 0, jeigu blokų grandinėje nėra blokų, tik GenesisBlock. (Faile info.txt saugomas skaičius - kiek yra blokų blokų grandinėje).  
Taip pat pačioje programoje galime pakeisti šiuos kintamuosius:  
TBlock - atspindi kiek transakcijų laiko vienas blokas.  
BlockSk - atspindi kiek naujų blokų bus sukurta.  
Turint visus šiuos duomenis galime paleisti į terminalą parašant šias komandas:  
 g++ -std=c++11 main.cpp -o main  ./main  
 ### Blokų grandinės funkcijos:  
 #### Blokų grandinės laikomi duomenys:  
 Bloko pavadinimas, transakcijos, bloko hash'as, praeito bloko hash'as, laiko žymė, "nonce", versija.  
 Patobulinti: pridėti difficulty target.  
 #### Vartotojai:  
 Vartotojai turi vardą bei savo balansą, kuris yra atnaujinamas atlikus transakcijas.  
 Patobulinti: pridėti viešajį bei privatųjį raktus.  
 #### Transakcijos:  
 Transakcijos rašomos tokiu formatu: Vardas skaičius Vardas. Pirmasis vardas tai vartotojo, kuris siunčia pinigus, antrasis vardas tai gavėjo vardas. O skaičius tai siunčiama suma.  
 Patobulinti: transakcijų siuntėjas bei gavėjas būtų atskiriamas pagal savo public key, o ne vardą.  
 #### Bloko hash gavimas:  
 Bloko hashas gaunamas sudėjus visas transakcijas ir gautą string atidavus kaip įvestį hash funkcijai.  
 Patobulinti: realizuoti Merkle tree.  
 #### Balanso atnaujinimas:  
 Kuriant naują bloką yra įvykdomos transakcijos. Įvykdant transakciją iš pirmoje vietoje įrašyto vartotojo atimama pervedimo sumo, o prie antroje vietoje įrašyto vartotojo balanso pridedama pervedimo suma.
 #### Transakcijų verifikavimas:  
 Prieš įvykdant transakciją yra patikrinama ar transakcija yra validi. Patikrinama ar siuntėjas (pirmoje vietoje įrašytas vartotojas) turi tiek pinigų savo balansę. Pavyzdžiui: Margarita 5 Aistis. Margarita balansas = 2. Transakcija nevalidi, nes Margarita neturi 5 pinigų savo balanse. 
 Patobulinti: įgyvendinti transakcijų hash'o tikrinimą.  
 #### Išvedimas:  
 Blokai ir visa jų laikoma informacija išvedami į tekstinį failą BlockChainInfo.txt.  
 Vartotojų atnaujinti balansai išvedami į tekstinį failą NewBalance.txt. Balansai išvedami sukūrus tiek blokų kiek buvo nustatyta.  
 Kiek jau sukurtą blokų šioje blokų grandinėje išvedama į tekstinį failą info.txt.  
 Patobulinimai: transakcijos būtų atnaujinamos po kiekvieno bloko įvykdytų transakcijų.  
 #### Patobulinimai:  
 Įgyvendinti mining.
