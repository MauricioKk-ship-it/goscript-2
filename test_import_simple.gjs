import sys from "./sys"

fn main() {
    println("=== TEST IMPORT SYS ===\n")
    println("Module chargé avec succès!")
    
    // Tester quelques fonctions basiques
    println("Version: " + sys::VERSION)
    println("OS: " + sys::OS)
    
    ret 0
}
