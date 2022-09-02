#!/bin/bash

mkdir -p logs;

make;
./ft_exec_vector > ./logs/ft_exec.log;
make std;
./std_exec_vector > ./logs/std_exec.log;
diff ./logs/ft_exec.log ./logs/std_exec.log > ./logs/trace;
more ./logs/trace
