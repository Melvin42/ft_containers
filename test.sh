#!/bin/bash

make;
./ft_exec > ft_exec.log;
make std;
./std_exec > std_exec.log;
diff ft_exec.log std_exec.log > trace;
more trace
