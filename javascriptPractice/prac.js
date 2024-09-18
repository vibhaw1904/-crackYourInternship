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

//Consistency

// Consistency ensures that a transaction brings the database from one valid state to another valid state, maintaining all predefined rules and constraints.

import React, { useState, useEffect } from 'react';

function UserProfile({ userId }) {
  const [user, setUser] = useState(null);

  useEffect(() => {
    async function fetchUser() {
      try {
        const response = await fetch(`/api/users/${userId}`);
        const userData = await response.json();
        
        // Ensure data consistency
        if (userData.age < 0 || userData.age > 120) {
          throw new Error('Invalid age');
        }
        
        setUser(userData);
      } catch (error) {
        console.error('Failed to fetch user:', error);
      }
    }
    
    fetchUser();
  }, [userId]);

  // Render user profile...
}

//Isolation

// Isolation ensures that concurrent execution of transactions leaves the database in the same state that would have been obtained if the transactions were executed sequentially.


//Imagine a bank with multiple tellers serving customers. Each teller's interaction with a customer is like a transaction. Isolation ensures that even though multiple tellers are working simultaneously, each customer's transaction is handled as if they were the only one in the bank.
// Here are some examples to illustrate isolation:

// ATM Withdrawals

// Scenario: Two people are withdrawing money from the same account at different ATMs simultaneously.
// Without Isolation:

// Account balance: $1000
// Person A withdraws $700
// Person B withdraws $500
// Final balance: -$200 (overdraft)

// With Isolation:

// Account balance: $1000
// Person A's transaction starts, sees $1000 balance
// Person B's transaction starts, also sees $1000 balance
// Person A withdraws $700, balance becomes $300
// Person B's withdrawal of $500 is rejected due to insufficient funds
// Final balance: $300
let accountBalance = 1000;

async function withdraw(amount) {
  // Start transaction
  const initialBalance = accountBalance;
  
  // Simulate processing time
  await new Promise(resolve => setTimeout(resolve, 100));
  
  if (initialBalance >= amount) {
    accountBalance -= amount;
    console.log(`Withdrawn ${amount}. New balance: ${accountBalance}`);
    return true;
  } else {
    console.log(`Insufficient funds. Balance: ${accountBalance}`);
    return false;
  }
}

// Simulate concurrent withdrawals
async function simulateConcurrentWithdrawals() {
  const results = await Promise.all([
    withdraw(700),
    withdraw(500)
  ]);
  
  console.log(`Withdrawal results: ${results}`);
  console.log(`Final balance: ${accountBalance}`);
}

simulateConcurrentWithdrawals();