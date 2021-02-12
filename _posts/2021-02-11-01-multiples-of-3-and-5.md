---
layout: post
mathjax: true
category: resolved
---
**Problem 01**  
[https://projecteuler.net/problem=01](https://projecteuler.net/problem=01)

<p>If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.</p>
<p>Find the sum of all the multiples of 3 or 5 below 1000.</p>
---

**Code**  `python`

```python
if __name__ == '__main__':
    s = 0
    for i in range(1000):
        if i % 3 == 0 or i % 5 == 0:
            s += i
    print(s)
```