#!/bin/sh
## runtests.sh for  in /home/bongol_b/ProjetsPerso/my_malloc
## 
## Made by Berdrigue Bongolo-Beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Tue Nov 22 17:46:22 2016 Berdrigue Bongolo-Beto
## Last update Thu Nov 24 20:36:50 2016 Berdrigue Bongolo-Beto
##

echo "Run tests."

export LD_LIBRARY_PATH=$HOME/ProjetsPerso/my_malloc/:$LD_LIBRARY_PATH

make re

./test
