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