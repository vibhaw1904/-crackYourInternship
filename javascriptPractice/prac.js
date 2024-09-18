//ACID PROPERTY

//1.Atomicity: Atomicity ensures that a transaction is treated as a single, indivisible unit. Either all operations within the transaction are completed successfully, or none of them are.

//eg

function TransferMoney(fromAccount,toAccount,amount){
try {
// Start transaction
beginTransaction();
fromAccount.balance -= amount;
    
// Add to another account
toAccount.balance += amount;

// Commit transaction
commitTransaction();
} catch (error) {
        // If any operation fails, roll back all changes
        rollbackTransaction();
        throw error;
}
}