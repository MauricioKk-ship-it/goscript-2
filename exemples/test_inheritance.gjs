// Test de l'héritage avec structd

import structd

// Définition des classes avec héritage
struct Object {
    name: string
    created: int
}

impl Object {
    fn init(self: Object, name: string): Object {
        ret new Object{
            name: name,
            created: time()
        }
    }
    
    fn to_string(self: Object): string {
        ret "Object: " + self.name
    }
}

struct Person extends Object {
    age: int
    email: string
}

impl Person {
    fn init(self: Person, name: string, age: int, email: string): Person {
        ret new Person{
            name: name,
            created: time(),
            age: age,
            email: email
        }
    }
    
    fn to_string(self: Person): string {
        ret "Person: " + self.name + " (" + self.age + ")"
    }
    
    fn greet(self: Person): string {
        ret "Hello, I'm " + self.name
    }
}

struct Employee extends Person {
    salary: int
    position: string
}

impl Employee {
    fn init(self: Employee, name: string, age: int, email: string, salary: int, position: string): Employee {
        ret new Employee{
            name: name,
            created: time(),
            age: age,
            email: email,
            salary: salary,
            position: position
        }
    }
    
    fn to_string(self: Employee): string {
        ret "Employee: " + self.name + " (" + self.position + ") - $" + self.salary
    }
    
    fn work(self: Employee): string {
        ret self.name + " is working as " + self.position
    }
    
    fn promote(self: Employee, new_position: string, new_salary: int): Employee {
        ret new Employee{
            name: self.name,
            created: self.created,
            age: self.age,
            email: self.email,
            salary: new_salary,
            position: new_position
        }
    }
}

fn main() {
    println("=== TEST HÉRITAGE ===\n")
    
    // Créer un objet de base
    muts obj = new Object{name: "Base", created: time()}
    println("Object: " + obj.to_string())
    
    // Créer une personne
    muts alice = new Person{
        name: "Alice",
        created: time(),
        age: 30,
        email: "alice@example.com"
    }
    println("\nPerson:")
    println("  " + alice.to_string())
    println("  " + alice.greet())
    
    // Créer un employé
    muts bob = new Employee{
        name: "Bob",
        created: time(),
        age: 35,
        email: "bob@company.com",
        salary: 50000,
        position: "Developer"
    }
    println("\nEmployee:")
    println("  " + bob.to_string())
    println("  " + bob.work())
    
    // Promotion
    muts bob2 = bob.promote("Senior Developer", 75000)
    println("\nAfter promotion:")
    println("  " + bob2.to_string())
    
    // Test méthodes héritées
    println("\nInherited methods:")
    println("  Bob's name: " + bob2.name)
    println("  Bob's age: " + bob2.age)
    
    // Test serialization
    println("\nJSON Serialization:")
    println("  Alice: " + structd::to_json(alice))
    println("  Bob: " + structd::to_json(bob2))
    
    // Test clone
    muts alice2 = structd::clone(alice)
    alice2.age = 31
    println("\nClone test:")
    println("  Original age: " + alice.age)
    println("  Cloned age: " + alice2.age)
    
    // Test equality
    println("\nEquality test:")
    muts alice3 = structd::clone(alice)
    println("  alice == alice3: " + structd::equals(alice, alice3))
    println("  alice == bob: " + structd::equals(alice, bob))
    
    // Dump
    println("\nDump:")
    structd::dump(bob2)
    
    println("\n=== TEST TERMINÉ ===")
    
    ret 0
}
