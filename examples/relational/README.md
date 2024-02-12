```
8 > 6
```
```
MOV A, 8
SUB A, 6
MOV B, no_assignment_boolean_01
CALL greater_than

HLT

logical_operations:
	MOV [B], 0
	RET

	greater_than:
		CALL logical_operations
		JA is_true
		RET
	
	is_true:
		MOV [B], 1
		RET

no_assignment_boolean_01: DB 0
```
---
```
8 < 6
```
```
MOV A, 8
SUB A, 6
MOV B, no_assignment_boolean_01
CALL less_than

HLT

logical_operations:
	MOV [B], 0
	RET

	less_than:
		CALL logical_operations
		JB is_true
		RET
	
	is_true:
		MOV [B], 1
		RET

no_assignment_boolean_01: DB 0	
```
---
```
6 >= 8
```
```
MOV A, 6
SUB A, 8
MOV B, no_assignment_boolean_01
CALL greater_than_or_equal

HLT

logical_operations:
	MOV [B], 0
	RET

	greater_than_or_equal:
		CALL logical_operations
		JAE is_true
		RET
	
	is_true:
		MOV [B], 1
		RET

no_assignment_boolean_01: DB 0
```
---
```
6 <= 8
```
```
MOV A, 6
SUB A, 8
MOV B, no_assignment_boolean_01
CALL less_than_or_equal

HLT

logical_operations:
	MOV [B], 0
	RET

	less_than_or_equal:
		CALL logical_operations
		JBE is_true
		RET
	
	is_true:
		MOV [B], 1
		RET

no_assignment_boolean_01: DB 0
```
---
```
10 == 10
```
```
MOV A, 10
SUB A, 10
MOV B, no_assignment_boolean_01
CALL equal_to

HLT

logical_operations:
	MOV [B], 0
	RET

	equal_to:
		CALL logical_operations
		JE is_true
		RET
	
	is_true:
		MOV [B], 1
		RET

no_assignment_boolean_01: DB 0
```
---
```
10 != 10
```
```
MOV A, 10
SUB A, 10
MOV B, no_assignment_boolean_01
CALL not_equal_to

HLT

logical_operations:
	MOV [B], 0
	RET

	not_equal_to:
		CALL logical_operations
		JNE is_true
		RET
	
	is_true:
		MOV [B], 1
		RET

no_assignment_boolean_01: DB 0
```
---
```
80 > 20 <= 10 >= 30 < 200 == 100 != 60
```
```
MOV A, 80
SUB A, 20
MOV B, no_assignment_boolean_01
CALL greater_than

MOV A, 20
SUB A, 10
MOV B, no_assignment_boolean_02
CALL less_than_or_equal
MOV A, [no_assignment_boolean_01]
AND A, [no_assignment_boolean_02]
MOV [no_assignment_boolean_07], A

MOV A, 10
SUB A, 30
MOV B, no_assignment_boolean_03
CALL greater_than_or_equal
MOV A, [no_assignment_boolean_02]
AND A, [no_assignment_boolean_03]
MOV [no_assignment_boolean_07], A

MOV A, 30
SUB A, 200
MOV B, no_assignment_boolean_04
CALL less_than
MOV A, [no_assignment_boolean_03]
AND A, [no_assignment_boolean_04]
MOV [no_assignment_boolean_07], A

MOV A, 200
SUB A, 100
MOV B, no_assignment_boolean_05
CALL equal_to
MOV A, [no_assignment_boolean_04]
AND A, [no_assignment_boolean_05]
MOV [no_assignment_boolean_07], A

MOV A, 100
SUB A, 60
MOV B, no_assignment_boolean_06
CALL not_equal_to
MOV A, [no_assignment_boolean_05]
AND A, [no_assignment_boolean_06]
MOV [no_assignment_boolean_07], A

HLT

logical_operations:
	MOV [B], 0
	RET

	greater_than:
		CALL logical_operations
		JA is_true
		RET

	greater_than_or_equal:
		CALL logical_operations
		JAE is_true
		RET

	less_than:
		CALL logical_operations
		JB is_true
		RET

	less_than_or_equal:
		CALL logical_operations
		JBE is_true
		RET

	equal_to:
		CALL logical_operations
		JE is_true
		RET				

	not_equal_to:
		CALL logical_operations
		JNE is_true
		RET
	
	is_true:
		MOV [B], 1
		RET

no_assignment_boolean_01: DB 0
no_assignment_boolean_02: DB 0
no_assignment_boolean_03: DB 0
no_assignment_boolean_04: DB 0
no_assignment_boolean_05: DB 0
no_assignment_boolean_06: DB 0
no_assignment_boolean_07: DB 0
```