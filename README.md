# 2-oji-užduotis

Programos versija v0.4.1

Pakeitimai nuo v0.4:

      • Pakeista studentų skirstymo funkcija;
      • Aptvarkytas programos kodas (pašalinti keli nenaudojami kintamieji)

Ši versija skirta programos spartumo testavimui.

Testo rezultatai, kai:

      • namų darbų skaičius kiekvienam studentui - 10;
      • galutinis pažymys skaičiuojamas pagal vidurkį.

|                               | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ----------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Sąrašo generavimas            | 0.01396 | 0.10231 | 0.87791 | 8.85506   | 90.23230   |
| Nuskaitymas ir skaičiavimai   | 0.00897 | 0.07782 | 0.78274 | 8.11333   | 74.79004   |
| Rikiavimas                    | 0.01000 | 0.12400 | 1.71300 | 20.95400  | 249.91700  |
| Skirstymas                    | 0.00000 | 0.00419 | 0.04719 | 0.45146   | 5.12625    |
| "Kietiakų" įrašymas           | 0.00997 | 0.05613 | 0.37632 | 3.65941   | 37.20836   |
| "Varguolių" įrašymas          | 0.00798 | 0.03594 | 0.26254 | 2.63883   | 27.28866   |
| Viso:                         | 0.05984 | 0.43184 | 4.12496 | 44.87665  | 486.56214  |

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
