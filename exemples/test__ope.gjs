fn main() {
    println("=== TESTS OPÉRATIONS ===\n")
    
    // Arithmétique
    lt a = 10
    lt b = 3
    println("a + b = " + (a + b))
    println("a - b = " + (a - b))
    println("a * b = " + (a * b))
    println("a / b = " + (a / b))
    println("a % b = " + (a % b))
    
    // Assignation composée
    lt x = 5
    x += 3
    println("x += 3 => " + x)
    x *= 2
    println("x *= 2 => " + x)
    
    ret 0
}
