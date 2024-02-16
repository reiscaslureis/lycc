```
E  -> R E'
E' -> + R E' | - R E' | ε
R  -> L R'
R' -> < L R' | > L R' | <= L R' | >= L R' | == L R' | != L R' | ε
L  -> T L' 
L' -> and T L' | or T L' | ε
T  -> P T'
T' -> * P T' | / P T' | % P T' | ε
P  -> F P'
P' -> ^ F P' | ε
F  -> ( E ) | IL | BL

IL     -> D+
BL     -> true | false

D  -> 0 | 1 | ... | 9
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
At this moment, lycc compiler has only lexical analysis, and you can scan from file or one-line expression
```
./lycc '<one-line expression>'
```
```
./lycc <file>.lyc
```
### Flags
- `--scanner` or `-s` prints all tokens the language recognizes
