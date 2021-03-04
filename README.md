# 2-oji-užduotis

Programos versija v0.3

Pakeitimai nuo versijos v0.2:

      • Programa suskaidyta į skirtingus *.cpp ir *.h tipo failus.
      • Naudojamos "exceptions":
            1) tikrinant ar nuskaitymo metu pavyksta atidaryti skaitomąjį failą;
            2) tikrinant ar vartotjo suvedinėjami įvertinimai patenka į intervalą [1; 10];
      • Pakoreguota programos struktūra;

Ši programa apskaičiuoja studento galutinį įvertinimą pagal vartotojo įvestus arba iš failo nuskaitytus
duomenis (namų darbų ir egzamino įvertinimus) ir pateikia rezultatus lentelės forma.

Diegimas ir paleidimas:

   Atsisiųskite ir išarchyvuokite release'o zip failą.
   Atverkite komandinę eilutę (cmd) ir nurodykite šio failo adresą kompiuteryje.

        cd /.../'folder_name'

   Į komandinę eilutę įveskite šias komandas:

        g++ -c functions.cpp functions_for_files.cpp
        g++ -o main main.cpp functions.o functions_for_files.o
        ./main
 
Naudojimasis:
 
  Paleidus programą, vadovaukitės programos nurodymais ir įveskite reikiamus duomenis.
  
Programai paskirti duomenis galima trimis būdais:

      • Visus duomenis suvedinėti rankiniu būdu;
      • Nuskaityti duomenis iš egzistuojančio tekstinio failo;
      • Nuskaityti duomenis iš naujo failo, sugeneruoto pagal pasirinktus parametrus;

Duomenų įvedimas rankiniu būdu:

      Namų darbų įvertinimus galima įvesti keliais būdais:
      
      • Žinant įvertinimų kiekį, bet nežinant įvertinimų (bus atsitiktinai sugeneruojami);
      • Žinant ir įvertinimų kiekį ir visus įvertinimus;
      • Nežinant įvertinimų kiekio, bet žinant visus įvertinimus.

      Egzamino įvertinimą taip pat galima įvesti keliais būdais:
      
      • Žinant įvertinimą;
      • Nežinant įvertinimo (bus atsitiktinai sugeneruojamas).
