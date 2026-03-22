// Import simple comme en V
import sys

// Import avec alias
import math as m

// Import avec contraintes (style V)
import io { only: [read, write] }

// Import depuis un dossier (comme en V)
import http 
fn main() {
    // Utilisation
    println("OS: " + sys::OS)
    println("PI: " + m::PI)
    
    // Seulement read et write sont disponibles
    let content = io::read("file.txt")
    io::write("output.txt", content)
    
    // Ceci échouerait (io::append n'est pas dans "only")
    // io::append("file.txt", "data")
    
    ret 0
}

