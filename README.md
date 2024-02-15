```
EXPRESSION      -> TERM EXPRESSION'
EXPRESSION'     -> + TERM EXPRESSION' | - TERM EXPRESSION' | ε
TERM            -> POWER TERM'
TERM'           -> * POWER TERM' | / POWER TERM' | % POWER TERM' | ε
POWER           -> FACTOR POWER'
POWER'          -> ^ FACTOR POWER' | ε
FACTOR          -> ( EXPRESSION ) | INTEGER_LITERAL
INTEGER_LITERAL -> DIGIT+
DIGIT           -> 0 | 1 | ... | 9
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
