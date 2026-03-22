fn main() {
    println("=== Goscript FFI Test ===\n")
    
    // Test des constantes
    println("Version: " + VERSION)
    println("PI: " + PI)
    println("")
    
    // Test string functions
    muts hello = "Hello"
    muts world = "World"
    println("strlen('Hello') = " + strlen(hello))
    println("strcmp('Hello', 'World') = " + strcmp(hello, world))
    println("")
    
    // Test file I/O
    muts file = fopen("test.txt", "w")
    fwrite(file, "Hello from Goscript!\n")
    fclose(file)
    println("File written successfully")
    
    muts read_file = fopen("test.txt", "r")
    muts content = fread(read_file, 1, 100)
    println("File content: " + content)
    fclose(read_file)
    println("")
    
    // Test system
    println("Current PID: " + getpid())
    println("")
    
    // Test random
    srand(clock())
    println("Random number: " + rand())
    println("")
    
    // Test environment
    muts path = getenv("PATH")
    println("PATH: " + path)
    println("")
    
    // Test sleep
    println("Sleeping for 1 second...")
    sleep(1)
    println("Done!")
    
    ret 0
}
