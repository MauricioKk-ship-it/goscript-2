// Structure de données
struct User {
    name: string
    age: int
    email: string
}

// Fonction qui retourne une structure
fn create_user(name: string, age: int, email: string): User {
    ret User{
        name: name,
        age: age,
        email: email
    }
}

// Fonction qui retourne directement un champ
fn get_user_name(user: User): string -> user.name

// Fonction qui retourne une autre fonction
fn make_greeting(greeting: string): fn(string): string {
    fn inner(name: string): string {
        ret greeting + ", " + name + "!"
    }
    ret inner
}

// Fonction qui retourne le résultat d'un appel
fn get_user_email(user: User): string -> create_user(user.name, user.age, user.email).email

fn main() {
    // Tester les structures
    muts user = create_user("Alice", 30, "alice@example.com")
    println("User name: " + get_user_name(user))
    println("User email: " + get_user_email(user))
    
    // Tester les fonctions comme valeurs
    muts hello_func = make_greeting("Hello")
    muts welcome_func = make_greeting("Welcome")
    
    println(hello_func("Bob"))
    println(welcome_func("Charlie"))
    
    // Tester l'appel direct
    muts greet = make_greeting("Hi")
    println(greet("David"))
    
    // Stocker et appeler
    muts functions = [hello_func, welcome_func, greet]
    muts i = 0
    while i < 3 {
        println(functions[i]("Friend"))
        i = i + 1
    }
    
    ret 0
}
