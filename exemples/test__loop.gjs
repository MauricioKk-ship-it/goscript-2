fn main() {
    println("=== BOUCLE WHILE ===\n")
    
    lt i = 0
    while i < 5 {
        println("i = " + i)
        i = i + 1
    }
    
    println("\n=== BOUCLE LOOP ===\n")
    lt j = 0
    loop {
        println("j = " + j)
        j = j + 1
        if j >= 3 {
            break
        }
    }
    
    ret 0
}
