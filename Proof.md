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

Each `get` in sequential history is defined by the number of preceding increments. Since we can compute the result of `get` from the original history, let's put each `get() == N` in sequential history after exactly `N` increments. 

If `Inc_j` finished before `get_i` invocation in the original history, then `get_i` result is not less than `j`, therefore it stays after `Inc_j` in our constructed history. If `get_i` finished before `Inc_j` invocation, then `get_i` result is less than `j` and it stays before `Inc_j`. So, the last condition of linearizability is satisfied. □

What changes if, instead of `inc()`, the counter has a method `inc(delta: Int)`, which atomically increments the counter on a non-negative `delta`? The counter with this modification becomes not linearizable. 

*Proof.* Consider concurrent execution of `inc(1)`, `inc(2)` and `get()`, where `inc(1)` modifies `A[0]` and `inc(2)` modifies `A[1]`, with the following history:

```
get()
    sum := 0
    sum += A[0]     // sum == 0
inc(1)
    i := random(K)  // i == 0
    FAA(&A[0], 1)
inc(2)
    i := random(K)  // i == 1
    FAA(&A[1], 2)
get()  // continuation
    sum += A[1]     // sum == 2
    return sum      // 2
```

Suppose there exists a sequential history which also produces `get() == 2`. By linearizability condition `inc(1)` must precede `inc(2)`, since `inc(1)` finished execution before invocation of `inc(2)`. So, there are 3 possible sequential histories:

```
get()   // 0
inc(1)
inc(2)
```

```
inc(1)
get()   // 1
inc(2)
```

```
inc(1)
inc(2)
get()   // 3
```

None of these histories produce `get() == 2`, so, we found a counterexample and the modified counter is not linearizable. □