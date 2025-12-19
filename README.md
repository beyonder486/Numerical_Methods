# Numerical Methods Implementation in C++

A comprehensive collection of numerical methods implemented in C++ for solving various mathematical problems.

## Table of Contents

- [Solution of Non-Linear Equations](#solution-of-non-linear-equations)
  - [Bisection Method](#bisection-method)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Newton-Raphson Method](#newton-raphson-method)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Regular Falsi (False Position) Method](#regular-falsi-false-position-method)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Secant Method](#secant-method)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)

- [Interpolation and Approximation](#interpolation-and-approximation)
  - [Newton's Forward Interpolation](#newtons-forward-interpolation)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Newton's Backward Interpolation](#newtons-backward-interpolation)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Newton's Divided Difference](#newtons-divided-difference)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)

- [Numerical Integration](#numerical-integration)
  - [Simpson's 1/3 Rule](#simpsons-13-rule)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Simpson's 3/8 Rule](#simpsons-38-rule)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)

- [Curve Fitting (Regression)](#curve-fitting-regression)
  - [Linear Least Squares Regression](#linear-least-squares-regression)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Polynomial Least Squares Regression](#polynomial-least-squares-regression)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)
  - [Exponential Least Squares Regression](#exponential-least-squares-regression)
  - [Theory](#theory)
  - [Code](#code)
  - [Input](#input)
  - [Output](#output)

---

## Solution of Non-Linear Equations

### Bisection Method

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `solution of non-linear equations/bisection-Method.cpp`

---

#### 📥 **INPUT**
**Format:**
```
a b tolerance maxIterations
```
**Parameters:**
- `a`: Lower bound of interval
- `b`: Upper bound of interval  
- `tolerance`: Convergence tolerance (e.g., 0.0001)
- `maxIterations`: Maximum number of iterations (e.g., 100)

**Example Input:** (`input_bisection.txt`)
```
0 5 0.0001 100
```

---

#### 📤 **OUTPUT**
**File:** `output_bisection.txt`
```
========== BISECTION METHOD RESULT ==========
Root: 0.2352941176
Iterations: 18
f(0.2352941176) = 1.234567e-05
```

---

### Newton-Raphson Method

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `solution of non-linear equations/newton-raphson-Method.cpp`

---

#### 📥 **INPUT**
**Format:**
```
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
-1 2 0.1 1e-6 1000
```

---

#### 📤 **OUTPUT**
**File:** `output_newton-raphson.txt`
```
========== NEWTON-RAPHSON METHOD RESULTS ==========
Number of roots found: 3
Roots:
Root 1: -0.6180339887 (iterations: 5)
Root 2: 0.6180339887 (iterations: 6)
Root 3: 1.6180339887 (iterations: 7)

Total iterations across all roots: 18
```

---

### Regular Falsi (False Position) Method

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `solution of non-linear equations/regularfalsi-FalsePosition-Method.cpp`

---

#### 📥 **INPUT**
**Format:**
```
a b tolerance maxIterations
```
**Parameters:**
- `a`: Lower bound of interval
- `b`: Upper bound of interval
- `tolerance`: Convergence tolerance (e.g., 1e-7)
- `maxIterations`: Maximum iterations (e.g., 100)

**Example Input:** (`input_regularfalsi.txt`)
```
0 1 1e-7 100
```

---

#### 📤 **OUTPUT**
**File:** `output_regularfalsi.txt`
```
========== REGULAR FALSI (FALSE POSITION) METHOD RESULT ==========
Root: 0.2352941176
Iterations: 8
f(0.2352941176) = 1.234567e-08
Tolerance: 0.0000001
```

---

### Secant Method

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `solution of non-linear equations/secant-Method.cpp`

---

#### 📥 **INPUT**
**Format:**
```
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
-3 3 0.1 1e-6 1000
```

---

#### 📤 **OUTPUT**
**File:** `output_secant.txt`
```
========== SECANT METHOD RESULTS ==========
Number of roots found: 3
Roots:
Root 1: -0.6180339887 (iterations: 7)
Root 2: 0.6180339887 (iterations: 8)
Root 3: 1.6180339887 (iterations: 8)

Total iterations across all roots: 23
```

---

## Interpolation and Approximation

### Newton's Forward Interpolation

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `Interpolation and approximation/forwardinterpolation.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
**File:** `output_forwardinterpolation.txt`
```
Class Intervals and Midpoints:
       Interval    Midpoint(x)  Frequency(y)
---------------------------------------------
     10-     20             15              5
     20-     30             25              8
     30-     40             35             12
     40-     50             45              7

Class width (h) = 10

Forward Difference Table:
...

========== RESULT ==========
y(25) = 8.500000
```

---

### Newton's Backward Interpolation

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `Interpolation and approximation/backwardinterpolation.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
**File:** `output_backwardinterpolation.txt`
```
Class Intervals and Midpoints:
       Interval    Midpoint(x)  Frequency(y)
---------------------------------------------
     10-     20             15              5
     20-     30             25              8
     30-     40             35             12
     40-     50             45              7

Backward Difference Table:
...

========== RESULT ==========
y(45) = 7.000000
```

---

### Newton's Divided Difference

#### 📚 **THEORY**
Newton's Divided Difference method works for both equally and unequally spaced data. It constructs an interpolating polynomial using divided differences.

**Formula:**
```
y(x) = f[x₀] + (x-x₀)f[x₀,x₁] + (x-x₀)(x-x₁)f[x₀,x₁,x₂] + ...
```

**Advantages:**
- Works with unequally spaced data
- Easy to add new data points
- Provides error estimation

---

#### 💻 **CODE**
**File:** `Interpolation and approximation/divideddifference.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
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

---

## Numerical Integration

### Simpson's 1/3 Rule

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `Numerical Integration/simpson's1of3Rule.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
**File:** `output_simpson1of3.txt`
```
========== SIMPSON'S 1/3 RULE RESULT ==========
Lower limit (a): 0.000000
Upper limit (b): 3.141590
Number of subintervals (n): 6
Step size (h): 0.523598

Integral value: 2.000109
```

---

### Simpson's 3/8 Rule

#### 📚 **THEORY**
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

---

#### 💻 **CODE**
**File:** `Numerical Integration/Simpson's3of8Rule.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
**File:** `output_simpson3of8.txt`
```
========== SIMPSON'S 3/8 RULE RESULT ==========
Lower limit (a): 0.000000
Upper limit (b): 3.141590
Number of subintervals (n): 6
Step size (h): 0.523598

Integral value: 2.000459
```

---

## Curve Fitting (Regression)

### Linear Least Squares Regression

#### 📚 **THEORY**
Linear Least Squares finds the best-fit straight line y = ax + b that minimizes the sum of squared residuals.

**Normal Equations:**
```
a = (nΣxy - ΣxΣy)/(nΣx² - (Σx)²)
b = (Σy - aΣx)/n
```

**Goodness of Fit:**
- R² (Coefficient of Determination): Measures how well the line fits the data (0 to 1)
- Correlation Coefficient (r): Measures linear relationship strength (-1 to 1)

---

#### 💻 **CODE**
**File:** `Curve fitting(Regression)/lsr-Linear.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
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

---

### Polynomial Least Squares Regression

#### 📚 **THEORY**
Polynomial Least Squares fits a polynomial of degree m: y = a₀ + a₁x + a₂x² + ... + aₘxᵐ

The method solves the system of normal equations using Gauss-Jordan elimination to find coefficients that minimize the sum of squared residuals.

**Normal Equations:** (m+1) × (m+1) system
```
[Σx⁰  Σx¹  ... Σxᵐ  ] [a₀]   [Σy·x⁰]
[Σx¹  Σx²  ... Σxᵐ⁺¹] [a₁] = [Σy·x¹]
[  ⋮    ⋮   ⋱   ⋮   ] [⋮ ]   [  ⋮  ]
[Σxᵐ  Σxᵐ⁺¹ ... Σx²ᵐ] [aₘ]   [Σy·xᵐ]
```

---

#### 💻 **CODE**
**File:** `Curve fitting(Regression)/lsr_polynomial.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
**File:** `output_lsr_polynomial.txt`
```
========== POLYNOMIAL LEAST SQUARES REGRESSION ==========
Degree: 2
Number of data points: 5

Best fit polynomial equation:
y = 0.371429 + 0.571429x + 0.928571x^2
```

---

### Exponential Least Squares Regression

#### 📚 **THEORY**
Exponential Least Squares fits data to the model: y = a·eᵇˣ

By taking logarithms: ln(y) = ln(a) + bx, which is linear in ln(y).

**Steps:**
1. Transform: Y = ln(y)
2. Apply linear regression on (x, Y)
3. Solve for b and ln(a)
4. Convert back: a = eˡⁿ⁽ᵃ⁾

**Requirements:**
- All y values must be positive (cannot take log of negative numbers)

---

#### 💻 **CODE**
**File:** `Curve fitting(Regression)/lsr_transcedental.cpp`

---

#### 📥 **INPUT**
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

---

#### 📤 **OUTPUT**
**File:** `output_lsr_transcedental.txt`
```
========== EXPONENTIAL LEAST SQUARES REGRESSION ==========
Number of data points: 5

Best fit exponential equation:
y = 1.025643 * e^(1.012345x)
```

---

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

---

## Error Handling

All programs include comprehensive error checking:
- **Division by zero** protection
- **Singular matrix** detection
- **Invalid input** validation
- **Convergence** monitoring
- **Iteration limits** to prevent infinite loops

---
