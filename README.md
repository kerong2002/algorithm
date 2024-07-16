# algorithm
<details> 
<summary><h2><b>stable matching</b></h2></summary> 

## Gale-Shapley algorithm
[UVa-1175](https://github.com/kerong2002/algorithm/blob/main/stable%20matching/UVa-1175.cpp)
```c=
Gale-Shapley algorithm
1. initial each person to free
2. while (some man m is free and hasn't proposed to every woman) do
3.   w = highest ranked woman in m's list to whom m has not yet proposed
4.   if (w is free) then
5.     (m, w) become engaged
6.   else if (w prefer m to her fiance m') then
7.     (m, w) become engaged
8.     m' become free
9. return the set S of engaged pairs
```


</details>
