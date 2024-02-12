```
2 + 3
```
```
MOV A, 2
ADD A, 3
MOV [no_assignment_integer_01], A

HLT

no_assignment_integer_01: DB 0
```
---
```
10 - 4
```
```
MOV A, 10
SUB A, 4
MOV [no_assignment_integer_01], A

HLT

no_assignment_integer_01: DB 0
```
---
```
10 * 4
```
```
MOV A, 10
MUL A, 4
MOV [no_assignment_integer_01], A

HLT

no_assignment_integer_01: DB 0
```
---
```
20 / 5
```
```
MOV A, 20
DIV A, 5
MOV [no_assignment_integer_01], A

HLT

no_assignment_integer_01: DB 0
```
---
```
100 % 23
```
```
MOV A, 100
DIV 23
MUL 23
MOV B, 100
SUB B, A
MOV [no_assignment_integer_01], B

HLT

no_assignment_integer_01: DB 0
```
---
```
2 ^ 7
```
```
MOV A, 2
MOV B, A
MOV C, 7
CALL calculate_exponential

HLT

calculate_exponential:
	MUL B
	DEC C
	CMP C, 1
	JNZ calculate_exponential
	MOV [no_assignment_integer_01], A
	RET

no_assignment_integer_01: DB 0
```
---
```
(5 - 2) ^ 2 ^ 2 - (100 - ((2 * 20) - (10 % 3)) / 3) % 10
```
```
MOV A, 5
SUB A, 2
MOV [no_assignment_integer_01], A

MOV A, 2
MUL 20
MOV [no_assignment_integer_02], A

MOV A, 10
DIV 3
MUL 3
MOV B, 10
SUB B, A
MOV [no_assignment_integer_03], B

MOV A, [no_assignment_integer_02]
SUB A, [no_assignment_integer_03]
MOV [no_assignment_integer_04], A

MOV A, [no_assignment_integer_04]
DIV 3
MOV [no_assignment_integer_05], A

MOV A, 100
SUB A, [no_assignment_integer_05]
MOV [no_assignment_integer_06], A

MOV A, [no_assignment_integer_01]
MOV B, A
MOV C, 2
CALL calculate_exponential
MOV [no_assignment_integer_07], A

MOV A, [no_assignment_integer_07]
MOV B, A
MOV C, 2
CALL calculate_exponential
MOV [no_assignment_integer_08], A

MOV A, [no_assignment_integer_06]
DIV 10
MUL 10
MOV B, [no_assignment_integer_06]
SUB B, A
MOV [no_assignment_integer_09], B

MOV A, [no_assignment_integer_08]
SUB A, [no_assignment_integer_09]
MOV [no_assignment_integer_10], A

HLT

calculate_exponential:
	MUL B
	DEC C
	CMP C, 1
	JNZ calculate_exponential
	RET

no_assignment_integer_01: DB 0
no_assignment_integer_02: DB 0
no_assignment_integer_03: DB 0
no_assignment_integer_04: DB 0
no_assignment_integer_05: DB 0
no_assignment_integer_06: DB 0
no_assignment_integer_07: DB 0
no_assignment_integer_08: DB 0
no_assignment_integer_09: DB 0
no_assignment_integer_10: DB 0
```