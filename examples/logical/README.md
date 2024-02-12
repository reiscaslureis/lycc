```
false and false
```
```
MOV A, 0
AND A, 0
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
false and true
```
```
MOV A, 0
AND A, 1
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
true and false
```
```
MOV A, 1
AND A, 0
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
true and true
```
```
MOV A, 1
AND A, 1
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
false or false
```
```
MOV A, 0
OR A, 0
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
false or true
```
```
MOV A, 0
OR A, 1
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
true or false
```
```
MOV A, 1
OR A, 0
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
true or true
```
```
MOV A, 1
OR A, 1
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```
---
```
false and true and false or true
```
```
MOV A, 0
AND A, 1
MOV [no_assignment_boolean_01], A

MOV A, [no_assignment_boolean_01]
AND A, 0
MOV [no_assignment_boolean_01], A

MOV A, [no_assignment_boolean_01]
OR A, 1
MOV [no_assignment_boolean_01], A

HLT

no_assignment_boolean_01: DB 0
```