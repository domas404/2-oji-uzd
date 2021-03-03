# 2-oji-užduotis

Programos versija v0.1.2

Pakeitimai nuo versijos v0.1.1:

      • Ištaisytos dinaminės atminties panaudojimo klaidos;
      • Dabar rikiavimui naudojama implementuota sort() funkcija iš standartinės šablonų bibliotekos;
      • Minimalūs pataisymai medianos ir vidurkio skaičiavimo funkcijose;

Ši programa apskaičiuoja studento galutinį įvertinimą pagal įvestus duomenis (namų darbų ir egzamino įvertinimus) ir pateikia rezultatą lentelėje.

Diegimas ir paleidimas:

   Atsisiųskite ir išarchyvuokite release'o zip failą.
   Atverkite komandinę eilutę (cmd) ir nurodykite 'main.cpp' failo adresą kompiuteryje.

        cd /.../'folder_name'

   Į komandinę eilutę įveskite šias komandas:

        g++ main.cpp -o main
        ./main
 
Naudojimasis:
 
  Paleidus programą, vadovaukitės programos nurodymais ir įveskite reikiamus duomenis.
  
Namų darbų įvertinimus galima įvesti keliais būdais:
      
      • Žinant įvertinimų kiekį, bet nežinant įvertinimų (bus atsitiktinai sugeneruojami);
      • Žinant ir įvertinimų kiekį ir visus įvertinimus;
      • Nežinant įvertinimų kiekio, bet žinant visus įvertinimus.

Egzamino įvertinimą taip pat galima įvesti keliais būdais:
      
      • Žinant įvertinimą;
      • Nežinant įvertinimo (bus atsitiktinai sugeneruojamas).
