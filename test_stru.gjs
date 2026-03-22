fn main() {
    println("=== STRUCT TEST ===\n")
    
    struct Point {
        x: int,
        y: int
    }
    
    // Créer une structure
    lt p = new Point{
        x: 10,
        y: 20
    }
    
    // Afficher les valeurs directement
    println("Point x: " + p.x)
    println("Point y: " + p.y)
    
    ret 0
}
