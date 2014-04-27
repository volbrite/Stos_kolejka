set terminal eps font ",10" linewidth 3
set output 'Sprawozdanie_STOS_LISTA-gnuplottex-fig1.eps'
set multiplot layout 1,2 title "Zestawienie działania algorytmów - 20 powtórzeń - czas ogólny."
set datafile separator ';'
set ylabel 'Czas [s]'
set xlabel 'Ilość przypisanych danych'
set xtics ('1k' 1000, '5k' 5000, '10k' 10000, '20k' 20000, '30k' 30000)
unset key
plot 'wyniki_0.csv' title "Zwiększanie +1" with linespoints lt 1

unset key
plot 'wyniki_1.csv' using 1:2 title "Zwiększanie x2" with linespoints lt 2 , 'wyniki_2.csv' using 1:2 title "Lista" with linespoints lt 3
unset multiplot
