struct Rectangle {
    width: int,
    height: int
}

impl Rectangle {
    fn area(self): int {
        ret self.width * self.height
    }
    
    fn perimeter(self): int {
        ret (self.width + self.height) * 2
    }
    
    fn scale(self, factor: int): Rectangle {
        ret new Rectangle{
            width: self.width * factor,
            height: self.height * factor
        }
    }
}

fn main() {
    println("=== RECTANGLE METHODS ===\n")
    
    lt rect = new Rectangle{
        width: 10,
        height: 5
    }
    
    println("Width: " + rect.width)
    println("Height: " + rect.height)
    println("Area: " + rect.area())
    println("Perimeter: " + rect.perimeter())
    
    lt big = rect.scale(2)
    println("\nAfter scaling by 2:")
    println("Width: " + big.width)
    println("Height: " + big.height)
    println("Area: " + big.area())
    
    ret 0
}
