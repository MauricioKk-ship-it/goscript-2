struct Point {
    x: int,
    y: int
}

fn main() {
    println("=== STRUCTURE ===\n")
    
    lt p = new Point{
        x: 10,
        y: 20
    }
    
    println("Point: (" + p.x + ", " + p.y + ")")
    
    ret 0
}
