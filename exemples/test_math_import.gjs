import math

fn main() {
    println("=== TEST IMPORT MATH ===\n")
    
    println("PI = " + math::PI)
    println("E = " + math::E)
    println("")
    
    lt a = 10
    lt b = 5
    println("add(10, 5) = " + math::add(a, b))
    println("multiply(10, 5) = " + math::multiply(a, b))
    
    println("\n=== TEST RÉUSSI ===")
    ret 0
}
