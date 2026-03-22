struct BankAccount {
    owner: string,
    balance: int
}

impl BankAccount {
    fn new(owner: string, initial: int) BankAccount {
        ret new BankAccount{
            owner: owner,
            balance: initial
        }
    }
    
    fn deposit(self, amount: int) BankAccount {
        ret new BankAccount{
            owner: self.owner,
            balance: self.balance + amount
        }
    }
    
    fn withdraw(self, amount: int) BankAccount {
        if amount <= self.balance {
            ret new BankAccount{
                owner: self.owner,
                balance: self.balance - amount
            }
        } else {
            println("Insufficient funds!")
            ret self
        }
    }
    
    fn display(self) {
        println(self.owner + "'s balance: $" + self.balance)
    }
}

fn main() {
    println("=== BANK ACCOUNT ===\n")
    
    lt account = BankAccount::new("Alice", 1000)
    account.display()
    
    account = account.deposit(500)
    account.display()
    
    account = account.withdraw(200)
    account.display()
    
    account = account.withdraw(2000)
    account.display()
    
    ret 0
}
