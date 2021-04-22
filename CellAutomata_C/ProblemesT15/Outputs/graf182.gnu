y(x) = a + b*x
fit y(x) "hamming_182.dat" u (log($1)):(log($2)) via a,b

plot y(x) title "regression", "hamming_182.dat" u (log($1)):(log($2)) pt 7 ps 0.5 title "ACE 182"
set key bottom
set xlabel "log(T)"
set ylabel "log(H)"
replot

pause -1
set term epslatex color
set output "ACE182.eps"
replot
replot

