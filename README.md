## Grammar
```
B  ::= { SS } | SS
SS ::= S \n SS | ε
S  ::= A | E | IF | W
IF ::= if E B EI EL
EI ::= else if E B EI EL | ε
EL ::= else | ε
W  ::= while E B
A  ::= ID = E A'
A' ::= , A | ε
E  ::= L E'
E' ::= + L E' | - L E' | ε
L  ::= R L' 
L' ::= and R L' | or R L' | ε
R  ::= T R'
R' ::= < T R' | > T R' | <= T R' | >= T R' | == T R' | != T R' | ε
T  ::= P T'
T' ::= * P T' | / P T' | % P T' | ε
P  ::= F P'
P' ::= ^ F P' | ε
F  ::= ( E ) | IL | BL | ID

IL ::= [0-9]+
ID ::= [a-zA-Z_][a-zA-Z0-9_]*
BL ::= ^(true|false)$
SL ::= '([^']*)'
```
---
## Build
```
git clone https://github.com/reiscaslureis/lycc.git
cd lycc
mkdir build
cd build
```
### CMake
```
cmake ..
cmake --build .
```
### Command-Line
```
g++ -std=c++17 ../src/*.cpp ../src/scanner/*.cpp -o lycc -I ../include
```
---
## Use
### Simple Usage
At this moment, lycc has only lexical analysis, and you can scan from file or one-line Eession
```
./lycc '<one-line Eession>'
```
```
./lycc <file>.lyc
```
### Flags
- `--scanner` or `-s` prints all tokens the language recognizes