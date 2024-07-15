# algorithm
<details> 
<summary><h2><b>stable matching</b></h2></summary> 

## Gale-Shapley algorithm
[UVa-1175](https://github.com/kerong2002/algorithm/blob/main/stable%20matching/UVa-1175.cpp)
```c=
initial each person to free
while (some man m is free and hasn't proposed to every woman) do
  w = highest ranked woman in m's list to whom m has not yet proposed
  if (w is free) then
    (m, w) become engaged
  else if (w prefer m to her fiance m') then
    (m, w) become engaged
    m' become free
return the set S of engaged paris
```


</details>
