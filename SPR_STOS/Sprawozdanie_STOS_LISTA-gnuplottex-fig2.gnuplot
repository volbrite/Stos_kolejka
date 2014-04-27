set terminal eps font ",11" linewidth 2
set output 'Sprawozdanie_STOS_LISTA-gnuplottex-fig2.eps'
set multiplot layout 1,2 title "Zestawienie działania algorytmów - 20 powtórzeń - czasy poszczególnych przypisań."
set datafile separator ';'
set ylabel 'Czas [s]'
set xlabel 'Ilość przypisanych danych'

unset key
set title "100 elementów"
plot '1/100_WYNIKI_1.csv' title "Zwiększanie x2" with linespoints lt 2, '2/100_WYNIKI_2.csv' title "Lista" with linespoints lt 3
unset title

unset key
set title "2 000 elementów"
plot '1/2000_WYNIKI_1.csv' with linespoints lt 2, '2/2000_WYNIKI_2.csv' with linespoints lt 3
unset title
unset multiplot
