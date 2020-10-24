import React, { useState } from 'react'
import { buttonStyle } from './styles/CounterStyles.bs'

// Counter component using ReactJS (for illustrative proposals)

function Counter() {
  const [count, setCount] = React.useState(0);
  const [error, setError] = React.useState("");

  const handleDecrement = () => {
    count === 0 ? 
      setError("Count cannot be negative!") : setCount(count => count - 1 )
  }

  const handleIncrement = () => {
    setCount(count => count + 1 )
  }

  const handleReset = () => {
    setCount(0)
    setError("")
  }

  return (
    <div>
      <p>Counter: {count}</p>
      <button style={buttonStyle} onClick={handleIncrement}>+</button>
      <button style={buttonStyle} onClick={handleDecrement}>-</button>
      <button style={buttonStyle} onClick={handleReset}>
        Reset
      </button>
      <span>{error}</span>
    </div>
  );
}

export default Counter;