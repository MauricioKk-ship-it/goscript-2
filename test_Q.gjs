// ============================================
// TEST COMPLET DU LANGAGE GOSCRIPT
// ============================================

fn main() {
    println("╔════════════════════════════════════════╗")
    println("║     GOSCRIPT COMPLETE TEST SUITE      ║")
    println("╚════════════════════════════════════════╝")
    println("")
    
    // ========== 1. VARIABLES ET TYPES ==========
    println("1. VARIABLES ET TYPES")
    println("----------------------------------------")
    
    lt integer = 42
    lt float_num = 3.14159
    lt string_text = "Hello Goscript"
    lt boolean_true = true
    lt boolean_false = false
    lt nothing = nil
    
    println("   Entier: " + integer)
    println("   Flottant: " + float_num)
    println("   Chaîne: " + string_text)
    println("   Booléen true: " + boolean_true)
    println("   Booléen false: " + boolean_false)
    println("   Nil: " + nothing)
    println("")
    
    // ========== 2. OPÉRATIONS ARITHMÉTIQUES ==========
    println("2. OPÉRATIONS ARITHMÉTIQUES")
    println("----------------------------------------")
    
    lt a = 25
    lt b = 10
    
    println("   a = " + a + ", b = " + b)
    println("   a + b = " + (a + b))
    println("   a - b = " + (a - b))
    println("   a * b = " + (a * b))
    println("   a / b = " + (a / b))
    println("   a % b = " + (a % b))
    println("")
    
    // ========== 3. OPÉRATEURS DE COMPARAISON ==========
    println("3. OPÉRATEURS DE COMPARAISON")
    println("----------------------------------------")
    
    lt x = 10
    lt y = 20
    
    println("   x = " + x + ", y = " + y)
    println("   x < y  = " + (x < y))
    println("   x > y  = " + (x > y))
    println("   x <= y = " + (x <= y))
    println("   x >= y = " + (x >= y))
    println("   x == y = " + (x == y))
    println("   x != y = " + (x != y))
    println("")
    
    // ========== 4. OPÉRATEURS LOGIQUES ==========
    println("4. OPÉRATEURS LOGIQUES")
    println("----------------------------------------")
    
    lt t = true
    lt f = false
    
    println("   t = true, f = false")
    println("   t && t = " + (t && t))
    println("   t && f = " + (t && f))
    println("   t || f = " + (t || f))
    println("   f || f = " + (f || f))
    println("   !t     = " + (!t))
    println("   !f     = " + (!f))
    println("")
    
    // ========== 5. OPÉRATEURS D'ASSIGNATION ==========
    println("5. OPÉRATEURS D'ASSIGNATION")
    println("----------------------------------------")
    
    lt z = 10
    println("   z = " + z)
    
    z += 5
    println("   z += 5  => " + z)
    
    z -= 3
    println("   z -= 3  => " + z)
    
    z *= 2
    println("   z *= 2  => " + z)
    
    z /= 4
    println("   z /= 4  => " + z)
    
    z %= 3
    println("   z %= 3  => " + z)
    println("")
    
    // ========== 6. CONDITIONS IF/ELSE ==========
    println("6. CONDITIONS IF/ELSE")
    println("----------------------------------------")
    
    lt score = 85
    
    if score >= 90 {
        println("   Grade: A (excellent)")
    }
    
    if score >= 80 && score < 90 {
        println("   Grade: B (très bien)")
    }
    
    if score >= 70 && score < 80 {
        println("   Grade: C (bien)")
    }
    
    if score >= 60 && score < 70 {
        println("   Grade: D (passable)")
    }
    
    if score < 60 {
        println("   Grade: F (échec)")
    }
    println("")
    
    // ========== 7. BOUCLE WHILE ==========
    println("7. BOUCLE WHILE")
    println("----------------------------------------")
    
    lt i = 0
    while i < 5 {
        println("   Itération while: " + i)
        i = i + 1
    }
    println("")
    
    // ========== 8. BOUCLE FOR ==========
    println("8. BOUCLE FOR")
    println("----------------------------------------")
    
    for j = 0; j < 5; j = j + 1 {
        println("   Itération for: " + j)
    }
    println("")
    
    // ========== 9. COMPTE À REBOURS ==========
    println("9. COMPTE À REBOURS")
    println("----------------------------------------")
    
    lt countdown = 5
    while countdown > 0 {
        println("   T-minus: " + countdown)
        countdown = countdown - 1
    }
    println("   LIFT OFF!")
    println("")
    
    // ========== 10. TABLE DE MULTIPLICATION ==========
    println("10. TABLE DE MULTIPLICATION (3x3)")
    println("----------------------------------------")
    
    lt row = 1
    while row <= 3 {
        print("   ")
        lt col = 1
        while col <= 3 {
            print(row * col)
            print(" ")
            col = col + 1
        }
        println("")
        row = row + 1
    }
    println("")
    
    // ========== 11. SOMME DES NOMBRES ==========
    println("11. SOMME DES NOMBRES DE 1 À 100")
    println("----------------------------------------")
    
    lt sum = 0
    lt n = 1
    while n <= 100 {
        sum = sum + n
        n = n + 1
    }
    println("   Somme = " + sum)
    println("")
    
    // ========== 12. FACTORIELLE ==========
    println("12. FACTORIELLE DE 5")
    println("----------------------------------------")
    
    lt fact = 1
    lt fnum = 1
    while fnum <= 5 {
        fact = fact * fnum
        fnum = fnum + 1
    }
    println("   5! = " + fact)
    println("")
    
    // ========== 13. NOMBRES PAIRS ==========
    println("13. NOMBRES PAIRS DE 1 À 20")
    println("----------------------------------------")
    
    lt even = 2
    print("   ")
    while even <= 20 {
        print(even)
        print(" ")
        even = even + 2
    }
    println("")
    println("")
    
    // ========== 14. FONCTIONS ==========
    println("14. FONCTIONS")
    println("----------------------------------------")
    
    lt add_result = add(15, 25)
    lt mul_result = multiply(8, 7)
    lt max_result = max(42, 17)
    lt min_result = min(42, 17)
    
    println("   add(15, 25)     = " + add_result)
    println("   multiply(8, 7)  = " + mul_result)
    println("   max(42, 17)     = " + max_result)
    println("   min(42, 17)     = " + min_result)
    println("")
    
    // ========== 15. FONCTION RÉCURSIVE ==========
    println("15. FONCTION RÉCURSIVE (FIBONACCI)")
    println("----------------------------------------")
    
    lt fib5 = fibonacci(5)
    lt fib8 = fibonacci(8)
    
    println("   fibonacci(5) = " + fib5)
    println("   fibonacci(8) = " + fib8)
    println("")
    
    // ========== 16. CONCATÉNATION DE CHAÎNES ==========
    println("16. CONCATÉNATION DE CHAÎNES")
    println("----------------------------------------")
    
    lt first = "Goscript"
    lt last = "Language"
    lt full = first + " " + last
    
    println("   " + first + " + " + last + " = " + full)
    println("")
    
    // ========== 17. EXPRESSION COMPLEXE ==========
    println("17. EXPRESSION COMPLEXE")
    println("----------------------------------------")
    
    lt complex = (a + b) * 2 - (a * 3) + (b / a) + (a % b)
    println("   (25 + 10) * 2 - (25 * 3) + (10 / 25) + (25 % 10) = " + complex)
    println("")
    
    // ========== 18. BOUCLE IMBRIQUÉE ==========
    println("18. BOUCLE IMBRIQUÉE (PYRAMIDE)")
    println("----------------------------------------")
    
    lt stars = 1
    while stars <= 5 {
        print("   ")
        lt s = 1
        while s <= stars {
            print("*")
            s = s + 1
        }
        println("")
        stars = stars + 1
    }
    println("")
    
    // ========== 19. TEST DES BOOLÉENS ==========
    println("19. TEST DES BOOLÉENS")
    println("----------------------------------------")
    
    lt is_valid = true
    lt is_ready = false
    
    if is_valid && !is_ready {
        println("   Valide mais pas prêt")
    }
    
    if !is_valid && is_ready {
        println("   Prêt mais pas valide")
    }
    
    if is_valid && is_ready {
        println("   Valide et prêt")
    }
    
    if !is_valid && !is_ready {
        println("   Ni valide ni prêt")
    }
    println("")
    
    // ========== 20. MESSAGE FINAL ==========
    println("╔════════════════════════════════════════╗")
    println("║     ALL TESTS PASSED SUCCESSFULLY     ║")
    println("╚════════════════════════════════════════╝")
    
    ret 0
}

// Fonction addition
fn add(x, y) {
    ret x + y
}

// Fonction multiplication
fn multiply(x, y) {
    ret x * y
}

// Fonction maximum
fn max(x, y) {
    if x > y {
        ret x
    }
    ret y
}

// Fonction minimum
fn min(x, y) {
    if x < y {
        ret x
    }
    ret y
}

// Fonction factorielle récursive
fn factorial(n) {
    if n <= 1 {
        ret 1
    }
    ret n * factorial(n - 1)
}

// Fonction Fibonacci récursive
fn fibonacci(n) {
    if n <= 1 {
        ret n
    }
    ret fibonacci(n - 1) + fibonacci(n - 2)
}

// Fonction puissance
fn power(base, exp) {
    lt result = 1
    lt i = 0
    while i < exp {
        result = result * base
        i = i + 1
    }
    ret result
}

// Fonction pour vérifier si un nombre est pair
fn is_even(n) {
    if n % 2 == 0 {
        ret true
    }
    ret false
}

// Fonction pour vérifier si un nombre est premier
fn is_prime(n) {
    if n < 2 {
        ret false
    }
    lt i = 2
    while i * i <= n {
        if n % i == 0 {
            ret false
        }
        i = i + 1
    }
    ret true
}
