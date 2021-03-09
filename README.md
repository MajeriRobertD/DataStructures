# DataStructures

# ADT SparseMatrix - representation using triples (value≠ 0).

# Implementation on a doubly linked list with dynamic

# allocation.

# ADT SparseMatrix:

The ADT Matrix is a container that represents a two-dimensionalarray.
Each element has a unique position, determined bytwo indexes: its line and
column.
If the Matrix contains many values of 0 (or 0TElem),we have a **sparse
matrix** , where it is more (space) efficient to memorizeonly the elements that
are different from 0.

# Domain

```
MAT = {mat|mat is a matrix with elements of the typeTElem}
```
# Interface.

# ● init(mat, nrL, nrC):

```
○ descr: creates a new matrix with a given number oflines and
columns
○ pre: nrL ∈ N ∗ and nrC ∈ N ∗
○ post: mat ∈ MAT , mat is a matrix with nrL lines andnrC
columns
○ throws: an exception if nrL or nrC is negative orzero
```
# ● nrLines(mat):

```
○ descr : returns the number of lines of the matrix
○ pre : mat ∈ MAT
○ post : nrLines ← returns the number of lines from mat
```

# ● nrCols(mat):

```
○ descr : returns the number of columns of the matrix
○ pre : mat ∈ MAT
○ post : nrCols ← returns the number of columns frommat
```
# ● element(mat, i, j):

```
○ descr : returns the element from a given position fromthe matrix
(assume 1-based indexing)
○ pre : mat ∈ MAT , 1 ≤ i ≤ nrLines, 1 ≤ j ≤ nrColumns
○ post : element ← the element from line i and columnj
○ throws : an exception if the position (i, j) is notvalid (less than 1 or
greater than nrLines/nrColumns)
```
# ● modify(mat, i, j, val):

```
○ descr : sets the element from a given position to agiven value
(assume 1-based indexing)
○ pre : mat ∈ MAT , 1 ≤ i ≤ nrLines, 1 ≤ j ≤ nrColumns,val ∈
TElem
○ post : the value from position (i, j) is set to val.modify ← the old
value from position (i, j)
○ throws : an exception if position (i, j) is not valid(less than 1 or
greater than nrLine/nrColumns)
```
# ● iterator(mat, it):

```
○ descr : returns an iterator over the sparse matrix
○ pre : mat ∈ MAT
○ post : it ∈ I, it is an iterator over mat
```

# ADT SparseMatrix - operation implementation

```
subalgorithm init(mat, nrL, nrC) is:
mat.head ← NULL
mat.tail ← NULL
mat.nrL ← nrL
mat.nrC ← nrC
Complexity :θ(1)
```
**function nrLines(mat) is:**
nrLines <- mat.nrL
Complexity :θ(1)

**function nrColumns(mat) is:**
nrColumns <- mat.nrC
Complexity :θ(1)

**function element(mat, i, j) is:
if** i < 1 OR j < 1 OR i > mat.nrLines OR j > mat.nrColumns **then**
@throw exception
**end-if**
current← mat.head
//look for the element. Stopif we passed the position where it
should be
**while** current != NULL AND ([current].line< i OR ([current].line
= i AND [current].column < j)) **execute**
current ← [current].next
**end-while**
//check if we found the element
**if** current != NULL AND [current].line= i AND [current].column =
j **then**


```
element ← [current].info
else
element ← NULL TVALUE
```
```
end-if
End-function
```
Complexity:
Best case: the current element is NIL => :θ(1)
Worst case: the element is on the last position =>O(numberof non-zero
elements)
Average case: O(number of non-zero elements)

```
function modify(mat, i, j, value) is:
if i < 1 OR j < 1 OR i > mat.nrLines OR j > mat.nrColumns then
@throw exception
end-if
current← mat.head
```
```
while current != NULL AND ([current].line < i OR([current].line
= i AND [current].column < j)) execute
current ← [current].next
end-while
```
**if** current != NULL AND [current].line= i AND [current].column =
j **then**
old ← [current].info
[current].info ← value
return old

```
else
modify ← NULL TVALUE
end-if
```

```
end-function
```
Complexity:
Best case: the head is NIL => :θ(1)
Worst case: the element is on the last position =>O(numberof non-zero
elements)
Average case: O(number of non-zero elements)

# Iterator domain

```
I = { it | it is an iterator over a sparse matrix}
```
# Iterator interface

# ● init(it, mat):

```
○ descr : creates a new iterator for a multimap
○ pre : mat is Sparse Matrix
○ post : it ∈ I
```
# ● getCurrent(it):

```
○ descr : returns the current element from the iterator
○ pre : it ∈ I, it is valid
○ post : getCurrent ←<i, j ,v> , i is a line(int), jis a
column(int), v is a TValue
○ throws : an exception if it is invalid
```
# ● next(it):

```
○ descr : moves the current element from the containerto the
next triple or makes the iterator invalid if no triplesare left
○ pre : it ∈ I, it is valid
```

```
○ post : the current element from it points to the next element
from the sparse matrix
○ throws : an exception if it is invalid
```
# ● valid(it):

```
○ descr: verifies if the iterator is valid
○ pre: it ∈ I
○ post: valid ←
○ True, if it points to a valid element from
the container
○ False, otherwise
```
# Sparse Matrix representation

# Node:

```
info: TElem
line: Integer
column: Integer
next: ↑ Node
prev: ↑ Node
```
# Sparse Matrix:

```
head: ↑ Node
tail:↑ Node
nrLines: Integer
```

```
nrColumns: Integer
```
# Iterator representation

# Iterator:

```
mat: SparseMatrix
currentElement: ↑ Node
```
# Problem Statement:

```
A hotel has a huge parking lot. This parking lotworks in the following
```
way: a client checks in, the valet takes the car andparks it wherever he finds a
free spot, and assigns to that position the licenseplate number. When the client
wants to check out, he goes to the reception and asksthe receptionist where the
car with his unique license plate is. Now, the receptionistneeds this awesome
application that lets her iterate only through theoccupied parking spots, until
she finds the client’s car

# Justification:

A SparseMatrix is a smart choice, because this parkinglot is set out like a
matrix, with lines , columns and a value: the licenseplate number. Also, we are
only interested in the occupied positions in orderto find a car fast and save
memory.
