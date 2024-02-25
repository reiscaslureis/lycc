## Grammar
```EBNF
<Stmts>   ::= <Stmt> ";" <Stmts> | ε
<Stmt>    ::= <Assign> | <Expr> | <Output>
<Output>  ::= "output" ( <StrLit> | <Expr> ) <OutputP>
<OutputP> ::= ( <StrLit> | <Expr> ) <OutputP> | ε
<Assign>  ::= <Id> "=" <Expr>
<Expr>    ::= <Logic> <ExprP>
<ExprP>   ::= ("+" | "-") <Logic> <ExprP> | ε
<Logic>   ::= <Rel> <LogicP>
<LogicP>  ::= ("and" | "or") <Rel> <LogicP> | ε
<Rel>     ::= <Term> <RelP>
<RelP>    ::= ("<" | ">" | "<=" | ">=" | "==" | "!=") <Term> <RelP> | ε
<Term>    ::= <Poten> <TermP>
<TermP>   ::= ("*" | "/" | "%") <Poten> <TermP> | ε
<Poten>   ::= <Factor> <PotenP>
<PotenP>  ::= "^" <Factor> <PotenP> | ε
<Unary>   ::= ( "++" | "--" ) <Id> | <Factor>
<Factor>  ::= "(" <Expr> ")" | <Id> | <IntLit> | <BooLit> | <StrLit>
<Id>      ::= <Letter> { <Letter> | <Digit> }
<IntLit>  ::= <Digit> { <Digit> }
<BooLit>  ::= "true" | "false"
<StrLit>  ::= "'" <Ascii> { <Ascii> } "'"
<Digit>   ::= "0" | "1" | ... | "9"
<Letter>  ::= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" | "_"
<Ascii>   ::= " " | "!" | """ | "#" | "$" | ... | "ÿ" |
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
./lycc "<one-line Expression>"
```
```
./lycc <file>.lyc
```
### Flags
- `--scanner` or `-s` prints all tokens the language recognizes