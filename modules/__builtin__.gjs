// ============================================
// Goscript Built-in Module v0.2.0
// Avec support FFI pour les fonctions système
// ============================================

// ========== VERSION ET CONSTANTES ==========
pub cn VERSION = "0.2.0"
pub cn AUTHOR = "Gopu.inc Team"
pub cn PI = 3.141592653589793
pub cn E = 2.718281828459045

// Constantes système (via FFI)
pub cn O_RDONLY = 0
pub cn O_WRONLY = 1
pub cn O_RDWR = 2
pub cn O_CREAT = 64
pub cn O_APPEND = 1024

pub cn SEEK_SET = 0
pub cn SEEK_CUR = 1
pub cn SEEK_END = 2

// ========== ASSERTIONS ==========
pub fn assert(condition: bool, message: string): bool {
    if !condition {
        println("[ASSERT] FAILED: " + message)
        ret false
    }
    ret true
}

pub fn assert_eq(a, b, message: string): bool {
    if a != b {
        println("[ASSERT] FAILED: " + message + " (" + a + " != " + b + ")")
        ret false
    }
    ret true
}

// ========== LOGGING ==========
pub fn log(level: string, msg: string) {
    println("[" + level + "] " + msg)
}

pub fn info(msg: string) {
    log("INFO", msg)
}

pub fn warn(msg: string) {
    log("WARN", msg)
}

pub fn error(msg: string) {
    log("ERROR", msg)
}

pub fn debug(msg: string) {
    if DEBUG {
        log("DEBUG", msg)
    }
}

// ========== MATH UTILITIES ==========
pub fn abs(x: int): int {
    if x < 0 {
        ret -x
    }
    ret x
}

pub fn max(a, b) {
    if a > b {
        ret a
    }
    ret b
}

pub fn min(a, b) {
    if a < b {
        ret a
    }
    ret b
}

pub fn clamp(x, low, high) {
    if x < low {
        ret low
    }
    if x > high {
        ret high
    }
    ret x
}

// ========== STRING UTILITIES (FFI) ==========
pub fn strlen(s: string): int {
    // Appelle strlen de la libc via FFI
    ret strlen_c(s)
}

pub fn strcmp(s1: string, s2: string): int {
    ret strcmp_c(s1, s2)
}

pub fn strcpy(dest: string, src: string): string {
    ret strcpy_c(dest, src)
}

pub fn strcat(dest: string, src: string): string {
    ret strcat_c(dest, src)
}

// ========== FILE I/O (FFI) ==========
pub struct File {
    fd: int
    path: string
    mode: string
}

pub fn fopen(path: string, mode: string): File {
    ret new File{
        fd: fopen_c(path, mode),
        path: path,
        mode: mode
    }
}

pub fn fclose(file: File): int {
    ret fclose_c(file.fd)
}

pub fn fread(file: File, size: int, count: int): string {
    ret fread_c(file.fd, size, count)
}

pub fn fwrite(file: File, data: string): int {
    ret fwrite_c(file.fd, data)
}

pub fn fseek(file: File, offset: int, whence: int): int {
    ret fseek_c(file.fd, offset, whence)
}

pub fn ftell(file: File): int {
    ret ftell_c(file.fd)
}

// ========== SYSTEM UTILITIES (FFI) ==========
pub fn system(cmd: string): int {
    ret system_c(cmd)
}

pub fn getpid(): int {
    ret getpid_c()
}

pub fn sleep(seconds: int) {
    sleep_c(seconds)
}

pub fn usleep(microseconds: int) {
    usleep_c(microseconds)
}

pub fn exit(code: int) {
    exit_c(code)
}

// ========== MEMORY UTILITIES (FFI) ==========
pub fn malloc(size: int): int {
    ret malloc_c(size)
}

pub fn free(ptr: int) {
    free_c(ptr)
}

// ========== ENVIRONMENT ==========
pub fn getenv(name: string): string {
    ret getenv_c(name)
}

pub fn setenv(name: string, value: string, overwrite: int): int {
    ret setenv_c(name, value, overwrite)
}

// ========== TIME UTILITIES ==========
pub fn now(): int {
    ret time_c()
}

pub fn clock(): int {
    ret clock_c()
}

// ========== RANDOM UTILITIES ==========
pub fn rand(): int {
    ret rand_c()
}

pub fn srand(seed: int) {
    srand_c(seed)
}

// ========== TYPE UTILITIES ==========
pub fn type_of(value) {
    ret type_of_c(value)
}

// ========== DEBUG FLAG ==========
pub cn DEBUG = false

// ========== HELPER FUNCTIONS ==========
pub fn print_array(arr) {
    muts result = "["
    muts i = 0
    while i < len(arr) {
        result = result + arr[i]
        if i < len(arr) - 1 {
            result = result + ", "
        }
        i = i + 1
    }
    result = result + "]"
    println(result)
}

pub fn range(start: int, end: int) {
    muts result = []
    muts i = start
    while i < end {
        result = result + i
        i = i + 1
    }
    ret result
}
