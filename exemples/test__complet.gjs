struct Person {
    name: string,
    age: int
}

enm Status {
    Active,
    Inactive
}

fn main() {
    println("=== TEST COMPLET ===\n")
    
    // Variables
    lt name = "Goscript"
    lt version = 1.0
    println("Langage: " + name + " v" + version)
    
    // Structure
    lt user = new Person{
        name: "Alice",
        age: 30
    }
    println("Utilisateur: " + user.name + ", " + user.age + " ans")
    
    // Énumération
    lt status = Status::Active
    if status == Status::Active {
        println("Statut: Actif")
    }
    
    // Boucle
    lt i = 0
    while i < 3 {
        println("Compteur: " + i)
        i = i + 1
    }
    
    // Condition
    lt score = 85
    if score >= 90 {
        println("Grade: A")
    } else if score >= 80 {
        println("Grade: B")
    } else {
        println("Grade: C")
    }
    
    println("\n=== TEST TERMINÉ ===")
    ret 0
}
