#!/bin/bash

mkdir -p logs;

make;
./ft_exec > ./logs/ft_exec.log;
make std;
./std_exec > ./logs/std_exec.log;
diff ./logs/ft_exec.log ./logs/std_exec.log > ./logs/trace;
more ./logs/trace
