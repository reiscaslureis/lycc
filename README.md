## Grammar
```
S  -> A | E
A  -> ID = E A'
A' -> , A | ε
E  -> L E'
E' -> + L E' | - L E' | ε
L  -> R L' 
L' -> and R L' | or R L' | ε
R  -> T R'
R' -> < T R' | > T R' | <= T R' | >= T R' | == T R' | != T R' | ε
T  -> P T'
T' -> * P T' | / P T' | % P T' | ε
P  -> F P'
P' -> ^ F P' | ε
F  -> ( E ) | IL | BL | ID

IL -> D+
ID -> LT (LT | D)*
BL -> true | false

D  -> 0 | 1 | ... | 9
LT -> a | b | ... | z | A | B | ... Z | _
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
At this moment, lycc has only lexical analysis, and you can scan from file or one-line expression
```
./lycc '<one-line expression>'
```
```
./lycc <file>.lyc
```
### Flags
- `--scanner` or `-s` prints all tokens the language recognizes