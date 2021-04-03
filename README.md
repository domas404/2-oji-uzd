# 2-oji-užduotis

Programos versija v0.5

Ši versija skirta programos spartumo testavimui.

Testo rezultatai, kai:

      • namų darbų skaičius kiekvienam studentui - 10;
      • galutinis pažymys skaičiuojamas pagal vidurkį.

| Vector                        | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ----------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas ir skaičiavimai   | 0.02254 | 0.07891 | 0.73814 | 7.29165   | 74.09560   |
| Rikiavimas                    | 0.00299 | 0.03409 | 0.45263 | 5.89147   | 73.69695   |
| Skirstymas                    | 0.00100 | 0.00399 | 0.04679 | 0.44981   | 4.81296    |
| Viso:                         | 0.02753 | 0.12170 | 1.26257 | 13.80058  | 154.34750  |

| Deque                         | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ----------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas ir skaičiavimai   | 0.01001 | 0.08181 | 0.74305 | 7.46251   | 77.02090   |
| Rikiavimas                    | 0.00399 | 0.03690 | 0.48769 | 6.49257   | 79.62870   |
| Skirstymas                    | 0.00010 | 0.00499 | 0.05488 | 0.63598   | 6.23764    |
| Viso:                         | 0.01695 | 0.12867 | 1.30997 | 14.80641  | 165.89919  |

| List                          | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ----------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas ir skaičiavimai   | 0.01027 | 0.07978 | 0.76877 | 7.70479   | 75.01005   |
| Rikiavimas                    | 0.00000 | 0.00736 | 0.08156 | 1.21034   | 14.2828    |
| Skirstymas                    | 0.00097 | 0.00580 | 0.06289 | 0.68737   | -          |
| Viso:                         | 0.01366 | 0.09802 | 0.96975 | 10.12359  | -          |

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
