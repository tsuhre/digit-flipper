# digit-flipper
### What is the smallest number *x* where moving the last digit to the front gives you $`2x`$? Small personal for-fun project in C++.
## About the Problem
This problem is pretty self-explanatory: do there exist numbers where moving the last digit to the front doubles the number, and if so, what is the smallest one? For example, $`x=25`$ is close: moving the 5 from the end to the front gives you 52, and $`2x=50`$. So, there must be a pretty small number to which this applies to, right? Nope! For this project, I had to represent *x* with a `long long`, rather than a regular `int`, which would have been nowhere near large enough to find the answer.
### Some Math
Unfortunately, this problem is part math, part programming. We have to do the math to understand the problem before we can start programming. Here is the problem represented algebraically:

$$
2x=10^{n-1}d+p
$$

where

$$
x=10p+d
$$

In these equations, *x* is the number we are trying to find, *p* is *x* without the last digit, *d* is the last digit of *x*, and *n* is the number of digits in *x*. We can now manipulate these equations using some algebra:

$$
2(10p+d)=10^{n-1}d+p
$$

$$
20p+2d=10^{n-1}d+p
$$

Combine like terms:

$$
19p=d(10^{n-1}-2)
$$

$$
p=\frac{d(10^{n-1}-2)}{19}
$$

Now we can make a few deductions. Since we know that *p* is a whole number (it's just *x* without the last digit), we know that the entire right side of the equation is a whole number. For this to be true, $`d(10^{n-1}-2)`$ must be a multiple of 19. However, we also know that *d* is a single-digit number 1-9 (if it were 0, moving it to the front of *x* could not result in $`2x`$). Because 19 is prime and $`d<19`$, we know that *d* cannot be a factor or multiple of 19, and we can ignore it. This means that we are left with just $`10^{n-1}-2`$ being a multiple of 19, which can be expressed as

$$
(10^{n-1}-2)\bmod{19}=0
$$

or

$$
10^{n-1}-2 \equiv 0\pmod{19}
$$

Moving the 2 to the other side, we get

$$
10^{n-1} \equiv 2\pmod{19}
$$

This congruency is what my `findMinN()` function is built around.
## How it Works
I broke this problem into two major steps. First, I find *n*, the smallest number of digits for which the aforementioned congruency can be true. Then, I use *n* to search for *x*, the actual number. This way, I don't have to check nearly as many numbers and I know how many digits my result should have.
### `findMinN()`
This function begins with two variables: `n`, which starts at 1, and `rem`, which also starts at 1. `rem` is short for remainder, and it tracks the current value of $`10^{n-1}\bmod{19}`$. I use a `while` loop to evaluate the expression $`10^{n-1}\bmod{19}`$ at every value of `n` until it finds one where `rem` = 2. However, with exponents, numbers get pretty big, pretty fast. To avoid calculating something like $`10^{17}\bmod{19}`$, I can use this property of modular arithmetic:

$$
((a\bmod{m})\times(b\bmod{m}))\bmod{m}=(a\times b)\bmod{m}
$$

This means that instead of having to check huge numbers, I can just keep multiplying `rem` by 10 and recalculating the remainder. Here's what I mean:

Let's say we already have the remainder when $`n=3`$. $`10^{3-1}=100`$, and $`100\bmod{19}=5`$. Instead of now calculating the remainder for $`n=4`$, or $`10^{4-1}=1000`$, I can say that $`a=100`$, $`b=10`$, and $`m=19`$, and use the formula above:

$$
((100\bmod{19})\times(10\bmod{19}))\bmod{19}=(100\times 10)\bmod{19}
$$

We already know $`100\bmod{19}=5`$, and $`10\bmod{19}`$ is just 10, so

$$
(5\times10)\bmod{19}=(100\times 10)\bmod{19}
$$

$$
50\bmod{19}=1000\bmod{19}
$$

Just by using this property, we've gone from a 4-digit number to a 2-digit number, and this benefit only gets more apparent as numbers scale. Finally, we can run `findMinN()` to find that the lowest number of digits *x* can have is a whopping 18!
### `findX()`

### Output
Given the nature of the problem, this program produces the same output every time, displaying the values of *n*, *x*, and $`2x`$. I lined up the values of *x* and $`2x`$ so that it was clear how the digits were manipulated.
```
Minimum digits of x: 18
 x =  105263157894736842
2x = 210526315789473684
```
Note: This program could probably be modified to find multiple results pretty easily, but I have achieved what I set out to do.
## How to Run It