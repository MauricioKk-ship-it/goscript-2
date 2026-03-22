import utils from ./utils

fn main() {
    println("=== TEST UTILS MODULE ===\n")
    
    lt text = "Hello Goscript!"
    
    println("Original: " + text)
    println("To Upper: " + utils::to_upper(text))
    println("To Lower: " + utils::to_lower(text))
    println("Reverse: " + utils::reverse(text))
    
    println("\n=== TEST RÉUSSI ===")
    ret 0
}
