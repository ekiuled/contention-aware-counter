```
A := int[K]

fun inc() { 
    i := random(K)
    FAA(&A[i], 1)
}

fun get() { 
    sum := 0
    for (i := 0; i < K; i++)
        sum += A[i]
    return sum
}
```

This counter implementation is linearizable. 

*Proof.* Consider any concurrent history of operations on the counter. To prove linearizability we must construct a corresponding sequential history that produces the same results and preserves ordering of any two operations A and B, such that A finished execution before invocation of B in the original history.

We will order all increments in order of their `FAA`s in the history, this ordering satisfies the last condition. Denote this ordering as `Inc_1`, ..., `Inc_k`.

Each `get` in sequential history is defined by the number of preceding increments. Since we can compute the result of `get` from the original history, let's put each `get()=N` in sequential history after exactly `N` increments. 

If `Inc_j` finished before `get_i` invocation in the original history, then `get_i` result is not less than `j`, therefore it stays after `Inc_j` in our constructed history. If `get_i` finished before `Inc_j` invocation, then `get_i` result is less than `j` and it stays before `Inc_j`. So, the last condition of linearizability is satisfied.