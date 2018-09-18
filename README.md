# Aula-5-Vetorizacao
Como dever de casa você deve ter estudado a aula da profa Mary Hall [aqui](./http://www.cs.utah.edu/~mhall/cs4230f12/CS4230-L19.mov)
e os slides [aqui](./http://www.cs.utah.edu/~mhall/cs4230f12/CS4230-L19.pdf)

Hoje vamos seguir o roteiro do [PRACE Summer of HPC 2017](./https://events.prace-ri.eu/event/590/session/14/#20170705) para exercitar esse conteúdo.

1. Verifique que o icc/icpc está instalado: 
```bash
$icpc -v
```
2. Compile os exemplos com: 
```bash
$icpc -O3 -msse3 -qopt-report=5 arq.c 
```
```bash
$icpc -O3 -xcore-avx2 -qopt-report=5 arq.c 
```
```bash
$gcc -O2 -ftree-vectorize -mavx2 -fopt-info-all arq.c
```
3. Extraia os arquivos do lab Vectorization_Hands_on.tar.bz2 a um subdiretório no seu home folder.
## Actividade 1 - Vectorização com o Intel C++ Compiler ##

Atividade 3:
1. Verifique que o Intel Advisor está disponível:
```bash
$advixe -cl --version
```
