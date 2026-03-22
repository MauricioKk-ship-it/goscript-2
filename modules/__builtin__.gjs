// ============================================
// Goscript Built-in Module v0.3.0
// Standard Library avec FFI/C
// ============================================

// ========== VERSION ET CONSTANTES ==========
pub cn VERSION = "0.3.0"
pub cn AUTHOR = "Gopu.inc Team"
pub cn PI = 3.141592653589793
pub cn E = 2.718281828459045

// ========== CONSTANTES SYSTÈME ==========
// File flags
pub cn O_RDONLY = 0
pub cn O_WRONLY = 1
pub cn O_RDWR = 2
pub cn O_CREAT = 64
pub cn O_APPEND = 1024
pub cn O_TRUNC = 512

// Seek modes
pub cn SEEK_SET = 0
pub cn SEEK_CUR = 1
pub cn SEEK_END = 2

// Signal numbers
pub cn SIGINT = 2
pub cn SIGKILL = 9
pub cn SIGTERM = 15

// ========== STRUCTURES ==========
pub struct File {
    fd: int
    path: string
    mode: string
    buffer: string
}

pub struct Stat {
    dev: int
    ino: int
    mode: int
    nlink: int
    uid: int
    gid: int
    size: int
    atime: int
    mtime: int
    ctime: int
}

pub struct Time {
    seconds: int
    nanoseconds: int
}

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

// ========== STRING UTILITIES ==========
pub fn strlen(s: string): int {
    ret strlen_c(s)
}

pub fn strcmp(s1: string, s2: string): int {
    ret strcmp_c(s1, s2)
}

pub fn strncmp(s1: string, s2: string, n: int): int {
    ret strncmp_c(s1, s2, n)
}

pub fn strchr(s: string, c: int): string {
    ret strchr_c(s, c)
}

pub fn strstr(haystack: string, needle: string): string {
    ret strstr_c(haystack, needle)
}

pub fn strtok(s: string, delim: string): string {
    ret strtok_c(s, delim)
}

pub fn strdup(s: string): string {
    ret strdup_c(s)
}

// ========== MATH UTILITIES ==========
pub fn abs(x: int): int {
    if x < 0 { ret -x }
    ret x
}

pub fn fabs(x: double): double {
    ret fabs_c(x)
}

pub fn max(a, b) {
    if a > b { ret a }
    ret b
}

pub fn min(a, b) {
    if a < b { ret a }
    ret b
}

pub fn clamp(x, low, high) {
    if x < low { ret low }
    if x > high { ret high }
    ret x
}

pub fn sin(x: double): double {
    ret sin_c(x)
}

pub fn cos(x: double): double {
    ret cos_c(x)
}

pub fn tan(x: double): double {
    ret tan_c(x)
}

pub fn sqrt(x: double): double {
    ret sqrt_c(x)
}

pub fn pow(base: double, exp: double): double {
    ret pow_c(base, exp)
}

pub fn exp(x: double): double {
    ret exp_c(x)
}

pub fn log(x: double): double {
    ret log_c(x)
}

pub fn log10(x: double): double {
    ret log10_c(x)
}

pub fn ceil(x: double): double {
    ret ceil_c(x)
}

pub fn floor(x: double): double {
    ret floor_c(x)
}

// ========== NUMBER CONVERSION ==========
pub fn atoi(s: string): int {
    ret atoi_c(s)
}

pub fn atof(s: string): double {
    ret atof_c(s)
}

pub fn strtol(s: string, base: int): int {
    ret strtol_c(s, 0, base)
}

// ========== CHARACTER CLASSIFICATION ==========
pub fn isalpha(c: int): bool {
    ret isalpha_c(c) != 0
}

pub fn isdigit(c: int): bool {
    ret isdigit_c(c) != 0
}

pub fn isalnum(c: int): bool {
    ret isalnum_c(c) != 0
}

pub fn isspace(c: int): bool {
    ret isspace_c(c) != 0
}

pub fn isupper(c: int): bool {
    ret isupper_c(c) != 0
}

pub fn islower(c: int): bool {
    ret islower_c(c) != 0
}

pub fn toupper(c: int): int {
    ret toupper_c(c)
}

pub fn tolower(c: int): int {
    ret tolower_c(c)
}

// ========== FILE I/O ==========
pub fn fopen(path: string, mode: string): File {
    ret new File{
        fd: fopen_c(path, mode),
        path: path,
        mode: mode,
        buffer: ""
    }
}

pub fn fclose(file: File): int {
    ret fclose_c(file.fd)
}

pub fn fread(file: File, size: int, count: int): string {
    ret fread_c(file.fd, size, count)
}

pub fn fwrite(file: File, data: string): int {
    ret fwrite_c(data, 1, len(data), file.fd)
}

pub fn fgetc(file: File): int {
    ret fgetc_c(file.fd)
}

pub fn fputc(file: File, c: int): int {
    ret fputc_c(c, file.fd)
}

pub fn fgets(file: File, size: int): string {
    muts buffer = malloc(size)
    ret fgets_c(buffer, size, file.fd)
}

pub fn fputs(file: File, s: string): int {
    ret fputs_c(s, file.fd)
}

pub fn fseek(file: File, offset: int, whence: int): int {
    ret fseek_c(file.fd, offset, whence)
}

pub fn ftell(file: File): int {
    ret ftell_c(file.fd)
}

pub fn rewind(file: File) {
    rewind_c(file.fd)
}

// ========== LOW-LEVEL FILE OPERATIONS ==========
pub fn open(path: string, flags: int, mode: int): int {
    ret open_c(path, flags, mode)
}

pub fn close(fd: int): int {
    ret close_c(fd)
}

pub fn read(fd: int, size: int): string {
    muts buffer = malloc(size)
    ret read_c(fd, buffer, size)
}

pub fn write(fd: int, data: string): int {
    ret write_c(fd, data, len(data))
}

pub fn unlink(path: string): int {
    ret unlink_c(path)
}

// ========== DIRECTORY OPERATIONS ==========
pub fn mkdir(path: string, mode: int): int {
    ret mkdir_c(path, mode)
}

pub fn rmdir(path: string): int {
    ret rmdir_c(path)
}

pub fn chdir(path: string): int {
    ret chdir_c(path)
}

pub fn getcwd(): string {
    muts buffer = malloc(1024)
    ret getcwd_c(buffer, 1024)
}

// ========== FILE INFORMATION ==========
pub fn stat(path: string): Stat {
    muts buf = malloc(128)
    stat_c(path, buf)
    ret new Stat{
        size: buf[0]
    }
}

// ========== SYSTEM UTILITIES ==========
pub fn system(cmd: string): int {
    ret system_c(cmd)
}

pub fn getpid(): int {
    ret getpid_c()
}

pub fn getppid(): int {
    ret getppid_c()
}

pub fn getuid(): int {
    ret getuid_c()
}

pub fn getgid(): int {
    ret getgid_c()
}

pub fn sleep(seconds: int) {
    sleep_c(seconds)
}

pub fn msleep(milliseconds: int) {
    usleep_c(milliseconds * 1000)
}

pub fn usleep(microseconds: int) {
    usleep_c(microseconds)
}

pub fn exit(code: int) {
    exit_c(code)
}

// ========== PROCESS MANAGEMENT ==========
pub fn fork(): int {
    ret fork_c()
}

pub fn execv(path: string, args: []string): int {
    ret execv_c(path, args)
}

pub fn wait(): int {
    ret wait_c(0)
}

pub fn waitpid(pid: int): int {
    ret waitpid_c(pid, 0, 0)
}

// ========== ENVIRONMENT ==========
pub fn getenv(name: string): string {
    ret getenv_c(name)
}

pub fn setenv(name: string, value: string, overwrite: int): int {
    ret setenv_c(name, value, overwrite)
}

pub fn unsetenv(name: string): int {
    ret unsetenv_c(name)
}

// ========== MEMORY MANAGEMENT ==========
pub fn malloc(size: int): int {
    ret malloc_c(size)
}

pub fn free(ptr: int) {
    free_c(ptr)
}

pub fn calloc(count: int, size: int): int {
    ret calloc_c(count, size)
}

pub fn realloc(ptr: int, size: int): int {
    ret realloc_c(ptr, size)
}

// ========== RANDOM NUMBERS ==========
pub fn rand(): int {
    ret rand_c()
}

pub fn srand(seed: int) {
    srand_c(seed)
}

pub fn random_range(min: int, max: int): int {
    ret min + rand() % (max - min + 1)
}

// ========== TIME FUNCTIONS ==========
pub fn time(): int {
    ret time_c(0)
}

pub fn clock(): int {
    ret clock_c()
}

pub fn now(): string {
    muts t = time()
    ret ctime_c(t)
}

// ========== SIGNAL HANDLING ==========
pub fn signal(sig: int, handler: int): int {
    ret signal_c(sig, handler)
}

pub fn raise(sig: int): int {
    ret raise_c(sig)
}

// ========== DYNAMIC LIBRARY LOADING ==========
pub fn dlopen(path: string, flags: int): int {
    ret dlopen_c(path, flags)
}

pub fn dlsym(handle: int, symbol: string): int {
    ret dlsym_c(handle, symbol)
}

pub fn dlclose(handle: int): int {
    ret dlclose_c(handle)
}

pub fn dlerror(): string {
    ret dlerror_c()
}

// ========== ARRAY UTILITIES ==========
pub fn len(arr) {
    if type_of(arr) == "array" {
        ret arr[0]
    }
    ret -1
}

pub fn push(arr, value) {
    muts new_arr = [value]
    ret arr + new_arr
}

pub fn pop(arr) {
    ret arr[0:len(arr)-1]
}

pub fn contains(arr, value): bool {
    muts i = 0
    while i < len(arr) {
        if arr[i] == value {
            ret true
        }
        i = i + 1
    }
    ret false
}

pub fn index_of(arr, value): int {
    muts i = 0
    while i < len(arr) {
        if arr[i] == value {
            ret i
        }
        i = i + 1
    }
    ret -1
}

// ========== MAP (DICTIONARY) UTILITIES ==========
pub fn map_new() {
    ret {}
}

pub fn map_set(map, key, value) {
    map[key] = value
}

pub fn map_get(map, key) {
    ret map[key]
}

pub fn map_has(map, key): bool {
    ret key in map
}

pub fn map_keys(map) {
    muts keys = []
    for k in map {
        keys = push(keys, k)
    }
    ret keys
}

// ========== STRING FORMATTING ==========
pub fn format(fmt: string, ...args) {
    muts result = ""
    muts i = 0
    muts arg_idx = 0
    
    while i < len(fmt) {
        if fmt[i] == '{' && fmt[i+1] == '}' {
            result = result + args[arg_idx]
            arg_idx = arg_idx + 1
            i = i + 2
        } else {
            result = result + fmt[i]
            i = i + 1
        }
    }
    ret result
}

// ========== JSON UTILITIES ==========
pub fn to_json(value) {
    match type_of(value) {
        "int" => ret value
        "string" => ret "\"" + value + "\""
        "bool" => ret value ? "true" : "false"
        "array" => {
            muts result = "["
            muts i = 0
            while i < len(value) {
                result = result + to_json(value[i])
                if i < len(value) - 1 {
                    result = result + ","
                }
                i = i + 1
            }
            ret result + "]"
        }
        _ => ret "null"
    }
}

// ========== DEBUG ==========
pub cn DEBUG = false

// ========== COLOR CODES ==========
pub cn COLOR_RESET = "\033[0m"
pub cn COLOR_RED = "\033[31m"
pub cn COLOR_GREEN = "\033[32m"
pub cn COLOR_YELLOW = "\033[33m"
pub cn COLOR_BLUE = "\033[34m"
pub cn COLOR_MAGENTA = "\033[35m"
pub cn COLOR_CYAN = "\033[36m"

pub fn colorize(text: string, color: string): string {
    ret color + text + COLOR_RESET
}

// ========== INITIALIZATION ==========
// Initialiser le générateur aléatoire avec l'horloge
srand(clock())
info("Goscript v" + VERSION + " initialized")
