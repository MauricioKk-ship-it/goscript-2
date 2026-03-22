struct Counter {
    value: int
}

impl Counter {
    fn new() Counter {
        ret new Counter{value: 0}
    }
    
    fn inc(self) Counter {
        ret new Counter{value: self.value + 1}
    }
    
    fn dec(self) Counter {
        ret new Counter{value: self.value - 1}
    }
    
    fn get(self) int {
        ret self.value
    }
}

fn main() {
    println("=== COUNTER ===\n")
    
    lt c = Counter::new()
    println("Initial: " + c.get())
    
    c = c.inc()
    println("After inc: " + c.get())
    
    c = c.inc()
    println("After inc: " + c.get())
    
    c = c.dec()
    println("After dec: " + c.get())
    
    ret 0
}
