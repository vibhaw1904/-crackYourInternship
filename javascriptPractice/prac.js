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