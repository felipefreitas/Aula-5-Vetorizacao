# Aula-5-Vetorizacao

Exercícios tomados de [PRACE Summer of HPC 2017](./https://events.prace-ri.eu/event/590/session/14/#20170705)

1. Verifique se o icc/icpc está instalado: 
```bash
$icpc -v
```
2. Compile os exemplos com 
```bash
$icpc -O3 -msse3 -qopt-report=5 arq.c 
```
```bash
$icpc -O3 -xcore-avx2 -qopt-report=5 arq.c 
```
```bash
$gcc -O2 -ftree-vectorize -mavx2 -fopt-info-all arq.c
```
