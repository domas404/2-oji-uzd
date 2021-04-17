# 2-oji-užduotis

Programos versija v1.0

Ši versija skirta programos spartumo testavimui ir palyginimui, naudojant skirtingus duomenų saugojimo konteinerius (std::vector, std::deque, std::list).

Sistemos parametrai:

      • CPU Intel i5-10300H 2.50GHz
      • RAM 16GB 2666MHz
      • SSD 512GB

Testo rezultatai, kai:

      • namų darbų skaičius kiekvienam studentui - 10;
      • galutinis pažymys skaičiuojamas pagal vidurkį.

| Vector                             | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ---------------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Skirstymas 1 strategija            |
| Skirstymas 2 strategija            | 0.00000 | 0.00100 | 0.00982 | 0.09855   | 0.98102    |
| 1 strategijos visas veikimo laikas |
| 2 strategijos visas veikimo laikas | 0.02316 | 0.20158 | 1.75329 | 18.47490  | 191.93179  |

| Vector                      | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| --------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas ir skaičiavimai | 0.00897 | 0.07644 | 0.73332 | 7.49821   | 73.51260   |
| Rikiavimas                  | 0.00262 | 0.03698 | 0.47337 | 6.23004   | 76.34202   |
| Skirstymas                  | 0.00000 | 0.00199 | 0.02304 | 0.25325   | 2.62937    |
| Viso:                       | 0.01159 | 0.11541 | 1.22973 | 13.98150  | 152.48399  |

| Deque                       | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| --------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas ir skaičiavimai | 0.00988 | 0.08303 | 0.76314 | 7.42392   | 75.20338   |
| Rikiavimas                  | 0.00194 | 0.04109 | 0.50099 | 6.32580   | 79.82032   |
| Skirstymas                  | 0.00000 | 0.00200 | 0.02655 | 0.27487   | 2.85571    |
| Viso:                       | 0.01182 | 0.12612 | 1.29068 | 14.02459  | 157.87941  |

| List                        | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| --------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Nuskaitymas ir skaičiavimai | 0.01588 | 0.08302 | 0.77093 | 7.69200   | 72.21972   |
| Rikiavimas                  | 0.00100 | 0.00679 | 0.09059 | 1.12389   | 13.82365   |
| Skirstymas                  | 0.00000 | 0.00299 | 0.05583 | 0.43409   | 4.30531    |
| Viso:                       | 0.01688 | 0.09280 | 0.91735 | 9.25998   | 90.34868   |

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
