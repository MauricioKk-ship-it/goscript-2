struct Person {
    name: string,
    age: int
}

impl Person {
    fn new(name: string, age: int) Person {
        ret new Person{
            name: name,
            age: age
        }
    }
    
    fn greet(self) {
        println("Hello, my name is " + self.name + " and I'm " + self.age + " years old.")
    }
    
    fn birthday(self) Person {
        ret new Person{
            name: self.name,
            age: self.age + 1
        }
    }
    
    fn is_adult(self) bool {
        ret self.age >= 18
    }
}

fn main() {
    println("=== PERSON ===\n")
    
    lt alice = Person::new("Alice", 25)
    alice.greet()
    println("Is adult? " + alice.is_adult())
    
    lt bob = Person::new("Bob", 16)
    bob.greet()
    println("Is adult? " + bob.is_adult())
    
    lt bob_older = bob.birthday()
    bob_older.greet()
    println("Is adult now? " + bob_older.is_adult())
    
    ret 0
}
