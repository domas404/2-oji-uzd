# 2-oji-užduotis

Programos versija v0.4.1

Pakeitimai nuo v0.4:

      • Pakeista studentų skirstymo funkcija;
      • Aptvarkytas programos kodas (pašalinti keli nenaudojami kintamieji)

Ši versija skirta programos spartumo testavimui.

|                               | 1'000  | 10'000 | 100'000 | 1'000'000 | 10'000'000 |
| ----------------------------- | :---:  | :---:  | :---:   | :---:     | :---:      |
| Sąrašo generavimas            | 0.02   | 0.102  | 0.91    | 8.921     | 88.129     |
| Nuskaitymas ir skaičiavimai   | 0.013  | 0.079  | 0.764   | 7.849     | 73.637     |
| Rikiavimas                    | 0.012  | 0.142  | 1.771   | 20.861    | 256.911    |
| Skirstymas                    | 0      | 0.004  | 0.047   | 0.471     | 4.846      |
| Kietiakų įrašymas             | 0.01   | 0.052  | 0.384   | 3.69      | 36.304     |
| Varguolių įrašymas            | 0.008  | 0.036  | 0.276   | 2.706     | 25.712     |
| Viso:                         | 0.069  | 0.435  | 4.207   | 44.729    | 487.367    |

Programos veikimas:

Programa sugeneruoja 5 skirtingų dydžių studentų sąrašus ir apskaičiuoja studentų galutinius
įvertinimus pagal sugeneruotus duomenis (namų darbų ir egzamino įvertinimus).
Pagal galutinius įvertinimus studentai suskirstomi į dvi grupes:
      1) "kietiakai" - kurių galutinis įvertinimas >= 5;
      2) "varguoliai" - kurių įvertinimas < 5.

Diegimas ir paleidimas:

   Atsisiųskite ir išarchyvuokite release'o zip failą.
   Atverkite komandinę eilutę (cmd) ir nurodykite šio failo adresą kompiuteryje.

        cd /.../'folder_name'

   Į komandinę eilutę įveskite šias komandas:

        g++ -c calculations.cpp testing.cpp
        g++ -o main main.cpp calculations.o testing.o
        
   Paleidžiant programą nurodykite:
      1) kiek generuojamame studentų sąraše kiekvienas studentas turi namų darbų;
      2) įvertinimų skaičiavimui naudoti vidurkį ar medianą [v/m].
   Pvz:
   
        ./main 10 v
        
   Taip pat galite pasinaudoti makefile'u:
      
        mingw32-make
        ./main 10 v
