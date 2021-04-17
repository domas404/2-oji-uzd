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

| Deque                              | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ---------------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Skirstymas 1 strategija            | 
| Skirstymas 2 strategija            | 0.00000 | 0.00200 | 0.01166 | 0.14151   | 1.19002    |
| 1 strategijos visas veikimo laikas | 
| 2 strategijos visas veikimo laikas | 0.02170 | 0.18563 | 1.78000 | 18.75997  | 192.80805  |

| List                               | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ---------------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Skirstymas 1 strategija            | 
| Skirstymas 2 strategija            | 0.00000 | 0.00199 | 0.02728 | 0.29258   | 2.88519    |
| 1 strategijos visas veikimo laikas | 
| 2 strategijos visas veikimo laikas | 0.02066 | 0.16116 | 1.54519 | 15.71893  | 157.29910  |

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
