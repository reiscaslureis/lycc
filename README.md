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
### Build
```
git clone https://github.com/reiscaslureis/lycc.git
cd lycc
```
- #### CMake
```
mkdir build
cd build
cmake ..
cmake --build .
```
- #### Command-Line
```
mkdir build
cd build
g++ -std=c++17 ../src/*.cpp ../src/scanner/*.cpp -o lycc -I ../include
```
