import greetings from "./greetings"

fn main() {
    println("=== TEST IMPORT SIMPLE ===\n")
    
    // Tester les constantes
    println("Constante: " + greetings::HELLO)
    println("Constante: " + greetings::WORLD)
    println("Constante: " + greetings::WELCOME)
    println("")
    
    // Tester les fonctions
    greetings::say_hello("Alice")
    greetings::say_goodbye("Bob")
    println("")
    
    // Tester la fonction avec retour
    lt msg = greetings::get_greeting("Charlie")
    println("Message: " + msg)
    
    println("\n=== TEST RÉUSSI ===")
    ret 0
}
