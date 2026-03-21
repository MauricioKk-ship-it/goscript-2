enm Color {
    Red,
    Green,
    Blue
}

fn main() {
    println("=== ENUM ===\n")
    
    lt c = Color::Red
    
    if c == Color::Red {
        println("C'est rouge!")
    } else if c == Color::Green {
        println("C'est vert!")
    } else {
        println("C'est bleu!")
    }
    
    ret 0
}
