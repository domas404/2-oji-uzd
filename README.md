# 2-oji-užduotis

Programos versija v0.4.1

Pakeitimai nuo v0.4:

      • Pakeista studentų skirstymo funkcija;
      • Aptvarkytas programos kodas (pašalinti keli nenaudojami kintamieji)

Ši versija skirta programos spartumo testavimui.

|                               | 1'000 | 10'000 | 100'000 | 1'000'000 | 10'000'000 |
| ----------------------------- | ----- | ------ | ------- | --------- | ---------- |
| Sąrašo generavimas            | 0.02  | 0.102  | 0.91    | 8.921     | 88.129     |
| Nuskaitymas ir skaičiavimai   | 0.764  | 0.102  | 0.91    | 8.921     | 88.129     |
| Rikiavimas                    | 1.771  | 0.102  | 0.91    | 8.921     | 88.129     |
| Skirstymas                    | 0.047  | 0.102  | 0.91    | 8.921     | 88.129     |
| Kietiakų įrašymas             | 0.384  | 0.102  | 0.91    | 8.921     | 88.129     |
| Varguolių įrašymas            | 0.276  | 0.102  | 0.91    | 8.921     | 88.129     |

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
