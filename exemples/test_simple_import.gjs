import simple

fn main() {
    println("=== TEST SIMPLE IMPORT ===\n")
    
    println("Message: " + simple::MSG)
    
    lt greeting = simple::greet("Alice")
    println(greeting)
    
    ret 0
}
