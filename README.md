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
      • prieš skirstymą studentai yra surikiuojami pagal galutinį įvertinimą

| Vector                             | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ---------------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Skirstymas 1 strategija            | 0.00100 | 0.00199 | 0.02393 | 0.23096   | 2.28685    |
| Skirstymas 2 strategija            | 0.00000 | 0.00100 | 0.00982 | 0.09855   | 0.98102    |

| Deque                              | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ---------------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Skirstymas 1 strategija            | 0.00000 | 0.00200 | 0.03036 | 0.27351   | 2.76711    |
| Skirstymas 2 strategija            | 0.00000 | 0.00200 | 0.01166 | 0.14151   | 1.19002    |

| List                               | 1'000   | 10'000  | 100'000 | 1'000'000 | 10'000'000 |
| ---------------------------------- | :---:   | :---:   | :---:   | :---:     | :---:      |
| Skirstymas 1 strategija            | 0.00000 | 0.00399 | 0.05894 | 0.58437   | 6.00405    |
| Skirstymas 2 strategija            | 0.00000 | 0.00199 | 0.02728 | 0.29258   | 2.88519    |

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

        mingw32-make
        ./main 10 v
        
   Paleidžiant programą nurodomi:
      1) kiek generuojamame studentų sąraše kiekvienas studentas turi namų darbų;
      2) įvertinimų skaičiavimui naudoti vidurkį ar medianą [v/m].
   Pvz:
   
        ./main 10 v
