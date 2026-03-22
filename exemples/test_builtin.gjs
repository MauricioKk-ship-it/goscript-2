fn main() {
    println("=== Testing Built-in Module ===\n")
    
    println("VERSION: " + VERSION)
    println("PI: " + PI)
    println("")
    
    println("abs(-10) = " + abs(-10))
    println("max(5, 10) = " + max(5, 10))
    println("min(5, 10) = " + min(5, 10))
    println("clamp(15, 0, 10) = " + clamp(15, 0, 10))
    println("")
    
    assert(5 > 3, "5 is greater than 3")
    println("Assertion passed!")
    
    ret 0
}
