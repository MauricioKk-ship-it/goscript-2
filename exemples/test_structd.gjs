// Test des structures avancées avec module structd

import structd

struct Person {
    name: string
    age: int
    active: bool
    tags: []string
}

struct Address {
    street: string
    city: string
    zip: int
}

struct Employee {
    person: Person
    address: Address
    salary: int
}

fn main() {
    println("=== TEST STRUCTURES AVANCÉES ===\n")
    
    // Créer une personne
    muts alice = new Person{
        name: "Alice",
        age: 30,
        active: true,
        tags: ["developer", "gopher"]
    }
    
    // Créer une adresse
    muts addr = new Address{
        street: "123 Main St",
        city: "Paris",
        zip: 75001
    }
    
    // Créer un employé
    muts emp = new Employee{
        person: alice,
        address: addr,
        salary: 50000
    }
    
    // 1. Afficher en JSON
    println("1. JSON Serialization:")
    println(structd::to_json(emp))
    println("")
    
    // 2. Cloner la structure
    println("2. Clone:")
    muts emp2 = structd::clone(emp)
    emp2.salary = 60000
    println("Original salary: " + emp.salary)
    println("Cloned salary: " + emp2.salary)
    println("")
    
    // 3. Comparer structures
    println("3. Equality:")
    muts emp3 = structd::clone(emp)
    println("emp == emp2: " + structd::equals(emp, emp2))
    println("emp == emp3: " + structd::equals(emp, emp3))
    println("")
    
    // 4. Obtenir les champs
    println("4. Field operations:")
    println("Fields: " + structd::fields(emp))
    println("person.name: " + structd::get(emp, "person.name"))
    println("Has field 'salary': " + structd::has_field(emp, "salary"))
    println("")
    
    // 5. Convertir en map
    println("5. Convert to Map:")
    muts map = structd::to_map(emp)
    println("Map: " + structd::to_json(map))
    println("")
    
    // 6. Dump structure
    println("6. Structure Dump:")
    structd::dump(emp)
    
    println("\n=== TEST TERMINÉ ===")
    
    ret 0
}
