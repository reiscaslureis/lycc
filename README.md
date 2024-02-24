## Grammar
```EBNF
<Block>  ::= "{" Stmts "}" | Stmts
<Stmts>  ::= Stmt ";" Stmts | ε
<Stmt>   ::= Assign | If | While
<If>     ::= "if" Expr Block Elif Else
<Elif>   ::= "else if" Expr Block Elif Else | ε
<Else>   ::= "else" Block | ε
<While>  ::= "while" Expr Block
<Assign> ::= Id "=" <Expr>
<Expr>   ::= <Logic> <ExprP>
<ExprP>  ::= ("+" | "-") <Logic> <ExprP> | ε
<Logic>  ::= <Rel> <LogicP>
<LogicP> ::= ("and" | "or") <Rel> <LogicP> | ε
<Rel>    ::= <Term> <RelP>
<RelP>   ::= ("<" | ">" | "<=" | ">=" | "==" | "!=") <Term> <RelP> | ε
<Term>   ::= <Poten> <TermP>
<TermP>  ::= ("*" | "/" | "%") <Poten> <TermP> | ε
<Poten>  ::= <Factor> <PotenP>
<PotenP> ::= "^" <Factor> <PotenP> | ε
<Factor> ::= "(" Expr ")" | Id | IntLit | BooLit
<Id>     ::= Letter { Letter | Digit }
<IntLit> ::= Digit { Digit }
<BooLit> ::= "true" | "false"
<Digit>  ::= "0" | "1" | ... | "9"
<Letter> ::= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" | "_"
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
At this moment, lycc has only lexical analysis, and you can scan from file or one-line Expression
```
./lycc '<one-line Expression>'
```
```
./lycc <file>.lyc
```
### Flags
- `--scanner` or `-s` prints all tokens the language recognizes
