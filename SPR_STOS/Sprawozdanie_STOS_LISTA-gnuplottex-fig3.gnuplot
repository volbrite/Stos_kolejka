set terminal eps font ",11" linewidth 2
set output 'Sprawozdanie_STOS_LISTA-gnuplottex-fig3.eps'
set multiplot layout 2,2 title "Zestawienie działania algorytmów - 20 powtórzeń - czasy poszczególnych przypisań."
set datafile separator ';'
set ylabel 'Czas [s]'
set xlabel 'Numer danego przypisania'

unset key
set title "6 000 elementów"
plot '1/6000_WYNIKI_1.csv' title "Zwiększanie x2" with linespoints lt 2, '2/6000_WYNIKI_2.csv' title "Lista" with linespoints lt 3
unset title

unset key
set title "10 000 elementów"
plot '1/10000_WYNIKI_1.csv' with linespoints lt 2, '2/10000_WYNIKI_2.csv' with linespoints lt 3

unset key
set title "20 000 elementów"
plot '1/20000_WYNIKI_1.csv' with linespoints lt 2, '2/20000_WYNIKI_2.csv' with linespoints lt 3

unset key
set title "30 000 elementów"
plot '1/30000_WYNIKI_1.csv' with linespoints lt 2, '2/30000_WYNIKI_2.csv' with linespoints lt 3


unset title
unset multiplot
