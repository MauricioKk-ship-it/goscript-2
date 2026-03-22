import sys from .sys

fn main() {
    println("=== SYS MODULE TEST ===\n")
    
    // 1. Informations système
    println("1. Système:")
    println("   Version: " + sys::VERSION)
    println("   OS: " + sys::OS)
    println("   ARCH: " + sys::ARCH)
    println("   PID: " + sys::getpid())
    println("")
    
    // 2. Variables d'environnement
    println("2. Environnement:")
    lt path = sys::env::get("PATH")
    println("   PATH: " + path)
    println("")
    
    // 3. Entrées/Sorties
    println("3. I/O:")
    sys::stdio::print("   Entrez votre nom: ")
    lt name = sys::stdio::input("")
    println("   Bonjour, " + name + "!")
    println("")
    
    // 4. Système de fichiers
    println("4. Fichiers:")
    sys::fs::write_file("/tmp/test.txt", "Hello Goscript!")
    lt content = sys::fs::read_file("/tmp/test.txt")
    println("   Contenu: " + content)
    sys::fs::remove("/tmp/test.txt")
    println("")
    
    // 5. Temps
    println("5. Temps:")
    lt t = sys::time::now()
    println("   Timestamp: " + t.sec)
    println("   Microsecondes: " + t.usec)
    println("")
    
    // 6. Processus
    println("6. Processus:")
    lt result = sys::process::system("echo 'Commande système exécutée!'")
    println("   Code de retour: " + result)
    println("")
    
    println("=== TEST TERMINÉ ===")
    ret 0
}
