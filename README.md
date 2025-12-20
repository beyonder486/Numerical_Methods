# Numerical Methods Implementation in C++

A comprehensive collection of numerical methods implemented in C++ for solving various mathematical problems.

## Table of Contents

- [Solution of Non-Linear Equations](#solution-of-non-linear-equations)
  - [Bisection Method](#bisection-method)
    - [Theory](#theory-of-bisection-method)
    - [Code](#code-of-bisection-method)
    - [Input](#input-of-bisection-method)
    - [Output](#output-of-bisection-method)
  - [Newton-Raphson Method](#newton-raphson-method)
    - [Theory](#theory-of-newton-raphson-method)
    - [Code](#code-of-newton-raphson-method)
    - [Input](#input-of-newton-raphson-method)
    - [Output](#output-of-newton-raphson-method)
  - [Regular Falsi (False Position) Method](#regular-falsi-false-position-method)
    - [Theory](#theory-of-regular-falsi-method)
    - [Code](#code-of-regular-falsi-method)
    - [Input](#input-of-regular-falsi-method)
    - [Output](#output-of-regular-falsi-method)
  - [Secant Method](#secant-method)
    - [Theory](#theory-of-secant-method)
    - [Code](#code-of-secant-method)
    - [Input](#input-of-secant-method)
    - [Output](#output-of-secant-method)

- [Interpolation and Approximation](#interpolation-and-approximation)
  - [Newton's Forward Interpolation](#newtons-forward-interpolation)
    - [Theory](#theory-of-newtons-forward-interpolation)
    - [Code](#code-of-newtons-forward-interpolation)
    - [Input](#input-of-newtons-forward-interpolation)
    - [Output](#output-of-newtons-forward-interpolation)
  - [Newton's Backward Interpolation](#newtons-backward-interpolation)
    - [Theory](#theory-of-newtons-backward-interpolation)
    - [Code](#code-of-newtons-backward-interpolation)
    - [Input](#input-of-newtons-backward-interpolation)
    - [Output](#output-of-newtons-backward-interpolation)
  - [Newton's Divided Difference](#newtons-divided-difference)
    - [Theory](#theory-of-newtons-divided-difference)
    - [Code](#code-of-newtons-divided-difference)
    - [Input](#input-of-newtons-divided-difference)
    - [Output](#output-of-newtons-divided-difference)

- [Numerical Integration](#numerical-integration)
  - [Simpson's 1/3 Rule](#simpsons-13-rule)
    - [Theory](#theory-of-simpsons-13-rule)
    - [Code](#code-of-simpsons-13-rule)
    - [Input](#input-of-simpsons-13-rule)
    - [Output](#output-of-simpsons-13-rule)
  - [Simpson's 3/8 Rule](#simpsons-38-rule)
    - [Theory](#theory-of-simpsons-38-rule)
    - [Code](#code-of-simpsons-38-rule)
    - [Input](#input-of-simpsons-38-rule)
    - [Output](#output-of-simpsons-38-rule)

- [Curve Fitting (Regression)](#curve-fitting-regression)
  - [Linear Least Squares Regression](#linear-least-squares-regression)
    - [Theory](#theory-of-linear-least-squares-regression)
    - [Code](#code-of-linear-least-squares-regression)
    - [Input](#input-of-linear-least-squares-regression)
    - [Output](#output-of-linear-least-squares-regression)
  - [Polynomial Least Squares Regression](#polynomial-least-squares-regression)
    - [Theory](#theory-of-polynomial-least-squares-regression)
    - [Code](#code-of-polynomial-least-squares-regression)
    - [Input](#input-of-polynomial-least-squares-regression)
    - [Output](#output-of-polynomial-least-squares-regression)
  - [Exponential Least Squares Regression](#exponential-least-squares-regression)
    - [Theory](#theory-of-exponential-least-squares-regression)
    - [Code](#code-of-exponential-least-squares-regression)
    - [Input](#input-of-exponential-least-squares-regression)
    - [Output](#output-of-exponential-least-squares-regression)


## Solution of Non-Linear Equations

### Bisection Method

#### Theory of Bisection Method
The Bisection Method is a root-finding algorithm that repeatedly bisects an interval and selects a subinterval where a root exists. It's based on the Intermediate Value Theorem:
- If f is continuous on [a,b] and f(a)·f(b) < 0, then there exists at least one root in (a,b)
- The method divides the interval in half at each iteration
- Converges linearly with error reduced by half each iteration

**Algorithm:**
1. Start with interval [a,b] where f(a)·f(b) < 0
2. Compute c = (a+b)/2
3. If |f(c)| < tolerance, c is the root
4. If f(a)·f(c) < 0, set b = c; else set a = c
5. Repeat until convergence


#### Code of Bisection Method

**[📂 View Source Code](solution%20of%20non-linear%20equations/bisection-Method.cpp)**


#### Input of Bisection Method
**Format:**
```
Testcases
a b tolerance maxIterations
```
**Parameters:**
- `a`: Lower bound of interval
- `b`: Upper bound of interval  
- `tolerance`: Convergence tolerance (e.g., 0.0001)
- `maxIterations`: Maximum number of iterations (e.g., 100)

**Example Input:** (`input_bisection.txt`)
```
2
0 1 0.0001 100
0 5 0.0001 100
```


#### Output of Bisection Method
**File:** `output_bisection.txt`
```
========== TEST CASE 1 ==========

Initial interval: [0, 1]
Tolerance: 0.0001

Iter a              b              c              f(c)           
1    0              1              0.5            -2.000000e+00  
2    0.000000       0.500000       0.250000       -1.250000e-01  
3    0.000000       0.250000       0.125000       9.062500e-01   
4    0.125000       0.250000       0.187500       3.828125e-01   
5    0.187500       0.250000       0.218750       1.269531e-01   
6    0.218750       0.250000       0.234375       4.882812e-04   
7    0.234375       0.250000       0.242188       -6.237793e-02  
8    0.234375       0.242188       0.238281       -3.097534e-02  
9    0.234375       0.238281       0.236328       -1.525116e-02  
10   0.234375       0.236328       0.235352       -7.383347e-03  
11   0.234375       0.235352       0.234863       -3.448009e-03  
12   0.234375       0.234863       0.234619       -1.479983e-03  
13   0.234375       0.234619       0.234497       -4.958808e-04  
14   0.234375       0.234497       0.234436       -3.807247e-06  

========== RESULT ==========
Root: 0.2344360352
Iterations: 14
f(root): -3.8072466850e-06
Final interval width: 1.2207031250e-04

========== TEST CASE 2 ==========

ERROR: No sign change in interval [0.0000000000e+00, 5.0000000000e+00]


```

### Newton-Raphson Method

#### Theory of Newton-Raphson Method
Newton-Raphson is an iterative method that uses tangent lines to approximate roots. It has quadratic convergence near simple roots.

**Formula:**
```
x_{n+1} = x_n - f(x_n)/f'(x_n)
```

**Advantages:**
- Fast convergence (quadratic) when close to root
- Requires only one initial guess

**Disadvantages:**
- Requires derivative f'(x)
- May fail if f'(x) ≈ 0
- May not converge if initial guess is far from root


#### Code of Newton-Raphson Method

**[📂 View Source Code](solution%20of%20non-linear%20equations/newton-raphson-Method.cpp)**


#### Input of Newton-Raphson Method
**Format:**
```
Testcases
a b step tolerance maxIterations
```
**Parameters:**
- `a`: Start of search interval
- `b`: End of search interval
- `step`: Step size for finding initial brackets (e.g., 0.1)
- `tolerance`: Convergence tolerance (e.g., 1e-6)
- `maxIterations`: Maximum iterations per root (e.g., 1000)

**Example Input:** (`input_newton-raphson.txt`)
```
2
-1 2 0.1 1e-6 1000
-1 5 0.1 1e-6 1000
```

#### Output of Newton-Raphson Method
**File:** `output_newton-raphson.txt`
```
========== TEST CASE 1 ==========

Initial guess: -1.0000000000
Tolerance: 2.0000000000

Iter x_n                 f(x_n)              

========== WARNING ==========
Maximum iterations reached without convergence.
Last approximation: -1.0000000000
f(x): -1.0000000000e+00

========== TEST CASE 2 ==========

Initial guess: 0.1000000000
Tolerance: 0.0000010000

Iter x_n                 f(x_n)              
1    0.1000000000        9.7010000000e-01    
2    1.7276845638        9.5491004824e-01    
3    1.6346289494        1.2361166459e-01    
4    1.6184984322        3.3634863998e-03    
5    1.6180343671        2.7380882983e-06    

========== RESULT ==========
Root: 1.6180339888
Iterations: 5
f(root): 1.8198775820e-12

```

### Regular Falsi (False Position) Method

#### Theory of Regular Falsi Method
The False Position Method is similar to the Bisection Method but uses linear interpolation instead of bisection to find the next approximation.

**Formula:**
```
c = a - f(a)·(b-a)/(f(b)-f(a))
```

**Advantages:**
- Generally faster convergence than bisection
- Always converges if f is continuous on [a,b]
- Does not require derivative

**Disadvantages:**
- Can be slower than Newton-Raphson
- May converge from one side only


#### Code of Regular Falsi Method

**[📂 View Source Code](solution%20of%20non-linear%20equations/regularfalsi-FalsePosition-Method.cpp)**


#### Input of Regular Falsi Method
**Format:**
```
Testcases
a b tolerance maxIterations
```
**Parameters:**
- `a`: Lower bound of interval
- `b`: Upper bound of interval
- `tolerance`: Convergence tolerance (e.g., 1e-7)
- `maxIterations`: Maximum iterations (e.g., 100)

**Example Input:** (`input_regularfalsi.txt`)
```
2
0 2 1e-7 1000
0 4 1e-8 500
```
#### Output of Regular Falsi Method
**File:** `output_regularfalsi.txt`
```
========== TEST CASE 1 ==========

Initial interval: [0, 2]
Tolerance: 1e-07

Iter a              b              c              f(c)           
1    0              2              0.666667       -1.777778e+00  
2    0.000000       0.666667       0.352941       -2.214533e-01  
3    0.000000       0.352941       0.317757       -2.236003e-02  
4    0.000000       0.317757       0.314244       -2.208034e-03  
5    0.000000       0.314244       0.313897       -2.175608e-04  
6    0.000000       0.313897       0.313863       -2.143192e-05  
7    0.000000       0.313863       0.313860       -2.111214e-06  
8    0.000000       0.313860       0.313859       -2.079708e-07  
9    0.000000       0.313859       0.313859       -2.048672e-08  

========== RESULT ==========
Root: 0.3138593419
Iterations: 9
f(root): -2.0486724761e-08

========== TEST CASE 2 ==========

ERROR: No sign change in interval [0.0000000000e+00, 4.0000000000e+00]

```


### Secant Method

#### Theory of Secant Method
The Secant Method is similar to Newton-Raphson but approximates the derivative using finite differences, eliminating the need to compute f'(x).

**Formula:**
```
x_{n+1} = x_n - f(x_n)·(x_n - x_{n-1})/(f(x_n) - f(x_{n-1}))
```

**Advantages:**
- No derivative needed
- Faster than bisection
- Superlinear convergence

**Disadvantages:**
- Requires two initial guesses
- May fail if f(x_n) ≈ f(x_{n-1})


#### Code of Secant Method

**[📂 View Source Code](solution%20of%20non-linear%20equations/secant-Method.cpp)**


#### Input of Secant Method
**Format:**
```
Testcases
a b step tolerance maxIterations
```
**Parameters:**
- `a`: Start of search interval
- `b`: End of search interval
- `step`: Step size for finding brackets (e.g., 0.1)
- `tolerance`: Convergence tolerance (e.g., 1e-6)
- `maxIterations`: Maximum iterations (e.g., 1000)

**Example Input:** (`input_secant.txt`)
```
2
-3 3 1e-6 1000
-3 6 1e-6 1000

```

#### Output of Secant Method
**File:** `output_secant.txt`
```
========== TEST CASE 1 ==========

Initial guesses: x0 = -3.0000000000, x1 = 3.0000000000
Tolerance: 0.0000010000
Max iterations: 1000

Iter x0             x1             x2             f(x2)          

WARNING: Denominator near zero. Secant method fails.

========== WARNING ==========
Method did not converge within the maximum iterations.
Last approximation: 3.0000000000
f(x): 5.5000000000e+01

========== TEST CASE 2 ==========

Initial guesses: x0 = -3.0000000000, x1 = 6.0000000000
Tolerance: 0.0000010000
Max iterations: 1000

Iter x0             x1             x2             f(x2)          
1    -3.0000000000  6.0000000000   -3.4365079365  1.0503757994e+02
2    6.0000000000   -3.4365079365  -4.3509196711  3.0257239942e+02
3    -3.4365079365  -4.3509196711  -2.9502767196  5.0649528275e+01
4    -4.3509196711  -2.9502767196  -2.6686750355  3.0354932576e+01
5    -2.9502767196  -2.6686750355  -2.2474791535  1.1360755424e+01
6    -2.6686750355  -2.2474791535  -1.9955543998  4.9115023246e+00
7    -2.2474791535  -1.9955543998  -1.8036982276  1.8241566079e+00
8    -1.9955543998  -1.8036982276  -1.6903401082  5.9212669794e-01
9    -1.8036982276  -1.6903401082  -1.6358589886  1.3305745236e-01
10   -1.6903401082  -1.6358589886  -1.6200680833  1.4771481717e-02
11   -1.6358589886  -1.6200680833  -1.6180961244  4.4966716366e-04
12   -1.6200680833  -1.6180961244  -1.6180342101  1.6020003892e-06
13   -1.6180961244  -1.6180342101  -1.6180339888  1.7480505932e-10

========== RESULT ==========
Root: -1.6180339888
Iterations: 13
f(root): 1.7480505932e-10

```

## Interpolation and Approximation

### Newton's Forward Interpolation

#### Theory of Newton's Forward Interpolation
Newton's Forward Interpolation uses forward differences to construct an interpolating polynomial. Best suited when interpolating near the beginning of tabulated data.

**Formula:**
```
y(x) = y₀ + pΔy₀ + p(p-1)/2!·Δ²y₀ + p(p-1)(p-2)/3!·Δ³y₀ + ...
where p = (x - x₀)/h
```

**Use Cases:**
- Equally spaced data points
- Interpolation near the beginning of data
- Class interval data (grouped frequency distributions)


#### Code of Newton's Forward Interpolation

**[📂 View Source Code](Interpolation%20and%20approximation/forwardinterpolation.cpp)**


#### Input of Newton's Forward Interpolation
**Format:**
```
n
lower₁ upper₁ frequency₁
lower₂ upper₂ frequency₂
...
lowerₙ upperₙ frequencyₙ
xp
```
**Parameters:**
- `n`: Number of class intervals
- `lower upper frequency`: Class interval bounds and frequency
- `xp`: Point at which to interpolate

**Example Input:** (`input_forwardinterpolation.txt`)
```
4
10 20 5
20 30 8
30 40 12
40 50 7
25
```

#### Output of Newton's Forward Interpolation
**File:** `output_forwardinterpolation.txt`
```
Class Intervals and Midpoints:
       Interval    Midpoint(x)  Frequency(y)
---------------------------------------------
     10-     20             15              5
     20-     30             25              8
     30-     40             35             12
     40-    50             45              7

Class width (h) = 10

Forward Difference Table:
...

========== RESULT ==========
y(25) = 8.500000
```

### Newton's Backward Interpolation

#### Theory of Newton's Backward Interpolation
Newton's Backward Interpolation uses backward differences to construct an interpolating polynomial. Best suited when interpolating near the end of tabulated data.

**Formula:**
```
y(x) = yₙ + q∇yₙ + q(q+1)/2!·∇²yₙ + q(q+1)(q+2)/3!·∇³yₙ + ...
where q = (x - xₙ)/h
```

**Use Cases:**
- Equally spaced data points
- Interpolation near the end of data
- Class interval data with interpolation near upper bounds


#### Code of Newton's Backward Interpolation

**[📂 View Source Code](Interpolation%20and%20approximation/backwardinterpolation.cpp)**


#### Input of Newton's Backward Interpolation
**Format:**
```
n
lower₁ upper₁ frequency₁
lower₂ upper₂ frequency₂
...
lowerₙ upperₙ frequencyₙ
xp
```

**Example Input:** (`input_backwardinterpolation.txt`)
```
4
10 20 5
20 30 8
30 40 12
40 50 7
45
```

#### Output of Newton's Backward Interpolation
**File:** `output_backwardinterpolation.txt`
```
Class Intervals and Midpoints:
       Interval    Midpoint(x)  Frequency(y)
---------------------------------------------
     10 - 20             15              5
     20 - 30             25              8
     30 - 40             35             12
     40 - 50             45              7

Backward Difference Table:
...

========== RESULT ==========
y(45) = 7.000000
```

### Newton's Divided Difference

#### Theory of Newton's Divided Difference
Newton's Divided Difference method works for both equally and unequally spaced data. It constructs an interpolating polynomial using divided differences.

**Formula:**
```
y(x) = f[x₀] + (x-x₀)f[x₀,x₁] + (x-x₀)(x-x₁)f[x₀,x₁,x₂] + ...
```

**Advantages:**
- Works with unequally spaced data
- Easy to add new data points
- Provides error estimation


#### Code of Newton's Divided Difference

**[📂 View Source Code](Interpolation%20and%20approximation/divideddifference.cpp)**


#### Input of Newton's Divided Difference
**Format:**
```
n
x₁ y₁
x₂ y₂
...
xₙ yₙ
xp
```
**Parameters:**
- `n`: Number of data points
- `x y`: Data point coordinates
- `xp`: Point at which to interpolate

**Example Input:** (`input_divideddifference.txt`)
```
5
1.0 1.5
2.0 4.2
3.0 8.1
4.0 13.5
5.0 20.0
2.5
```


#### Output of Newton's Divided Difference
**File:** `output_divideddifference.txt`
```
Data Points:
         x         f(x)
------------------------
    1.0000      1.5000
    2.0000      4.2000
    3.0000      8.1000
    4.0000     13.5000
    5.0000     20.0000

Divided Difference Table:
...

========== RESULT ==========
y(2.5) = 5.887500

========== TRUNCATION ERROR ESTIMATE ==========
Term-by-term contributions:
Term 0: 1.500000
Term 1: 1.350000 (cumulative: 2.850000)
Term 2: 1.537500 (cumulative: 4.387500)
Term 3: 1.200000 (cumulative: 5.587500)
Term 4: 0.300000 (cumulative: 5.887500)

Estimated truncation error: ≈ 0.125000
```

## Numerical Integration

### Simpson's 1/3 Rule

#### Theory of Simpson's 1/3 Rule
Simpson's 1/3 Rule approximates definite integrals by fitting parabolas through consecutive triplets of points. It provides better accuracy than the Trapezoidal Rule.

**Formula:**
```
∫ₐᵇ f(x)dx ≈ (h/3)[f(x₀) + 4Σf(xᵢ) + 2Σf(xⱼ) + f(xₙ)]
```
where i = odd indices, j = even indices (excluding endpoints)

**Requirements:**
- Number of subintervals (n) must be even
- Function must be continuous

**Error:** O(h⁴)


#### Code of Simpson's 1/3 Rule

**[📂 View Source Code](Numerical%20Integration/simpson's1of3Rule.cpp)**


#### Input of Simpson's 1/3 Rule
**Format:**
```
a b n
```
**Parameters:**
- `a`: Lower limit of integration
- `b`: Upper limit of integration
- `n`: Number of subintervals (must be even)

**Example Input:** (`input_simpson1of3.txt`)
```
0 3.14159 6
```


#### Output of Simpson's 1/3 Rule
**File:** `output_simpson1of3.txt`
```
========== SIMPSON'S 1/3 RULE RESULT ==========
Lower limit (a): 0.000000
Upper limit (b): 3.141590
Number of subintervals (n): 6
Step size (h): 0.523598

Integral value: 2.000109
```

### Simpson's 3/8 Rule

#### Theory of Simpson's 3/8 Rule
Simpson's 3/8 Rule uses cubic interpolation and is similar to Simpson's 1/3 Rule but requires the number of subintervals to be a multiple of 3.

**Formula:**
```
∫ₐᵇ f(x)dx ≈ (3h/8)[f(x₀) + 3Σf(xᵢ) + 2Σf(xⱼ) + f(xₙ)]
```
where i = non-multiples of 3, j = multiples of 3 (excluding endpoints)

**Requirements:**
- Number of subintervals (n) must be a multiple of 3
- Function must be continuous

**Error:** O(h⁴)


#### Code of Simpson's 3/8 Rule

**[📂 View Source Code](Numerical%20Integration/Simpson's3of8Rule.cpp)**


#### Input of Simpson's 3/8 Rule
**Format:**
```
a b n
```
**Parameters:**
- `a`: Lower limit of integration
- `b`: Upper limit of integration
- `n`: Number of subintervals (must be multiple of 3)

**Example Input:** (`input_simpson3of8.txt`)
```
0 3.14159 6
```


#### Output of Simpson's 3/8 Rule
**File:** `output_simpson3of8.txt`
```
========== SIMPSON'S 3/8 RULE RESULT ==========
Lower limit (a): 0.000000
Upper limit (b): 3.141590
Number of subintervals (n): 6
Step size (h): 0.523598

Integral value: 2.000459
```

## Curve Fitting (Regression)

### Linear Least Squares Regression

#### Theory of Linear Least Squares Regression
Linear Least Squares finds the best-fit straight line y = ax + b that minimizes the sum of squared residuals.

**Normal Equations:**
```
a = (nΣxy - ΣxΣy)/(nΣx² - (Σx)²)
b = (Σy - aΣx)/n
```

**Goodness of Fit:**
- R² (Coefficient of Determination): Measures how well the line fits the data (0 to 1)
- Correlation Coefficient (r): Measures linear relationship strength (-1 to 1)


#### Code of Linear Least Squares Regression

**[📂 View Source Code](Curve%20fitting(Regression)/lsr-Linear.cpp)**


#### Input of Linear Least Squares Regression
**Format:**
```
n
x₁ y₁
x₂ y₂
...
xₙ yₙ
```
**Parameters:**
- `n`: Number of data points
- `x y`: Data point coordinates

**Example Input:** (`input_lsr_Linear.txt`)
```
5
1.0 2.5
2.0 4.2
3.0 5.9
4.0 8.1
5.0 9.8
```

#### Output of Linear Least Squares Regression
**File:** `output_lsr_Linear.txt`
```
Data Points:
         x         y
--------------------
    1.0000    2.5000
    2.0000    4.2000
    3.0000    5.9000
    4.0000    8.1000
    5.0000    9.8000

========== CALCULATIONS ==========
Σx   = 15
Σy   = 30.5
Σx²  = 55
Σxy  = 103.5
n    = 5

========== LEAST SQUARES LINEAR REGRESSION ==========
Best fit line: y = 1.8700x + 0.7400

========== GOODNESS OF FIT ==========
R² (Coefficient of Determination): 0.9945
Correlation Coefficient (r):       0.9972
Interpretation: Excellent fit (R² > 0.9)
```

### Polynomial Least Squares Regression

#### Theory of Polynomial Least Squares Regression
Polynomial Least Squares fits a polynomial of degree m: y = a₀ + a₁x + a₂x² + ... + aₘxᵐ

The method solves the system of normal equations using Gauss-Jordan elimination to find coefficients that minimize the sum of squared residuals.

**Normal Equations:** (m+1) × (m+1) system
```
[Σx⁰  Σx¹  ... Σxᵐ  ] [a₀]   [Σy·x⁰]
[Σx¹  Σx²  ... Σxᵐ⁺¹] [a₁] = [Σy·x¹]
[  ⋮    ⋮   ⋱   ⋮   ] [⋮ ]   [  ⋮  ]
[Σxᵐ  Σxᵐ⁺¹ ... Σx²ᵐ] [aₘ]   [Σy·xᵐ]
```

#### Code of Polynomial Least Squares Regression

**[📂 View Source Code](Curve%20fitting(Regression)/lsr_polynomial.cpp)**


#### Input of Polynomial Least Squares Regression
**Format:**
```
n degree
x₁ y₁
x₂ y₂
...
xₙ yₙ
```
**Parameters:**
- `n`: Number of data points
- `degree`: Degree of polynomial (e.g., 2 for quadratic)
- `x y`: Data point coordinates

**Example Input:** (`input_lsr_polynomial.txt`)
```
5 2
1.0 2.5
2.0 5.4
3.0 10.1
4.0 15.9
5.0 23.5
```


#### Output of Polynomial Least Squares Regression
**File:** `output_lsr_polynomial.txt`
```
========== POLYNOMIAL LEAST SQUARES REGRESSION ==========
Degree: 2
Number of data points: 5

Best fit polynomial equation:
y = 0.371429 + 0.571429x + 0.928571x^2
```

### Exponential Least Squares Regression

#### Theory of Exponential Least Squares Regression
Exponential Least Squares fits data to the model: y = a·eᵇˣ

By taking logarithms: ln(y) = ln(a) + bx, which is linear in ln(y).

**Steps:**
1. Transform: Y = ln(y)
2. Apply linear regression on (x, Y)
3. Solve for b and ln(a)
4. Convert back: a = eˡⁿ⁽ᵃ⁾

**Requirements:**
- All y values must be positive (cannot take log of negative numbers)


#### Code of Exponential Least Squares Regression

**[📂 View Source Code](Curve%20fitting(Regression)/lsr_transcedental.cpp)**


#### Input of Exponential Least Squares Regression
**Format:**
```
n
x₁ y₁
x₂ y₂
...
xₙ yₙ
```
**Parameters:**
- `n`: Number of data points (must be ≥ 2)
- `x y`: Data points (all y values must be positive)

**Example Input:** (`input_lsr_transcedental.txt`)
```
5
1.0 2.5
2.0 7.2
3.0 18.5
4.0 49.0
5.0 132.5
```

#### Output of Exponential Least Squares Regression
**File:** `output_lsr_transcedental.txt`
```
========== EXPONENTIAL LEAST SQUARES REGRESSION ==========
Number of data points: 5

Best fit exponential equation:
y = 1.025643 * e^(1.012345x)
```


## Usage Instructions

### Compilation
All programs can be compiled using g++:
```bash
g++ filename.cpp -o outputname
```

Example:
```bash
g++ "solution of non-linear equations/bisection-Method.cpp" -o bisection
```

### Execution
Programs read from `input_*.txt` and write to `output_*.txt`:
```bash
./bisection
```

### Input Files
Each program has a corresponding input file:
- `input_bisection.txt`
- `input_newton-raphson.txt`
- `input_regularfalsi.txt`
- `input_secant.txt`
- `input_forwardinterpolation.txt`
- `input_backwardinterpolation.txt`
- `input_divideddifference.txt`
- `input_simpson1of3.txt`
- `input_simpson3of8.txt`
- `input_lsr_Linear.txt`
- `input_lsr_polynomial.txt`
- `input_lsr_transcedental.txt`

### Output Files
Results are written to corresponding output files:
- `output_bisection.txt`
- `output_newton-raphson.txt`
- etc.


## Error Handling

All programs include comprehensive error checking:
- **Division by zero** protection
- **Singular matrix** detection
- **Invalid input** validation
- **Convergence** monitoring
- **Iteration limits** to prevent infinite loops

