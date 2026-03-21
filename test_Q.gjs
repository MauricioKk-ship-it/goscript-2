fn main() {
    println("=== TEST DES FONCTIONS C ===\n")
    
    // Appels directs aux fonctions C
    lt sum = c_add(10, 20)
    println("10 + 20 = " + sum)
    
    lt product = c_mul(5, 6)
    println("5 * 6 = " + product)
    
    lt power = c_pow(2.0, 5.0)
    println("2^5 = " + power)
    
    lt max_val = c_max(42, 17)
    println("max(42, 17) = " + max_val)
    
    // Manipulation de chaînes
    lt hello = "Hello"
    lt world = " World"
    lt message = c_strcat(hello, world)
    println(message)
    
    lt len = c_strlen(message)
    println("Longueur: " + len)
    
    // System call
    c_system("echo 'Commande système exécutée!'")
    
    println("\n=== TEST TERMINÉ ===")
    ret 0
}
