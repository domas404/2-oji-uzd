# 2-oji-užduotis

Programos versija v0.5

Ši versija skirta programos spartumo testavimui.

Testo rezultatai, kai:

      • namų darbų skaičius kiekvienam studentui - 10;
      • galutinis pažymys skaičiuojamas pagal vidurkį.
      
Sistemos parametrai:

      • CPU Intel i5-10300H 2.50GHz
      • RAM 16GB 2666MHz
      • SSD 512GB

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

| Deque          | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| -------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas    | 0.00196 | 0.00997 | 0.09674 | 0.92955   | 9.20981    |
| Rikiavimas     | 0.00299 | 0.03594 | 0.47972 | 6.23536   | 76.95899   |
| Skirstymas     | 0.00000 | 0.00299 | 0.02697 | 0.27430   | 3.05681    |
| Viso:          | 0.00495 | 0.04890 | 0.60342 | 7.43921   | 89.22562   |

| List           | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| -------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas    | 0.00098 | 0.01097 | 0.10375 | 1.06116   | 10.17448   |
| Rikiavimas     | 0.00000 | 0.00698 | 0.08278 | 1.08909   | 14.82660   |
| Skirstymas     | 0.00000 | 0.00299 | 0.04087 | 0.40889   | 4.22648    |
| Viso:          | 0.00098 | 0.02095 | 0.22741 | 2.55914   | 29.22756   |

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
