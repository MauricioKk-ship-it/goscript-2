fn main() {
    println("Version: " + VERSION)
    println("PI: " + PI)
    
    assert(5 > 3, "5 is greater than 3")
    info("This is an info message")
    warn("This is a warning")
    
    muts x = -10
    println("abs(-10) = " + abs(x))
    println("max(5, 10) = " + max(5, 10))
    println("min(5, 10) = " + min(5, 10))
    println("clamp(15, 0, 10) = " + clamp(15, 0, 10))
    
    ret 0
}
