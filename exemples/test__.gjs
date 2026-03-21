fn main() {
    println("=== TEST SIMPLE ===\n")
    
    lt a = 10
    lt b = 20
    lt c = a + b
    lt e = true

    println("a + b = " + c)
    println(e)
    if a < b {
        println("a est plus petit que b", e)
    } else { println(" b est plus grand")
    }
    
    ret 0
}
