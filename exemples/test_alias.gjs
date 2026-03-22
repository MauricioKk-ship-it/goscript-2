import math as m from ./math
import utils as u from ./utils

fn main() {
    println("=== TEST IMPORT AVEC ALIAS ===\n")
    
    println("PI = " + m::PI)
    println("add(10, 5) = " + m::add(10, 5))
    println("")
    
    println("to_upper('hello') = " + u::to_upper("hello"))
    println("reverse('Goscript') = " + u::reverse("Goscript"))
    
    println("\n=== TEST RÉUSSI ===")
    ret 0
}
