
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
    
    println("Point: (" + p.x + ", " + p.y + ")")
    
    ret 0
}
