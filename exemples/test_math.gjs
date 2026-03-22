import math from ./math

fn main() {
    println("=== TEST MATH MODULE ===\n")
    
    println("PI = " + math::PI)
    println("E = " + math::E)
    println("")
    
    lt a = 10
    lt b = 5
    
    println("add(" + a + ", " + b + ") = " + math::add(a, b))
    println("multiply(" + a + ", " + b + ") = " + math::multiply(a, b))
    println("subtract(" + a + ", " + b + ") = " + math::subtract(a, b))
    println("divide(" + a + ", " + b + ") = " + math::divide(a, b))
    println("square(" + a + ") = " + math::square(a))
    
    println("\n=== TEST RÉUSSI ===")
    ret 0
}
