set title 'Execution Time Comparison'
set xlabel 'Test Number'
set ylabel 'Time (seconds)'
plot 'execution_times.txt' using 1:2 title 'Iterative' with lines,\
     'execution_times.txt' using 1:3 title 'Recursive' with lines
pause -1
